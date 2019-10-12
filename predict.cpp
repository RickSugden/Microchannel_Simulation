#include "common.h"

void predict()
{
  int p;

  // from Gear predictor-corrector

  for(p = 0; p < NUMPART; p++)
    {
      x[p]  += dt*vx[p] + DT2o2*ax[p] + DT3o6*bx[p] + DT4o24*cx[p];
      vx[p] += dt*ax[p] + DT2o2*bx[p] + DT3o6*cx[p];
      axp[p] = ax[p] + dt*bx[p] + DT2o2*cx[p];
      bx[p] += dt*cx[p];
    }

  for(p = 0; p < NUMPART; p++)
    {
      y[p]  += dt*vy[p] + DT2o2*ay[p] + DT3o6*by[p] + DT4o24*cy[p];
      vy[p] += dt*ay[p] + DT2o2*by[p] + DT3o6*cy[p];
      ayp[p] = ay[p] + dt*by[p] + DT2o2*cy[p];
      by[p] += dt*cy[p];
    }

}
