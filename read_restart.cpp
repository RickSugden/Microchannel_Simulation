#include "common.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

void read_restart()
{
  char fname[72];
  int filed;
  long nb;
  int p;

  if (RESTART_TIME == 0)
    sprintf(fname, "restart/d%.4f/a%.2f/%4.4i.start", DENSITY, ASPECT_RATIO, ic-RESTART_SUB);
  else
    sprintf(fname, "restart/d%.4f/a%.2f/%4.4i.end", DENSITY, ASPECT_RATIO, ic-RESTART_SUB);

  fprintf(stderr, "Reading restart file %s...\n", fname);

  filed = open(fname, O_RDONLY);
  nb = read(filed, (char *) &x[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &y[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &vx[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &vy[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &ax[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &ay[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &bx[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &by[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &cx[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &cy[0], NUMPART*sizeof(double));
  
  nb = read(filed, (char *) &lxwall_offset, sizeof(double));
  nb = read(filed, (char *) &rxwall_offset, sizeof(double));
  
  nb = read(filed, (char *) &r[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &m[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &invm[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &axp[0], NUMPART*sizeof(double));
  nb = read(filed, (char *) &ayp[0], NUMPART*sizeof(double));

  nb = read(filed, (char *) &cell[0], NUMPART*sizeof(int));
  nb = read(filed, (char *) &next[0], NUMPART*sizeof(int));
  nb = read(filed, (char *) &prev[0], NUMPART*sizeof(int));
  nb = read(filed, (char *) &numincell[0], NUMCELL*sizeof(int));
  nb = read(filed, (char *) &firstincell[0], NUMCELL*sizeof(int));

  for (p = 0 ; p < NUMPART; p++)
    press[p] = 1.0;
  pressave = 1.0;
  
  fprintf(stderr, "done reading\n");

  close(filed);
}
