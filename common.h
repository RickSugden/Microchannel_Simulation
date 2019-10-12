
#include "params.h"
#include "protos.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

#ifndef EXT
#define EXT extern
#endif

EXT double r[MAXPART];
EXT double m[MAXPART];
EXT double invm[MAXPART];
EXT double invI[MAXPART];

EXT double x[MAXPART];
EXT double y[MAXPART];

EXT double vx[MAXPART];
EXT double vy[MAXPART];

EXT double ax[MAXPART];
EXT double ay[MAXPART];

EXT double axp[MAXPART];
EXT double ayp[MAXPART];

EXT double bx[MAXPART];
EXT double by[MAXPART];

EXT double cx[MAXPART];
EXT double cy[MAXPART];

EXT double lxwall_offset;
EXT double rxwall_offset;

EXT int cell[MAXPART];

EXT int next[MAXPART];
EXT int prev[MAXPART];

EXT int numincell[MAXCELL];
EXT int firstincell[MAXCELL];

// EXT double magic_force[MAXPART];
EXT double stressxx[MAXPART];
EXT double stressyy[MAXPART];
EXT double stressxy[MAXPART];
EXT double press[MAXPART];
EXT double rad[MAXPART];
EXT double shear[MAXPART];

EXT double wbforce;

EXT int ic;

EXT double xscale, invxscale, mscale, invmscale, tscale, invtscale;
EXT double thermal_time, lxwall_velocity, rxwall_velocity;
EXT double WALLBALLR, WALLBALLSPACING, HALFWBSPACING, INVWBSPACING;
EXT double BIGR, SMALLR;
EXT double LX;
EXT double DISKH, DISKDENSITY;
EXT double G, kn, gamman, gammas;
EXT double dt, invdy, invdx;
EXT double DT2o2, DT3o6, DT4o24;
EXT double PFACTOR, VFACTOR, BFACTOR, CFACTOR;
EXT double WFACTOR, WDDFACTOR, WDDDFACTOR;

EXT int NX, NY, NUMPART, NUMSMALL, NUMBIG;
EXT double DENSITY, TARGETDENSITY, ASPECT_RATIO, SIZERATIO;

EXT double pressave;

EXT FILE *wbfile;
EXT FILE *pvtfile;
//EXT FILE *psvtfile;
EXT FILE *evtfile;

EXT double totpress;

EXT char wbbuff[BIGBUFF];
EXT char pvtbuff[BIGBUFF];
EXT char evtbuff[BIGBUFF];

#undef EXT
