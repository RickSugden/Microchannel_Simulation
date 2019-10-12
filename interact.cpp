#include "common.h"

/* Switched velocity differences to be consistent with thesis 7/24/09 */

void interact(int p1, int p2, double rx, double ry)   //rx and ry are distance vectors
{
  double d2, d, diff, dinv, riprj;  //dist^2, dist, diff, 1/d, sum of two radii
  double rhatx, rhaty;
  double vijnx, vijny;
  double fx, fy, fdotrhat;
  double vijtx, vijty, vtmag;
  double vtinv, ftx, fty, thatx, thaty;
  double vxij, vyij, vijdotrhat;


  d2 = rx*rx+ry*ry;

  riprj = r[p1]+r[p2];

  if(d2 < riprj*riprj)
    {
      d = sqrt(d2);
      diff = (d-riprj);   //a negative value, unless the disks are not touching
      dinv = 1./d;
      
      rhatx = rx * dinv;  //unit vectors
      rhaty = ry * dinv;

      //Force laws etc.

      vxij = vx[p2] - vx[p1];
      vyij = vy[p2] - vy[p1];

      vijdotrhat = vxij*rhatx + vyij*rhaty;

      vijnx = vijdotrhat * rhatx; //normal velocities
      vijny = vijdotrhat * rhaty;

      //elastic spring laws and dissipative normal force
      fx = kn * diff * rhatx + gamman * vijnx;
      fy = kn * diff * rhaty + gamman * vijny;

      fdotrhat = fx * rhatx + fy * rhaty;  //think negative or positive?
   
      if (fdotrhat > 0.)
	fdotrhat = 0.;
      else
	if (fdotrhat < 0.)
	  {
	    vijtx = vxij - vijnx;  //shear velocities are whatever is not due to normal
	    vijty = vyij - vijny;

	    vtmag = sqrt(vijtx*vijtx + vijty*vijty);      
                      
	    if ((gammas * vtmag) < (-MU * fdotrhat))
	      {
		/* Schoellmann paper has wrong sign for these */
		ftx = gammas * vijtx;
		fty = gammas * vijty;
	      }
	    else
	      {
		if (vtmag > 0.)
		  {
		    vtinv = 1./vtmag;
		    
		    thatx = vijtx * vtinv;
		    thaty = vijty * vtinv;
		    
		    /* Note: fdotrhat < 0, so need extra "-" for abs(f) */
		    ftx = -MU * fdotrhat * thatx;
		    fty = -MU * fdotrhat * thaty;
		    
		  }
		else
		  {
		    ftx = 0.;
		    fty = 0.;
		  }
	      }


	    ax[p1] += fx + ftx;     //increment as a force, adjusted later by f_to_a()
	    ay[p1] += fy + fty;
	    ax[p2] -= fx + ftx;
	    ay[p2] -= fy + fty;

	    // changed to just normal on 12/23/09
	    stressxx[p1] += (fx) * rhatx;
	    stressxx[p2] += (fx) * rhatx;
	    stressyy[p1] += (fy) * rhaty;
	    stressyy[p2] += (fy) * rhaty;

	    stressxy[p1] += 0.5*((fx) * rhaty + (fy) * rhatx);
	    stressxy[p2] += 0.5*((fx) * rhaty + (fy) * rhatx);
	    
	  }
    }
}
