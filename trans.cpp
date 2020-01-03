
#include "common.h"

void trans()
{
  int numout;
  int tloop, inner;

  int thermal_steps = (int) ((thermal_time/dt) + 0.5);
  fprintf(stderr,"thermal steps = %d \n",thermal_steps);
  fprintf(stderr,"thermal time = %f \n",thermal_time);
  fprintf(stderr,"dt = %f \n",dt);
  fprintf(stderr,"the first for loop goes to %d", (thermal_steps/(EVERY*TBETWEENFRAMES)));
  for (numout = 0; numout < (thermal_steps/(EVERY*TBETWEENFRAMES)); numout++)
    { 
		//fprintf(stderr,"for loop %d",numout);

      for (tloop = 0; tloop < TBETWEENFRAMES; tloop++)
        {
		//fprintf(stderr,"nested tloop  = %d \n",tloop);

		
		for (inner = 0; inner < EVERY; inner++)
			{
			//fprintf(stderr,"double nested loop = %d \n",inner);
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
