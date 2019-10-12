
#include "common.h"

void open_files()
{
  char comname[72];
  char fname[72];

#if (PRINT_WB)
  sprintf(fname, "wbforce/d%.4f/a%.2f/wb.%4.4i", DENSITY, ASPECT_RATIO, ic);
  wbfile = fopen(fname, "w");
  setvbuf(wbfile, wbbuff, _IOFBF, BIGBUFF);
#endif

#if PRINT_FVT
  sprintf(fname, "pvt/d%.4f/a%.2f/pvt.%4.4i", DENSITY, ASPECT_RATIO, ic);
  pvtfile = fopen(fname, "w");
  setvbuf(pvtfile, pvtbuff, _IOFBF, BIGBUFF);

  //  sprintf(fname, "psvt/d%.4f/a%.2f/psvt.%4.4i", DENSITY, ASPECT_RATIO, ic);
  //  psvtfile = fopen(fname, "w");
#endif

#if PRINT_EVT
  sprintf(fname, "evt/d%.4f/a%.2f/evt.%4.4i", DENSITY, ASPECT_RATIO, ic);
  evtfile = fopen(fname, "w");
  setvbuf(evtfile, evtbuff, _IOFBF, BIGBUFF);
#endif
}
