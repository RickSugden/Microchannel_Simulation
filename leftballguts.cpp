#include "common.h"

void leftballguts(int p1, double rx, double ry)
{
  double d2, d, diff, dinv, riprj;
  double rhatx, rhaty;
  double vxij, vyij;
  double vijdotrhat;
  double vijnx, vijny;
  double fx, fy, fdotrhat;
  double vijtx, vijty, vtmag;
  double vtinv, ftx, fty, thatx, thaty;
  double wallx, wally;

  /* For interaction with wall balls */

  d2 = rx*rx + ry*ry;

  riprj = r[p1] + WALLBALLR;

  if(d2 < riprj*riprj)
    {
      d = sqrt(d2);
      diff = (d - riprj);
      dinv = 1./d;

      rhatx = rx * dinv;
      rhaty = ry * dinv;

      vxij = -vx[p1];
      vyij = lxwall_velocity - vy[p1];
      
      vijdotrhat = vxij*rhatx + vyij*rhaty;
      
      vijnx = vijdotrhat * rhatx;
      vijny = vijdotrhat * rhaty;

      fx = kn * diff * rhatx + gamman * vijnx;
      fy = kn * diff * rhaty + gamman * vijny;
            
      fdotrhat = fx * rhatx + fy * rhaty;

      if (fdotrhat > 0.)
	fdotrhat = 0.;
      else
	if (fdotrhat < 0.)
	  {
	    vijtx = vxij - vijnx;
	    vijty = vyij - vijny;

	    vtmag = sqrt(vijtx*vijtx + vijty*vijty);

	    if ((gammas * vtmag) < (-MU * fdotrhat))
	      {
		ftx = gammas * vijtx;
		fty = gammas * vijty;

	      }
	    else
	      {
		if(vtmag > 0.)
		  {
		    vtinv = 1./vtmag;

		    thatx = vijtx * vtinv;
		    thaty = vijty * vtinv;

		    ftx = -MU * fdotrhat * thatx;
		    fty = -MU * fdotrhat * thaty;
	        
		  }
		else
		  {
		    ftx = 0.;
		    fty = 0.;
		  }
	      }

	    ax[p1] += fx + ftx;
	    ay[p1] += fy + fty;
	    
	    // kept only normal parts 12/23/09
	    stressxx[p1] += (fx) * rhatx;
	    stressyy[p1] += (fy) * rhaty;

	    stressxy[p1] += 0.5*((fx) * rhaty + (fy) * rhatx);

	    wbforce += fy+fty;

	  }
    }


}
