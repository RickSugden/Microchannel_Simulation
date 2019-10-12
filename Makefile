
# to debug, DEBUG = -g

DEBUG =

# to use the profiler PROFILER = -p

PROFILER =

#to search additional directories for header files INCLUDES = -Idirectory

INCDIRS =

#directories to search for libraries LIBRARIES = -Ldirectory

LIBDIRS =

#libraries to link -llib

LIBS = -lm 
#-framework Accelerate
# -lscs_mp -lmpi
# -lcomplib.sgimath_mp

#add any optimization flags here, eg set "OPTIMIZE = -O"

#OPTIMIZE = -O3 -funroll-loops -fstrict-aliasing -fsched-interblock -falign-loops=16 -falign-jumps=16 -falign-functions=16 -falign-jumps-max-skip=15 -falign-loops-max-skip=15 -malign-power -ffast-math -mdynamic-no-pic -mpowerpc-gpopt -force_cpusubtype_ALL -mtune=7450 -mcpu=7450 -mpowerpc64 -faltivec

OPTIMIZE = -O3
#OPTIMIZE = -fast

#other flags -mp

OTHERS = 
# -DPERIODIC
# -mp -pca

CMFFLAGS = $(OTHERS) $(OPTIMIZE) $(DEBUG) $(PROFILER) $(INCDIRS)

.SUFFIXES: .o .cpp

.cpp.o : 
	clang $(CFLAGS) -c $< 

# list of object files derived from .fcm files

OBJ =\
assign_to_cells.o\
calc_en.o\
compute_force.o\
open_files.o\
close_files.o\
correct.o\
dump_data.o\
f_to_a.o\
get_pressure.o\
get_press_noprint.o\
init_all.o\
init_scaled_params.o\
int_cells.o\
int_cells_yp.o\
int_lxwall.o\
int_rxwall.o\
int_self.o\
int_bottom.o\
interact.o\
interact_lxwall.o\
interact_rxwall.o\
leftballguts.o\
rightballguts.o\
main.o\
make_dirs.o\
move_walls.o\
predict.o\
rebox.o\
output_pf.o\
trans.o\
write_params.o\
write_wb.o\
write_restart.o\
read_restart.o\

# targets.

periodic:
	make runme FC=f77 CC=clang LD=clang\
          'CFLAGS=$(CMFFLAGS) -DPERIODIC' \
          LIB='-lm'


runme: $(OBJ)
	$(LD) -o $@ $(CMFFLAGS) $(OBJ) $(LIBDIRS) $(LIBS)

archive:
	ar uv archive.a $(FILES)	# archive files

clean:
	-rm mon.out core *\.o     # '-'  means to ignore any error code

listing:
	print *.h *.f Makefile


# List of dependencies of included files:

assign_to_cells.o :\
  common.h\
  params.h
calc_en.o :\
  common.h\
  params.h
compute_force.o :\
  common.h\
  params.h
open_files.o :\
  common.h\
  params.h
close_files.o :\
  common.h\
  params.h
correct.o :\
  common.h\
  params.h
dump_data.o :\
  common.h\
  params.h
f_to_a.o :\
  common.h\
  params.h
get_pressure.o :\
  common.h\
  params.h
get_press_noprint.o :\
  common.h\
  params.h
init_all.o :\
  common.h\
  params.h
init_scaled_params.o :\
  common.h\
  params.h
int_cells.o :\
  common.h\
  params.h
int_cells_yp.o :\
  common.h\
  params.h
int_lxwall.o :\
  common.h\
  params.h
int_rxwall.o :\
  common.h\
  params.h
int_self.o :\
  common.h\
  params.h
interact.o :\
  common.h\
  params.h
interact_lxwall.o :\
  common.h\
  params.h
interact_rxwall.o :\
  common.h\
  params.h
leftballguts.o :\
  common.h\
  params.h
rightballguts.o :\
  common.h\
  params.h
main.o :\
  params.h\
  protos.h
make_dirs.o :\
  params.h\
  protos.h
move_walls.o :\
  params.h\
  protos.h
predict.o :\
  common.h\
  params.h
rebox.o :\
  common.h\
  params.h
output_forces.o :\
  common.h\
  params.h
output_pf.o :\
  common.h\
  params.h
write_exp.o :\
  common.h\
  params.h
write_params.o :\
  common.h\
  params.h
write_wb.o :\
  common.h\
  params.h
write_restart.o :\
  common.h\
  params.h
read_restart.o :\
  common.h\
  params.h
trans.o :\
  common.h\
  params.h
