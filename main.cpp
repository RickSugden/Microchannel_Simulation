//rick
//cpp program
#define EXT
#include "common.h"

int main(int argc, char *argv[])
{
  int numout;
  int i,inner, tloop, numframe;
  int thermal_steps;

  int q;

  if (argc != 4)
    {
      fprintf(stderr, "runme TARGETDENSITY ASPECT_RATIO ic\n");
      exit(-1);
    }
  sscanf(argv[1], "%lg", &TARGETDENSITY);
  sscanf(argv[2], "%lg", &ASPECT_RATIO);
  sscanf(argv[3], "%i", &ic);
  fprintf(stderr, "Starting with dens=%g a=%g ic=%8.8i\n", TARGETDENSITY, ASPECT_RATIO, ic);

  init_scaled_params();
    

  make_dirs();
 

  if (RESTART_STATE)
    read_restart();
  else
    init_all();

  trans();
  fprintf(stderr, "trans() is finished \n");
  open_files();

  write_params();

  if (WRITE_START)
    write_restart(0);

  get_press_noprint(); // can remove this if we stop tracking changes in pressure

  int counter = 0;
  //now we run the simulation and get data
  for (numframe = 0; numframe < FRAMES; numframe++)
    {
      if ((numframe % 50 )==0)
      {
        
      write_restart(100+counter); // this will output the frame data as a .frame text file
      counter = counter +1;
      }
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


	  int tstep = (numframe*TBETWEENFRAMES+tloop+1)*EVERY;

	  get_pressure(tstep); // done before renorm since we're excluding particles from lyap stuff based on pressure

#if (PRINT_EVT)
	  calc_en(tstep);
#endif

#if (PRINT_WB)
	  write_wb(tstep);
#endif

	}
    fprintf(stderr, "the wall force total for this frame was: %f", wall_force);


#if (DUMP_DATA)
      dump_data(numframe);
#endif

#if (PRINT_PF)
      output_pf(numframe);//one function to output positions and forces
#endif

    }

  if (WRITE_END)
    write_restart(1);

  return(0);
}
