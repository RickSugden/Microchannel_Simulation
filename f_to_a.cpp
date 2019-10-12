#include "common.h"
    
//the purpose of this function is to convert the acceleration which has been tabulated 
//as a force into m/s^2 (or ang. accel. from a torque)

void f_to_a()
{
  int p;

  for (p = 0; p < NUMPART; p++)
    {
      ax[p] *= invm[p];
      ay[p] *= invm[p];
    }
}
