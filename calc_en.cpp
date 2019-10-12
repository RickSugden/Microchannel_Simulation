
#include "common.h"

void calc_en(int tstep)
{
  double ke;
  double ketotal = 0.;
  double ketotal2 = 0.;
  int q;

  for (q = 0; q < NUMPART; q++)
    {
      ke = m[q] * (vx[q]*vx[q] + vy[q]*vy[q]);
      ketotal += ke;
      ketotal2 += ke*ke;
    }
  //  fprintf(evtfile, "%.7f %7.5g %7.5g\n", tstep*dt*tscale, 
  //	  ketotal * mscale * xscale * xscale * invtscale * invtscale, 
  //      sqrt(ketotal*ketotal/ketotal2));
  fprintf(evtfile, "%7.5g\n", 
	  ketotal * mscale * xscale * xscale * invtscale * invtscale);
}
