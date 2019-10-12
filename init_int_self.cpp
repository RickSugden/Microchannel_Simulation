#include "common.h"

void init_int_self(int c1)
{
  int p1, p2;

  for(p1 = firstincell[c1]; p1 != LAST; p1 = next[p1])
    for(p2 = next[p1]; p2 != LAST; p2 = next[p2])
      init_interact(p1, p2, x[p2]-x[p1], y[p2] -y[p1]);
}
