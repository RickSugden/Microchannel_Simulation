#include "common.h"

void int_cells(int c1, int c2)
{
  int p1, p2;
  
  if(numincell[c2] != 0)       //if there are particles in other cell...
    for(p1 = firstincell[c1]; p1 != LAST; p1 = next[p1])
      for(p2 = firstincell[c2]; p2 != LAST; p2 = next[p2])
	  interact(p1, p2, x[p2]-x[p1], y[p2]-y[p1]);

  //interact wants a vector pointing from p1 to p2
}
