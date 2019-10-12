#include "common.h"

void correct()
{
  int p;
  double diffx[NUMPART], diffy[NUMPART];

  for(p = 0; p < NUMPART; p++)
    {
      diffx[p] = ax[p] - axp[p];
      diffy[p] = ay[p] - ayp[p];
    }

  for(p = 0; p < NUMPART; p++)
    {
      x[p] += diffx[p] * PFACTOR;
      vx[p] += diffx[p] * VFACTOR;
      bx[p] += diffx[p] * BFACTOR;
      cx[p] += diffx[p] * CFACTOR;
    }

  for(p = 0; p < NUMPART; p++)
    {
      y[p] += diffy[p] * PFACTOR;
      vy[p] += diffy[p] * VFACTOR;
      by[p] += diffy[p] * BFACTOR;
      cy[p] += diffy[p] * CFACTOR;
    }

}
