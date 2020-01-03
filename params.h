
/* We will use primed units of ball radii and cycles !! */

//0 false, 1 true
#define RESTART_STATE 0//true if we want to restart from a file
#define RESTART_TIME 0 // 0 means "start", 1 means "end"
#define RESTART_SUB 1000 // how to find restart data ; ic - RESTART_SUB
#define WRITE_START 1//true if we want to write a restart file after the transient
#define WRITE_END 1//true if we want to write a restart file after the run
#define PRINT_FVT 1
#define PRINT_EVT 0
#define PRINT_WB 0
#define PRINT_PF 0
#define DUMP_DATA 0

//#define DIRNUM ic
//#define TARGETDENSITY 0.82
#define RESTART_DENSITY DENSITY // the density of the run in the restart file

#define SLOW 0
#define RSEED (3+2*ic)

#define RESIZE_STEPS 10000 // was 100000
//#define RESIZE_STEPS 0
#if SLOW
#define uTHERMAL_TIME 500.0//longer transient for slow walls
#else
#define uTHERMAL_TIME 200 //can be changed to 20 to save time
//#define uTHERMAL_TIME 400.0
#endif
//#define TBETWEENFRAMES 10000
//#define TBETWEENFRAMES 40000
#define TBETWEENFRAMES 1000
//#define TBETWEENFRAMES 100
//#define TBETWEENFRAMES 1//wasnt originally an option
#define EVERY 1
#define FRAMES 5000
//#define FRAMES 50

#if SLOW
#define uWALL_VELOCITY 0.00002
#else
#define uWALL_VELOCITY 0.00055// 0.005//m/s moves up  //0.0001 is the original value
#endif
#define uLXWALL_VELOCITY uWALL_VELOCITY
#define uRXWALL_VELOCITY (-1.*uWALL_VELOCITY)

#define ENDLX 50. // units of small ball radii
//#define ASPECT_RATIO 1.0 // LY/ENDLX  CHECK WHETHER THIS YIELDS A MULTIPLE OF WALLBALLSPACING
#define LY (ASPECT_RATIO*ENDLX) 
#define STARTLX (3.*ENDLX)

#define PARTBASE 440 // total # of big and small particles in aspect ratio of 1

#define SMALLSIZEFRACTION 0.5
#define BIGSIZEFRACTION (1.0-SMALLSIZEFRACTION)
#define uSMALLR 0.0035 // m
//#define SIZERATIO 1.4
#define uBIGR (SIZERATIO*uSMALLR) // m

//#define uWALLBALLR (0.40*uSMALLR) // originally .001 m
//#define uWALLBALLSPACING (5.0*uWALLBALLR) // originally .005 m
//#define uWALLBALLR (1.25*uSMALLR) // originally .001 m
//#define uWALLBALLSPACING (4.0*uWALLBALLR) // originally .005 m
//#define uWALLBALLR (0.80*uSMALLR) // originally .001 m
//#define uWALLBALLSPACING (2.5*uWALLBALLR) // originally .005 m
#define uWALLBALLR (0.80*uSMALLR) // originally .001 m
#define uWALLBALLSPACING (2.5*uSMALLR) // originally .005 m
// LY can safely be any multiple of 2.5 -- aspect ratio 

#define uDISKDENSITY 1060.0 //  kg/m^3
#define uDISKH 0.006 // m

#define uG (9.800) // m/s^2

#define uKN 352.1//100.0//352.1 // N/m
#define uGAMMAN 0.19 // kg/s
//#define uGAMMAN 0.38 // kg/s
#define uGAMMAS 0.15 // kg/s
#define MU 0.44
#define BOTTOM_FORCE_ON 0
#define MU_BOTTOM 0.00000 // originally 0.00002

//#define uDT 0.004//This wasnt originally an option
//#define uDT 0.00004//s
//#define uDT 0.000005//s
#define uDT 0.00004//s wasnt originally an option
/* must have NX < LX/(2 BIGR) and NY < LY / (2 BIGR) */

#define NUMCELL (NX*NY)
#define MAXCELL 13000
#define MAXPART 15000

#define FIRST -1
#define LAST -2

#define TWOPI 6.283185307179586
#define PI 3.141592653589793

#define LEFTBALL (NUMPART+10)
#define LEFTWALL (NUMPART+11)
#define RIGHTBALL (NUMPART+12)
#define RIGHTWALL (NUMPART+13)

#define BIGBUFF 1048576

//i add my own



/* Now initialized in init_scaled_params.cpp
#define DT2o2 (dt*dt/2.0)
#define DT3o6 (dt*dt*dt/6.0)
#define DT4o24 (dt*dt*dt*dt/24.)

#define PFACTOR ((19.0*dt*dt)/(120.0*2.0)) 
#define VFACTOR ((3.0*dt)/(4.0*2.0))
#define BFACTOR ((1.0*3.0)/(2.0*dt))
#define CFACTOR ((1.0*12.0)/(12.0*dt*dt))

#define WFACTOR ((3.0*dt)/(8.0))
#define WDDFACTOR ((3.0*2.0)/(4.0*dt))
#define WDDDFACTOR ((1.0*6.0)/(6.0*dt*dt))
*/

