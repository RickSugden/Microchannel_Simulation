
#include "common.h"

void trans()
{
  int numout;
  int tloop, inner;

  int thermal_steps = (int) ((thermal_time/dt) + 0.5);

  for (numout = 0; numout < (thermal_steps/(EVERY*TBETWEENFRAMES)); numout++)
    { 
      for (tloop = 0; tloop < TBETWEENFRAMES; tloop++)
	{
	  for (inner = 0; inner < EVERY; inner++)
	    {
	      move_walls();

	      predict();

	      rebox();

	      compute_force();
              
	      f_to_a();
              
	      correct();
	    }

	  get_pressure(-1);
	}
    }
  
}
