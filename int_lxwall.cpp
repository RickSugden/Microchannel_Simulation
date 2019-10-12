#include "common.h"

void int_lxwall(int c1)
{
  int p1;
  
  for (p1 = firstincell[c1]; p1 != LAST; p1 = next[p1])
    interact_lxwall(p1);
}
