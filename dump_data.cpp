#include "common.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>


void dump_data(int t)
{
  char fname[72];
  int filed;
  long nb;

  sprintf(fname, "dump/d%.4f/a%.2f/ic%4.4i/dump.%6.6i", DENSITY, ASPECT_RATIO, ic, t);

  filed = creat(fname, 0755);
  nb = write(filed, (char *) &x[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &y[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &r[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &press[0], NUMPART*sizeof(double));

  close(filed);

}
