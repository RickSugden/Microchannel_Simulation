#include "common.h"

void rebox()
{
  int p;
  int newcell;

  for (p = 0; p < NUMPART; p++)
    {
      //periodic boundary condition
      if(y[p] < 0.)
	y[p] += LY;
      else
	if(y[p] >= LY)
	  y[p] -= LY;
 
      newcell = (int)(x[p]*invdx) + NX * (int)(y[p]*invdy);

      //if p has moved into a new cell, i.e., out of the old cell[p]
      if(newcell != cell[p])
	{
	  numincell[cell[p]]--;

	  //renumbering the particles in cell
	  if(numincell[cell[p]] > 0)
	    {    
	      //if prev[p] is not the value FIRST
	      if (prev[p] != FIRST)
		next[prev[p]] = next[p];
	      //if prev[p] is FIRST, make firstincell next[p]
	      //this happens if p moves out of cell and p was firstincell
	      else
		firstincell[cell[p]] = next[p];
	      //if next[p] is not the value LAST, previous of next becomes prev[p]
	      if(next[p] != LAST)
		prev[next[p]] = prev[p];
	    }
	  else
	    firstincell[cell[p]] = LAST;

	  cell[p] = newcell;
	  numincell[cell[p]]++;
	  next[p] = firstincell[cell[p]];

	  if(next[p] != LAST)
	    prev[next[p]] = p;

               
	  firstincell[cell[p]] = p;
	  prev[p] = FIRST;
	}
                         
    }
}
