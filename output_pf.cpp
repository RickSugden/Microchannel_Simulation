#include "common.h"
#include "params.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

void output_pf(int numout)
{
  char fname[72];
  FILE *pfile;
  FILE *apfile;
  int p;
  int n;
  double yw;
  

  sprintf(fname, "pf_out/d%.4f/a%.2f/ic%4.4i/pf.%6.6i", DENSITY, ASPECT_RATIO, ic, numout);
  pfile = fopen(fname, "w");
  
  sprintf(fname, "e2_out/d%.4f/a%.2f/ic%4.4i/e2.%6.6i", DENSITY, ASPECT_RATIO, ic, numout);
  apfile = fopen(fname, "w");
  
  for(p = 0; p < NUMPART; p++)
    {
      fprintf(pfile, "%12.10g %12.10g %12.10g %12.10g\n", x[p] * xscale, y[p] * xscale, r[p] * xscale, 
	      press[p] * mscale * invtscale * invtscale);
      fprintf(apfile, "%12.10g %12.10g %12.10g %12.10g\n", x[p] * xscale, y[p] * xscale, r[p] * xscale, 
	      (0.5*press[p] - rad[p]) * mscale * invtscale * invtscale); // minor eigenvalue
    }
  n = (int) (LY * INVWBSPACING + 0.5);
  for (p = 0; p < n; p++)
    {
      yw = (p-0.5)*WALLBALLSPACING + rxwall_offset;
      if (yw < 0.)
         yw += LY;
      if (yw > LY)
         yw -= LY;
      fprintf(pfile, "%12.10g %12.10g %12.10g %12.10g\n", LX * xscale, yw * xscale, WALLBALLR * xscale, -1.0);        
      fprintf(apfile, "%12.10g %12.10g %12.10g %12.10g\n", LX * xscale, yw * xscale, WALLBALLR * xscale, -1.0);        

      yw = (p-0.5)*WALLBALLSPACING + lxwall_offset;
      if (yw < 0.)
         yw += LY;
      if (yw > LY)
         yw -= LY;
      fprintf(pfile, "%12.10g %12.10g %12.10g %12.10g\n", 0., yw * xscale, WALLBALLR * xscale, -1.0);        
      fprintf(apfile, "%12.10g %12.10g %12.10g %12.10g\n", 0., yw * xscale, WALLBALLR * xscale, -1.0);        
    }      

  fclose(pfile);
  fclose(apfile);

}
