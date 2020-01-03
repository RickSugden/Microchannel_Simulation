#include "common.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>



void write_restart(int t)
{
  int framenum;
  char fname[72];
  int filed;
  long nb;

  if (t == 0)
    sprintf(fname, "restart/d%.4f/a%.2f/%4.4i.start", DENSITY, ASPECT_RATIO, ic);

  //if (t ==3)
  //  sprintf(fname, "restart/d%.4f/a%.2f/%4.4i.frame", DENSITY, ASPECT_RATIO, ic);

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
  //

  //the remainder of this file is added by Rick. it is trying to get the 
  //data to be written in an intelligble way

  //not really sure why these are here yet, the file paramas write had it though
  char filename[72];
  FILE *pfile;
  
  

  if(t==1||t==0)
    sprintf(filename, "data_output %d",ic); // this saves fname as "data output"
  if(t>=100)
    framenum = t-100;
    sprintf(filename, "big_output %d %d",ic, framenum); // this saves fname as "data output"
    
  pfile = fopen(filename, "w"); //creates a file in the current directory by the name fo fname, the mode is "a" this means apppend. 
  //it will just add data to the end if it already exists

for (int i = 0; i<(NUMPART-1); i++)
  { 
  //fprintf(pfile, "in the form: ");
  //fprintf(pfile, "x y vx ax ay bx by cx cy lxwall_offset rxwall_offset r m invm axp ayp cell next numincell firstincell");
  fprintf(pfile, "%g\t %g\t %g\t %g\t %g\t %g\t %g\t %g\t %g\t %g\t %g\t%g\t %g\t %g\t %g\t %g\t %g\t %d\t%d\t %d\t %d\t %g\t %g\t\n ", x[i],y[i],vx[i],vy[i],ax[i],ay[i],bx[i],by[i],cx[i],cy[i], lxwall_offset, rxwall_offset, r[i],m[i],invm[i],axp[i],ayp[i],cell[i],next[i],numincell[i],firstincell[i],stressxx[i],stressxy[i]); //this writes "x[0]" then tab then whatever the value of x[0] is then nextline
  //  use the &as a pointer to the first number then find a way to get it to output the rest of them
  
  //x y
  // fprintf(pfile, "vx[0] \t%g\t", vx[i]);
  // fprintf(pfile, "vy[0] \t%g\t", vy[i]);
  // fprintf(pfile, "ax[0] \t%g\t", ax[i]);
  // fprintf(pfile, "ay[0] \t%g\n", ay[i]);
  // fprintf(pfile, "bx[0] \t%g\n", bx[i]);
  // fprintf(pfile, "by[0] \t%g\n", by[i]);
  // fprintf(pfile, "cx[0] \t%g\n", cx[i]);
  // fprintf(pfile, "cy[0] \t%g\n", cy[i]);

  // fprintf(pfile, "lxwall_offset[0] \t%g\n", lxwall_offset);
  // fprintf(pfile, "rxwall_offset[0] \t%g\n", rxwall_offset);
  // fprintf(pfile, "r[0] \t%g\n", r[i]);
  // fprintf(pfile, "m[0] \t%g\n", m[i]);
  // fprintf(pfile, "invm[0] \t%g\n", invm[i]);
  // fprintf(pfile, "axp[0] \t%g\n", axp[i]);
  // fprintf(pfile, "ayp[0] \t%g\n", ayp[i]);

  // fprintf(pfile, "cell[0] \t%g\n", cell[i]);
  // fprintf(pfile, "next[0] \t%g\n", next[i]);
  // fprintf(pfile, "numincell[0] \t%g\n", numincell[i]);
  // fprintf(pfile, "firstincell[0] \t%g\n", firstincell[i]);
  
  }
  fclose(pfile);
}
