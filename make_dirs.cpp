
#include "common.h"

void make_dirs()
{
  char comname[72];
  char fname[72];

  sprintf(comname, "mkdir params");
  system(comname);
  sprintf(comname, "mkdir params/d%.4f", DENSITY);
  system(comname);
  sprintf(comname, "mkdir params/d%.4f/a%.2f", DENSITY, ASPECT_RATIO);
  system(comname);

#if (PRINT_WB)
  sprintf(comname, "mkdir wbforce");
  system(comname);
  sprintf(comname, "mkdir wbforce/d%.4f", DENSITY);
  system(comname);
  sprintf(comname, "mkdir wbforce/d%.4f/a%.2f", DENSITY, ASPECT_RATIO);
  system(comname);
#endif

#if PRINT_PF
  sprintf(comname, "mkdir pf_out");
  system(comname);
  sprintf(comname, "mkdir pf_out/d%.4f", DENSITY);
  system(comname);
  sprintf(comname, "mkdir pf_out/d%.4f/a%.2f", DENSITY, ASPECT_RATIO);
  system(comname);
  sprintf(comname, "mkdir pf_out/d%.4f/a%.2f/ic%4.4i", DENSITY, ASPECT_RATIO, ic);
  system(comname);

  //sprintf(comname, "mkdir e2_out");
  //system(comname);
  //sprintf(comname, "mkdir e2_out/d%.4f", DENSITY);
  //system(comname);
  //sprintf(comname, "mkdir e2_out/d%.4f/a%.2f", DENSITY, ASPECT_RATIO);
  //system(comname);
  //sprintf(comname, "mkdir e2_out/d%.4f/a%.2f/e2.%4.4i", DENSITY, ASPECT_RATIO, ic);
  //system(comname);
#endif

#if PRINT_FVT
  sprintf(comname, "mkdir pvt");
  system(comname);
  sprintf(comname, "mkdir pvt/d%.4f", DENSITY);
  system(comname);
  sprintf(comname, "mkdir pvt/d%.4f/a%.2f", DENSITY, ASPECT_RATIO);
  system(comname);

  //  sprintf(comname, "mkdir psvt");
  //  system(comname);
  //  sprintf(comname, "mkdir psvt/d%.4f", DENSITY);
  //  system(comname);
  //  sprintf(comname, "mkdir psvt/d%.4f/a%.2f", DENSITY, ASPECT_RATIO);
  //  system(comname);
#endif

#if PRINT_EVT
  sprintf(comname, "mkdir evt");
  system(comname);
  sprintf(comname, "mkdir evt/d%.4f", DENSITY);
  system(comname);
  sprintf(comname, "mkdir evt/d%.4f/a%.2f", DENSITY, ASPECT_RATIO);
  system(comname);
#endif

#if DUMP_DATA
  sprintf(comname, "mkdir dump");
  system(comname);
  sprintf(comname, "mkdir dump/d%.4f", DENSITY);
  system(comname);
  sprintf(comname, "mkdir dump/d%.4f/a%.2f", DENSITY, ASPECT_RATIO);
  system(comname);
  sprintf(comname, "mkdir dump/d%.4f/a%.2f/ic%4.4i", DENSITY, ASPECT_RATIO, ic);
  system(comname);
#endif

#if (WRITE_START || WRITE_END)
  sprintf(comname, "mkdir restart");
  system(comname);
  sprintf(comname, "mkdir restart/d%.4f", DENSITY);
  system(comname);
  sprintf(comname, "mkdir restart/d%.4f/a%.2f", DENSITY, ASPECT_RATIO);
  system(comname);
#endif

}
