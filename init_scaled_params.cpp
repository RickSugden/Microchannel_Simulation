#include "common.h"

void init_scaled_params()
{
  xscale = uSMALLR;
  invxscale = 1./xscale;

  mscale = PI * xscale * xscale * uDISKH * uDISKDENSITY;
  invmscale = 1./mscale;

  tscale = sqrt(mscale/uKN);
  invtscale = 1./tscale;

  thermal_time = uTHERMAL_TIME * invtscale;

  lxwall_velocity = uLXWALL_VELOCITY * invxscale * tscale;
  rxwall_velocity = uRXWALL_VELOCITY * invxscale * tscale;

  WALLBALLR = uWALLBALLR * invxscale;
  WALLBALLSPACING = uWALLBALLSPACING * invxscale;

  HALFWBSPACING = 0.5*WALLBALLSPACING;
  INVWBSPACING = 1./WALLBALLSPACING;

  DISKH = uDISKH * invxscale;
  DISKDENSITY = uDISKDENSITY * xscale * xscale * xscale * invmscale;

  G = uG * invxscale * tscale * tscale;

  kn = uKN * invmscale * tscale * tscale; // Should be 1 in scaled units
  gamman = uGAMMAN * invmscale * tscale;
  gammas = uGAMMAS * invmscale * tscale;

  dt = uDT * invtscale;

  SMALLR = uSMALLR * invxscale;

  LX = ENDLX;

  int nwallball = (int) (0.5 + ((double) LY)/WALLBALLSPACING); //number of balls on wall = length/spacing increment
  double arealeft = LX * LY - nwallball * PI * WALLBALLR * WALLBALLR; //subtract the wall balls from area left

  NUMPART = (int) (PARTBASE * ASPECT_RATIO + 0.5);
  NUMSMALL = (int) (NUMPART * SMALLSIZEFRACTION + 0.5);
  NUMBIG = NUMPART - NUMSMALL;

  if (NUMPART > MAXPART)
    {
      fprintf(stderr, "Need to adjust MAXPART\n");
      exit(-1);
    }

  SIZERATIO = sqrt((TARGETDENSITY*arealeft/PI - NUMSMALL * SMALLR * SMALLR) / 
		   (NUMBIG * SMALLR * SMALLR));
  BIGR = SMALLR * SIZERATIO;
  DENSITY = PI * (NUMSMALL * SMALLR * SMALLR + NUMBIG * BIGR * BIGR) / (arealeft);

  NX = (int) (ENDLX/(2.0*BIGR));  // min is 2*BIGR
  NY = (int) (LY/(2.0*BIGR)); // min is 2*BIGR
  if (NUMCELL > MAXCELL)
    {
      fprintf(stderr, "Need to adjust MAXCELL\n");
      exit(-1);
    }

  invdy = NY/LY;
  invdx = NX/LX;

  DT2o2 = (dt*dt/2.0);
  DT3o6 = (dt*dt*dt/6.0);
  DT4o24 = (dt*dt*dt*dt/24.);

  //  PFACTOR = ((19.0*dt*dt)/(120.0*2.0)); 
  PFACTOR = ((19.0*dt*dt)/(90.0*2.0)); /* Changed 6/17/09 */
  VFACTOR = ((3.0*dt)/(4.0*2.0));
  BFACTOR = ((1.0*3.0)/(2.0*dt));
  CFACTOR = ((1.0*12.0)/(12.0*dt*dt));

  WFACTOR = ((3.0*dt)/(8.0));
  WDDFACTOR = ((3.0*2.0)/(4.0*dt));
  WDDDFACTOR = ((1.0*6.0)/(6.0*dt*dt));

}
