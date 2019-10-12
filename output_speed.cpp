#include "common.h"
#include "params.h"

void output_speed(int numout)
{
  char fname[72];
  FILE *spfile;
  int p;
  double speed[NUMPART];
  
  for(p = 0; p < NUMPART; p++)
     speed[p] = vx[p] * vx[p] + vy[p] * vy[p];

  sprintf(fname, "speed_out%9.9lu/sp.%6.6i", DIRNUM, numout);
  
  spfile = fopen(fname, "w");
  
  for(p = 0; p < NUMPART; p++)
    fprintf(spfile, "%12.10g %12.10g %12.10g %12.10g\n", x[p] * xscale, y[p] * xscale, r[p] * xscale, 
	    speed[p] * xscale * xscale * invtscale * invtscale);
    
  fflush(spfile);
  fclose(spfile);
}
