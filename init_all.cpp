#include "common.h"

void init_all()
{
  int p, p2;     //particles
  double dist;
  double ydiff;
  int numout;
  int overlap;
  double stepsize;
  int count;
  int pb, ps;

  srandom(RSEED);

  LX = STARTLX;
  invdx = NX/LX;

  for(long rrr = 0; rrr < 20.3*NUMPART; rrr++)
    int randtemp = random();

  ps = pb = 0;

  for(p = 0; p < NUMPART; p++)
    {
      if ( ((double) random()/RAND_MAX) > SMALLSIZEFRACTION ) //make two ball sizes
	if (pb < NUMBIG)
	  {
	    r[p] = BIGR;
	    pb++;
	  }
	else
	  {
	    r[p] = SMALLR;
	    ps++;
	  }
      else
	if (ps < NUMSMALL)
	  {
	    r[p] = SMALLR;
	    ps++;
	  }
	else
	  {
	    r[p] = BIGR;
	    pb++;
	  }
      
      do
	{
	  // no overlaps with wall
    //this next line assigns the centre of the ball's X position as at least one wall ball r plus the maximum ball
    // radius (no overlap) then adding a randomly generated percentage of the effective width (wall ball&bigR subtracted from each side)
    // Y is simply a random percentage of the y length
	  x[p] = BIGR+WALLBALLR + ((double) random()/RAND_MAX) * (LX-2*(BIGR+WALLBALLR));
          y[p] = ((double) random()/RAND_MAX) * (LY);
	  
	  overlap = 0;

	  for(p2 = 0; (p2 < p) && (overlap == 0); p2++)
	    {
	      ydiff = y[p]-y[p2];
	      if (ydiff > 0.5*LY)
		ydiff -= LY;
	      if (ydiff < -0.5*LY)
		ydiff += LY;
	      dist = sqrt(((x[p]-x[p2]) * (x[p]-x[p2])) + ydiff * ydiff);
	      if (dist < (r[p]+r[p2]))
		overlap = 1;
	    }
	}
      while (overlap == 1);

      m[p] = PI*r[p]*r[p]*DISKH*DISKDENSITY;
      invm[p] = 1.0/m[p];
      // invI[p] = invm[p]/(0.5*r[p]*r[p]);      // I = (1/2) M R^2 
    }

  fprintf(stderr, "Done placing disks\n");
  
  for(p = 0; p < NUMPART; p++)
    {
      vx[p] = 0.;
      vy[p] = 0.;
      ax[p] = 0.;
      ay[p] = 0.;
      bx[p] = 0.;
      by[p] = 0.;
      cx[p] = 0.;
      cy[p] = 0.;
      press[p] = 1.0;
    }
  pressave = 1.0;
  
  assign_to_cells();

  lxwall_offset = 0.;
  rxwall_offset = 0.;

#if (RESIZE_STEPS > 0)
  stepsize = ((STARTLX - ENDLX) / RESIZE_STEPS);

  double oldLX;

  for (numout = 0; numout < RESIZE_STEPS; numout++)
    {
      oldLX = LX;
      LX = STARTLX - (stepsize * numout);
      invdx = NX/LX;
      
      for(count = 0; count < NUMPART; count++)
	{
	  x[count] = (x[count] * LX) / oldLX;
	}

      move_walls();

      predict();

      rebox();

      compute_force();

      f_to_a();

      correct();
    }
#endif

  LX = ENDLX;             //should be unnecessary, but just a check
  invdx = NX/LX;

}
