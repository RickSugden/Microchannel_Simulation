#include "common.h"
#include "params.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>
#include <time.h>

void write_params()
{
  char fname[72];
  FILE *pfile;
  

  sprintf(fname, "catalog");
  pfile = fopen(fname, "a");
  time_t tt = time(NULL);
  fprintf(pfile, "%.4f %1.f %i %s", DENSITY, ASPECT_RATIO, ic, ctime(&tt));
  fclose(pfile);

  sprintf(fname, "params/d%.4f/a%.2f/params.%4.4i", DENSITY, ASPECT_RATIO, ic);
  pfile = fopen(fname, "w");

  //  fprintf(pfile, "DIRNUM\t%9.9lu\n", DIRNUM);
  fprintf(pfile, "ic\t%i\n", ic);

  fprintf(pfile, "DENSITY\t%g\n", DENSITY);
  fprintf(pfile, "TARGETDENSITY\t%g\n", TARGETDENSITY);
  fprintf(pfile, "ASPECT_RATIO\t%g\n", ASPECT_RATIO);
  fprintf(pfile, "ENDLX\t%g\n", ENDLX);
  fprintf(pfile, "LY\t%g\n", LY);
  fprintf(pfile, "STARTLX\t%g\n", STARTLX);

  fprintf(pfile, "uWALL_VELOCITY\t%g\n", uWALL_VELOCITY);

  fprintf(pfile, "RESIZE_STEPS\t%i\n", RESIZE_STEPS);
  fprintf(pfile, "uTHERMAL_TIME\t%g\n", uTHERMAL_TIME);
  fprintf(pfile, "TBETWEENFRAMES\t%i\n", TBETWEENFRAMES);
  fprintf(pfile, "EVERY\t%i\n", EVERY);
  fprintf(pfile, "FRAMES\t%i\n", FRAMES);

  fprintf(pfile, "NUMPART\t%i\n", NUMPART);
  fprintf(pfile, "NUMSMALL\t%i\n", NUMSMALL);
  fprintf(pfile, "NUMBIG\t%i\n", NUMBIG);
  fprintf(pfile, "SMALLSIZEFRACTION\t%g\n", SMALLSIZEFRACTION);
  fprintf(pfile, "uSMALLR\t%g\n", uSMALLR);
  fprintf(pfile, "SIZERATIO\t%g\n", SIZERATIO);
  fprintf(pfile, "uWALLBALLR\t%g\n", uWALLBALLR);
  fprintf(pfile, "uWALLBALLSPACING\t%g\n", uWALLBALLSPACING);

  fprintf(pfile, "uDISKDENSITY\t%g\n", uDISKDENSITY);
  fprintf(pfile, "uDISKH\t%g\n", uDISKH);
  fprintf(pfile, "uG\t%g\n", uG);
  fprintf(pfile, "uKN\t%g\n", uKN);
  fprintf(pfile, "uGAMMAN\t%g\n", uGAMMAN);
  fprintf(pfile, "uGAMMAS\t%g\n", uGAMMAS);
  fprintf(pfile, "MU\t%g\n", MU);
  fprintf(pfile, "MU_BOTTOM\t%g\n", MU_BOTTOM);
  fprintf(pfile, "uDT\t%g\n", uDT);

  fprintf(pfile, "RESTART_STATE\t%i\n", RESTART_STATE);
  fprintf(pfile, "RESTART_TIME\t%i\n", RESTART_TIME);
  fprintf(pfile, "RESTART_SUB\t%i\n", RESTART_SUB);
  fprintf(pfile, "RESTART_DENSITY\t%g\n", RESTART_DENSITY);

  fprintf(pfile, "NX\t%i\n", NX);
  fprintf(pfile, "NY\t%i\n", NY);

  fclose(pfile);

}
