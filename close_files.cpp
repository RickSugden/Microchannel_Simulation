
#include "common.h"

void close_files()
{

#if (PRINT_WB)
  fclose(wbfile);
#endif

#if (PRINT_EVT)
  fclose(evtfile);
#endif

#if (PRINT_FVT)
  fclose(pvtfile);
  //  fclose(psvtfile);
#endif

}
