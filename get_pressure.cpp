
#include "common.h"

void get_pressure(int tstep)
{
  double e1total = 0.;
  double e2total = 0.;
  double total2 = 0.;
  double invr;
  int q;

  totpress = 0.;

  for(q = 0; q < NUMPART; q++)
    {
      invr = -1./(PI*r[q]);
      stressxx[q] *= invr;
      stressyy[q] *= invr;
      stressxy[q] *= invr;
      press[q] = stressxx[q]+stressyy[q];
      rad[q] = sqrt(0.25*(stressxx[q]-stressyy[q])*(stressxx[q]-stressyy[q]) + stressxy[q]*stressxy[q]);
    }

  int numintot = 0;
  for(q = 0; q < NUMPART; q++)
    {
      if (press[q] > 0.)
	numintot++;
      totpress += press[q]; // pressure
      total2 += press[q]*press[q];
      e1total += 0.5*press[q] + rad[q];
      e2total += 0.5*press[q] - rad[q];
    }
  pressave = totpress/numintot;

#if (PRINT_FVT)
  if (tstep >= 0)
    {
    fprintf(pvtfile, "%.6f\n", 
	    totpress * mscale * invtscale * invtscale);
    //    fprintf(pvtfile, "%.2f %.2f\n", 
    //    totpress * mscale * invtscale * invtscale, sqrt(totpress*totpress/total2));

    //    fprintf(pvtfile, "%.7f %.2f %.2f\n", tstep*dt*tscale, 
    //	    totpress * mscale * invtscale * invtscale, sqrt(totpress*totpress/total2));

  //	 fprintf(psvtfile, "%.8f %12.10g %12.10g\n", tstep*dt*tscale, 
  //		 e1total * mscale * invtscale * invtscale, e2total * mscale * invtscale * invtscale);
    }
#endif

}
