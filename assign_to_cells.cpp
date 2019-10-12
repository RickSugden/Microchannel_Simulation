#include "common.h"

void assign_to_cells()
{
  int c, p;
  
  for (c = 0; c < NUMCELL; c++)  //c = 0, increment until hit reaches number of cells
    {
      numincell[c] = 0;   //set number of disks in each cell equal to 0
      firstincell[c] = LAST;   //-2
    }

  for(p = 0; p < NUMPART; p++)
    cell[p] = (int)(x[p]*invdx) + NX*(int)(y[p]*invdy); //cell p is in is an integer combination of x and y pos.

  for(p = 0; p < NUMPART; p++)
    {
      numincell[cell[p]]++;   //increase number in cell for every disk p assigned to the cell
      next[p] = firstincell[cell[p]]; //set next[p] equal to first in cell of cell of p
      if(next[p] != LAST)  //if next[p] is not the last then p is the prev of next
	prev[next[p]] = p;
      firstincell[cell[p]] = p; //set first in cell to be p
      prev[p] = FIRST;  
    }
}
