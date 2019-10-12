#include "common.h"

// Put in friction with bottom plate 

void int_bottom()
{
  int p;
  double invvmag;
  double invvmag2;
  double vdotdelta[NUMVECT];

  for (p = 0; p < NUMPART; p++)
  {
    if ((vx[p] != 0.) || (vy[p] != 0.))
	{
	  invvmag = 1./sqrt(vx[p]*vx[p]+vy[p]*vy[p]);
	  invvmag2 = invvmag * invvmag;

	  
	  ax[p] -= MU_BOTTOM * m[p] * G * vx[p] * invvmag;    //G is for gravity
	  ay[p] -= MU_BOTTOM * m[p] * G * vy[p] * invvmag;
	
	}
  }
}
