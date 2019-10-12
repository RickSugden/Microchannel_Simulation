#include "common.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>


void write_restart(int t)
{
  char fname[72];
  int filed;
  long nb;

  if (t == 0)
    sprintf(fname, "restart/d%.4f/a%.2f/%4.4i.start", DENSITY, ASPECT_RATIO, ic);
  else
    sprintf(fname, "restart/d%.4f/a%.2f/%4.4i.end", DENSITY, ASPECT_RATIO, ic);

  filed = creat(fname, 0755);
  nb = write(filed, (char *) &x[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &y[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &vx[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &vy[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &ax[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &ay[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &bx[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &by[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &cx[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &cy[0], NUMPART*sizeof(double));
  
  nb = write(filed, (char *) &lxwall_offset, sizeof(double));
  nb = write(filed, (char *) &rxwall_offset, sizeof(double));
  
  nb = write(filed, (char *) &r[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &m[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &invm[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &axp[0], NUMPART*sizeof(double));
  nb = write(filed, (char *) &ayp[0], NUMPART*sizeof(double));

  nb = write(filed, (char *) &cell[0], NUMPART*sizeof(int));
  nb = write(filed, (char *) &next[0], NUMPART*sizeof(int));
  nb = write(filed, (char *) &prev[0], NUMPART*sizeof(int));
  nb = write(filed, (char *) &numincell[0], NUMCELL*sizeof(int));
  nb = write(filed, (char *) &firstincell[0], NUMCELL*sizeof(int));

  close(filed);

  //the remainder of this file is added by Rick. it is trying to get the 
  //data to be written in an intelligble way

  //not really sure why these are here yet, the file paramas write had it though
  char filename[72];
  FILE *pfile;
  
  sprintf(filename, "data output"); // this saves fname as "data output"

  pfile = fopen(filename, "a"); //creates a file in the current directory by the name fo fname, the mode is "a" this means apppend. 
  //it will just add data to the end if it already exists

  fprintf(pfile, "x[0] \t%g\n", x[0]); //this writes "x[0]" then tab then whatever the value of x[0] is then nextline
  fprintf(pfile, "y[0] \t%g\n", y[0]);
  fprintf(pfile, "vx[0] \t%g\n", vx[0]);
  fprintf(pfile, "vy[0] \t%g\n", vy[0]);
  fprintf(pfile, "ax[0] \t%g\n", ax[0]);
  fprintf(pfile, "ay[0] \t%g\n", ay[0]);
  fprintf(pfile, "bx[0] \t%g\n", bx[0]);
  fprintf(pfile, "by[0] \t%g\n", by[0]);
  fprintf(pfile, "cx[0] \t%g\n", cx[0]);
  fprintf(pfile, "cy[0] \t%g\n", cy[0]);

  fclose(pfile);
}
