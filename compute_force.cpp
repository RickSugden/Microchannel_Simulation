#include "common.h"

void compute_force()
{
  int xc, yc, c;   //counters for cell number
  int p,k;

  for(p = 0; p < NUMPART; p++)
    {
      ax[p] = 0.;
      ay[p] = 0.;

      stressxx[p] = 0.;
      stressyy[p] = 0.;
      stressxy[p] = 0.;
    }

  wbforce = 0.;

  //left wall except upper corner
  for(c = 0; c < NX*NY - NX; c += NX)
    if(numincell[c] > 0)
      {
	int_self(c);           //interactions with disks in own cell
	int_cells(c, c+1);     //with disks in cell to right
	int_cells(c, c+NX);    //with disks above
	int_cells(c, c+NX+1);  //diagonally above to the right
	int_lxwall(c);         //interaction with left wall
      }

  //upper left corner
  if(numincell[c] > 0)
    {
      int_self(c);
      int_cells(c, c+1);
      int_cells_yp(0, c);
      int_cells_yp(1, c);
      int_lxwall(c);
    }

  //bulk
  for(yc = 0; yc < NY-1; yc++)
    {
      for(c = yc*NX + 1; c < yc*NX + (NX-1); c++) //remember cell numbering starts with 0
	{
	  if(numincell[c] > 0)
	    {
	      int_self(c);
	      int_cells(c, c+NX-1);
	      int_cells(c, c+NX);
	      int_cells(c, c+NX+1);
	      int_cells(c, c+1);
	    }
	}
    }

  //upper row except adjacent to walls
  for(xc = 1; xc < NX-1; xc++)
    {
      c = NX * (NY-1) + xc;
      if(numincell[c] > 0)
	{
	  int_self(c);
	  int_cells(c, c+1);
	  int_cells_yp(xc-1, c);
	  int_cells_yp(xc, c);
	  int_cells_yp(xc+1, c);
	}
    }

  //right wall except upper corner
  for(c = NX-1; c < NX*NY-1; c += NX)
    if(numincell[c] > 0)
      {
	int_self(c);
	int_cells(c, c+NX-1);
	int_cells(c, c+NX);
	int_rxwall(c);
      }

  //upper right corner
  if(numincell[c] > 0)
    {
      int_self(c);
      int_cells_yp(NX-2, c);
      int_cells_yp(NX-1, c);
      int_rxwall(c);
    }

#if (BOTTOM_FORCE_ON)
  int_bottom();
#endif
}
