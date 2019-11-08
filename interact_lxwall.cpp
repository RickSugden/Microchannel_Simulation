#include "common.h"

void interact_lxwall(int p1)
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
  double rx, ry;

  /* For interaction with wall balls */

  wallx = 0.0;
  wally = ((int)((y[p1] - lxwall_offset + WALLBALLSPACING)*INVWBSPACING))*WALLBALLSPACING - 
    HALFWBSPACING + lxwall_offset;  //where along the wall disk is located
  //first figure out which ball closest to
  //final position is that of wallball

  //x and y distances away from wallballs
  rx = wallx - x[p1];
  ry = wally - y[p1];

  leftballguts(p1, rx, ry);

  ry += WALLBALLSPACING;
  leftballguts(p1, rx, ry);

  ry -= 2*WALLBALLSPACING;
  leftballguts(p1, rx, ry);


  /* Now check for interaction with wall */

  wallx = 0.;
  wally = y[p1];

  rx = wallx - x[p1]; //distance between ball and wall in x direction
  ry = 0.0; // we analyze the ball against the portion of the wall with the same Y value

  d2 = rx*rx;

  if(d2 < r[p1]*r[p1]) //this means if the distance btwn wall and ball is less than the r of ball, theyre touching, so compute
    {
      //      exit(-2);

      d = sqrt(d2);
      diff = (d - r[p1]); //(distance btwn - ball r) must return a negative number, since they are overlapping
      dinv = 1./d;

      rhatx = rx * dinv; //distance btwn * inverse of overlap
      rhaty = 0.; // i believe this is zero because we aren't looking at shear force yet

      //difference in velocity
      vxij = -vx[p1]; //since wall doesnt move in x direction
      vyij = lxwall_velocity - vy[p1]; // relative velocity in y direction
      
      vijdotrhat = vxij*rhatx; //relative velocity * (distance btwn * inverse of overlap)
      
      //the next line reapplies the multiplication that just happened, i dont understand the physical representation
      vijnx = vijdotrhat * rhatx;//relative velocity * (distance btwn * inverse of overlap)* (distance btwn * inverse of overlap)
      vijny = 0.0;

      //f in x direction = vector just calculated *gamman? + overlap*(distance btwn * inverse of overlap)
      fx = kn * diff * rhatx + gamman * vijnx; //kn is in units of surface tension
      fy = 0.0; // we continue to assume force in the y direction is zero
      
      fdotrhat = fx * rhatx;

      if (fdotrhat > 0.)
	fdotrhat = 0.;
      else
	if (fdotrhat < 0.)
	  {
	    vijtx = 0.;
	    vijty = vyij;

	    vtmag = sqrt(vijty*vijty);

	    if ((gammas * vtmag) < (-MU * fdotrhat))
	      {
		ftx = 0.0;
		fty = gammas * vijty;
	      }
	    else
	      {
		if(vtmag > 0.)
		  {
		    vtinv = 1./vtmag;

		    thatx = 0.;
		    thaty = vijty * vtinv;

		    ftx = 0.0;
		    fty = -MU * fdotrhat;
		    
		  }

		else
		  {
		    ftx = 0.;
		    fty = 0.;
		  }
	      }

	    ax[p1] += fx + ftx;
	    ay[p1] += fy + fty;

	    // changed 12/23/09 to only use normal forces
	    stressxx[p1] += (fx) * rhatx;
	    stressxy[p1] += 0.5*((fy) * rhatx);

	  }
    }
}
