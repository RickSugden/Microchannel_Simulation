#include "common.h"

void move_walls()
{
           
  lxwall_offset += lxwall_velocity * dt;
  rxwall_offset += rxwall_velocity * dt;

  if(lxwall_offset > HALFWBSPACING)
    lxwall_offset -= WALLBALLSPACING;  //because of periodic boundary condition
  else
    if (lxwall_offset < -HALFWBSPACING)
      lxwall_offset += WALLBALLSPACING;

  if(rxwall_offset > HALFWBSPACING)
    rxwall_offset -= WALLBALLSPACING;  //because of periodic boundary condition
  else
    if (rxwall_offset < -HALFWBSPACING)
      rxwall_offset += WALLBALLSPACING;

}
