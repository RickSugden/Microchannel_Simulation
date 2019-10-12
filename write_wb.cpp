
#include "common.h"

void write_wb(int tstep)
{
  //  fprintf(wbfile, "%.7f %7.5g\n", tstep*dt*tscale, wbforce * mscale * xscale * invtscale * invtscale);
  fprintf(wbfile, "%7.5g\n", wbforce * mscale * xscale * invtscale * invtscale);
}
