# Makefile generated by imake - do not edit!

#  Note that the LAB-Imake.tmpl file includes the LAB.cf file at this
#  point and that LAB-Imake.tmpl continues after this included file with
#  more defines.

SPARC = sparc

POWERPC = powerpc

I386 = i386

I586 = i586

I386MAC = i386mac

X86_64 = x86_64

X86_64 = x86_64mac

I486XENO = i486xeno

X86_64XENO = x86_64xeno

MY_BINDIR     =  $(PROG_ROOT)/bin
MY_INCLUDES   =  $(PROG_ROOT)/include
MY_LIBDIR     =  $(PROG_ROOT)/lib

MYBINDIR      =  $(MY_BINDIR)
MYINCLUDEPATH =  $(MY_INCLUDES)
MYLIBDIR      =  $(MY_LIBDIR)

DOCUMENTATIONDIR = doc

LAB             =   CLMC
LAB_BINDIR      =   $(LAB_ROOT)/bin
LAB_INCLUDES    =  -I$(LAB_ROOT)/include
LAB_LIBDIR      =  -L$(LAB_ROOT)/lib/$(MACHTYPE)

CLGROOT         =   $(LAB_ROOT)
CLGBINDIR       =   $(LAB_BINDIR)
CLGINCLUDEPATH  =   $(LAB_INCLUDES)
CLGLIBDIR       =   $(LAB_LIBDIR)

VXPROCS         =   ../2700  ../2400

MATLAB_SUFFIX   =  mexglx
MATLAB_ARCH     =  glnx86

MATLAB_ROOT     =   /usr/local/matlab
MATLAB_INCLUDES =  -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include
MATLAB_LIBDIR   =  -L$(MATLAB_ROOT)/bin/$(MATLAB_ARCH)

CROSSMACHTYPE   =   $(SPARC)

LDOGHOST        =  argus

XENOMAI_ROOT    = /usr/xenomai

SARCOS_MASTER_HOST = xenomai
SARCOS_SLAVE_HOST  = xenomai
SARCOS_PRIMUS_HOST = xenomai

ARM_HOST = mandy

HERMES_HOST = hermes

#  The LAB-Imake.tmpl file resumes at this point.

              DOC = doxygen
            IMAKE = imake -D$(MACHTYPE)
               AR = ar cq
               CC = gcc
             CCPP = g++
            C40AR = ar30 -r
            C40CC = cl30
             VXAR = ar68k -r
             VXCC = cc68k
            PPCAR = arppc -r
            PPCCC = ccppc
            M332AR = 332ar -r
            M332CC = cc68k
              CPP = /lib/cpp
             YACC = /usr/bin/yacc
              LEX = /usr/bin/lex
          INSTALL = install
               LD = ld
             VXLD = ld68k
            PPCLD = ldppc
           M332LD = 332ld
             MAKE = make
               MV = mv
               CP = cp
           RANLIB = ranlib
               RM = rm -f
             TAGS = etags
               AS = as
              CAT = cat
            MKDIR = mkdir -p
           DEPEND = makedepend

    INSTDISTFLAGS = -m 0664
     INSTOBJFLAGS = -m 0755
     INSTBINFLAGS = -m 0755
     INSTLIBFLAGS = -m 0664
     INSTMANFLAGS = -m 0444
     INSTDATFLAGS = -m 0444
  INSTHEADERFLAGS = -m 0444
     INSTDOCFLAGS = -m 0444
  RANLIBINSTFLAGS =

  NORMAL_CC_FLAGS = -D$(MACHTYPE) -D$(LAB) -DUNIX -Wall -Wno-unused -Wno-strict-aliasing -Wno-write-strings -march=native -mtune=native

    ANSI_CC_FLAGS = -ansi -pedantic -Wtrigraphs
   DEBUG_CC_FLAGS = -g
OPTIMIZE_CC_FLAGS = -O3  -ffast-math -funit-at-a-time
  MATLAB_CC_FLAGS = -DMATLAB_MEX_FILE -fPIC -D_GNU_SOURCE -pthread
    LINT_CC_FLAGS = -Wall -Wimplicit -Wreturn-type -Wunused -Wswitch 			-Wcomment -Wshadow -Wid-clash-31 -Wpointer-arith 			-Wcast-qual

  C40_NORMAL_CC_FLAGS = -x -v40 -mf -c -Dc40 -eo.o
   C40_OPTIMIZE_FLAGS = -o
   VX_NORMAL_CC_FLAGS = -D$(LAB) -DVX $(VX_NORMAL_INCLUDES)/h -fvolatile -W
 M332_NORMAL_CC_FLAGS = -mnobitfield -freg-struct-return -nostdinc -nostdlib -Wall -Wno-unused $(M332_NORMAL_INCLUDES)
  PPC_NORMAL_CC_FLAGS = -fno-builtin -fno-for-scope -nostdinc -D_GNU_TOOL -c -D$(LAB) -DVX $(PPC_NORMAL_INCLUDES) -Wall -Wno-unused
    VX_68040_CC_FLAGS = -DCPU=MC68040 -m68040
    VX_68020_CC_FLAGS = -mc68020 -m68881
        M332_CC_FLAGS = -mc68020 -DM332
    PPC_2400_CC_FLAGS = -DCPU=PPC604  -DMV2400
    PPC_2600_CC_FLAGS = -DCPU=PPC604  -DMV2600
    PPC_2700_CC_FLAGS = -DCPU=PPC604  -DMV2700
    VX_OPTIMIZE_FLAGS = -O2
   PPC_OPTIMIZE_FLAGS = -O2

 M322_NORMAL_INCLUDES = M322NormalIncludes
   VX_NORMAL_INCLUDES = -I$(VX_VW_BASE)/h
  PPC_NORMAL_INCLUDES = -I$(WIND_BASE)/target/h

   LDCOMBINEFLAGS = -X -r

      SYS_LDFLAGS = -L/sw/lib -L/usr/X11/lib -L/opt/local/lib $(SYS_LIBDIR)

      LAB_LDFLAGS =  $(LAB_LIBDIR)
   MATLAB_LDFLAGS = -pthread -shared -Wl,--version-script,$(MATLAB_ROOT)/extern/lib/glnx86/mexFunction.map $(MATLAB_LIBDIR)
    LAB_VXLDFLAGS =  $(LAB_VXLIBDIR)
     PROJ_LDFLAGS =  $(PROJ_LIBDIR)
     PROJ_VXLDFLAGS =  $(PROJ_VXLIBDIR)

      LAB_DEFINES =
     PROJ_DEFINES =
    IMAKE_DEFINES = -TLAB_Imake.tmpl
DIRECTORY_DEFINES =

    PROJ_IMAKEDIR = $(LAB_ROOT)/config
     LAB_IMAKEDIR = $(LAB_ROOT)/config

    SYS_LIBRARIES = -lpthread -lrt -lreadline -lcurses
    LAB_LIBRARIES =
   PROJ_LIBRARIES =
 OPENGL_LIBRARIES = -lglut -lGL -lGLU -lX11 -lXmu
 MATLAB_LIBRARIES = -L$(MATLAB_ROOT)/bin/$(MATLAB_ARCH) -lmx -lmex -lmat -lm
     SYS_INCLUDES =
   COMM_LIBRARIES = -lnsl

      ALLINCLUDES = $(INCLUDES) $(PROJ_INCLUDES) $(LAB_INCLUDES) $(SYS_INCLUDES)
       ALLDEFINES = $(DEFINES) $(DIRECTORY_DEFINES) $(PROJ_DEFINES) 			$(LAB_DEFINES) $(ALLINCLUDES)

       ALLLDFLAGS = $(LDFLAGS) $(PROJ_LDFLAGS) $(LAB_LDFLAGS) $(SYS_LDFLAGS)
     ALLVXLDFLAGS = $(LDFLAGS) $(PROJ_VXLDFLAGS) $(LAB_VXLDFLAGS) $(SYS_LDFLAGS)
     ALLLIBRARIES = $(LIBRARIES) $(PROJ_LIBRARIES) $(LAB_LIBRARIES) 			$(SYS_LIBRARIES)

        CPP_FLAGS = $(ALLDEFINES)
    DEPENDDEFINES =
 GCCDEPENDDEFINES = -MD -MP -MF $*.d

        IMAKE_CMD = $(IMAKE) -I$(PROJ_IMAKEDIR) $(IMAKE_DEFINES) $(DIRECTORY_DEFINES)
           RM_CMD = find . \( -name "*.CKP" -or -name "*.ln" -or -name "*.BAK" -or -name "*.bak" -or -name "*.o" -or -name "*.d" -or -name "core" -or -name "errs" -or -name ",*" -or -name "*~" -or -name "*.a" -or -name ".emacs_*" -or -name "TAGS" -or -name "make.log" -or -name "MakeOut" -or -name "*.68k" -or -name "*.ppc" -or -name "*.x40" -or -name "*.map" \) -exec rm {} \;

             ARCH = `arch`

#  $RCSfile: CED-Imake.rules,v $
#  $Revision: 1.19 $
#  $Author: bryant $, $State: Exp $, $Locker: bryant $
#  Program : All programs at the CED.
#  Project : All projects at the CED.

#  Imake rules for generating programs and libraries.
#  These rules are specific to the Center for Engineering Design

#  This is the beginning of the Imakefile produced makefile.
#  The header information below identifies the Imakefile and
#  version of this particular makefile.

INCLUDES               = -I../src -I../include -I$(MY_INCLUDES)                           -I$(SARCOSDTSHOME)/include -I../math                          -I/usr/local/glut/include

CFLAGS                 = $(OPTIMIZE_CC_FLAGS) $(INCLUDES) -D$(MACHTYPE)
SRCDIR                 = ../src
LIBDIR                 = $(MY_LIBDIR)/$(MACHTYPE)
HEADERDIR              = $(MY_INCLUDES)
LIBRARIES              = -L$(MY_LIBDIR)/$(MACHTYPE)
BINDIR                 = $(MY_BINDIR)/$(MACHTYPE)

OBJS_SL_COMMON = 	SL_common.o 	SL_collect_data.o 	SL_vx2unix_wrappers.o 	SL_shared_memory.o 	SL_filters.o 	SL_unix_common.o 	SL_terrains.o 	SL_oscilloscope.o 	SL_man.o

SRCS_SL_COMMON = 	SL_common.c 	SL_collect_data.c 	SL_vx2unix_wrappers.c 	SL_shared_memory.c 	SL_filters.c 	SL_unix_common.c 	SL_terrains.c 	SL_oscilloscope.c 	SL_man.c

OBJS_MOTOR_SERVO = 	SL_controller.o 	SL_motor_servo.o 	SL_motor_servo_unix.o 	SL_sensor_proc.o

SRCS_MOTOR_SERVO = 	SL_controller.c 	SL_motor_servo.c 	SL_motor_servo_unix.c 	SL_sensor_proc.c

OBJS_TASK_SERVO = 	SL_tasks.o 	SL_task_servo.o 	SL_task_servo_unix.o 	SL_goto_task.o 	SL_sine_task.o 	SL_go_cart_task.o 	SL_objects.o 	SL_traj_task.o

SRCS_TASK_SERVO = 	SL_tasks.c 	SL_task_servo.c 	SL_task_servo_unix.c 	SL_goto_task.c 	SL_sine_task.c 	SL_go_cart_task.c 	SL_objects.c 	SL_traj_task.c

OBJS_SIM_SERVO = 	SL_simulation_servo.o 	SL_simulation_servo_unix.o 	SL_userSimulation.o 	SL_objects.o 	SL_integrate.o

SRCS_SIM_SERVO = 	SL_simulation_servo.c 	SL_simulation_servo_unix.c 	SL_userSimulation.c 	SL_objects.c         SL_integrate.c

OBJS_GL_SERVO = 	SL_openGL_servo.o 	SL_openGL_servo_unix.o 	SL_openGL.o 	SL_openGL_oscilloscope.o 	SL_objects.o 	SL_userGraphics.o

SRCS_GL_SERVO = 	SL_openGL_servo.c 	SL_openGL_servo_unix.c 	SL_openGL.c 	SL_openGL_oscilloscope.c 	SL_objects.c 	SL_userGraphics.c

OBJS_VISION_SERVO = 	SL_vision_servo.o 	SL_vision_servo_unix.o 	SL_dbvision.o 	SL_serial_unix.o 	SL_vision_proc.o

SRCS_VISION_SERVO = 	SL_vision_servo.c 	SL_vision_servo_unix.c 	SL_dbvision.c 	SL_serial_unix.c 	SL_vision_proc.c

OBJS_ROS_SERVO = 	SL_ros_servo.o 	SL_ros_servo_unix.o 	SL_ros_communicator.o

SRCS_ROS_SERVO = 	SL_ros_servo.cpp 	SL_ros_servo_unix.cpp 	SL_ros_communicator.cpp

ROS_PACKAGES = roscpp sensor_msgs geometry_msgs

SOURCES = $(SRCS_SL_COMMON) $(SRCS_TASK_SERVO) $(SRCS_MOTOR_SERVO) $(SRCS_SIM_SERVO) $(SRCS_GL_SERVO) $(SRCS_VISION_SERVO)

OBJECTS = $(OBJS_SL_COMMON) $(OBJS_TASK_SERVO) $(OBJS_MOTOR_SERVO) $(OBJS_SIM_SERVO) $(OBJS_GL_SERVO) $(OBJS_VISION_SERVO)

ROS_SOURCES = $(SRCS_ROS_SERVO)
ROS_OBJECTS = $(OBJS_ROS_SERVO)

all:: $(addsuffix .a, $(addprefix lib, SLcommon))

$(addsuffix .a, $(addprefix lib, SLcommon)): $(OBJS_SL_COMMON)
	$(RM) $@
	$(AR) $@ $(OBJS_SL_COMMON)
	$(RANLIB) $@

install:: $(addsuffix .a, $(addprefix lib, SLcommon))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib, SLcommon)) $(LIBDIR)
	$(RANLIB) $(RANLIBINSTFLAGS) $(addsuffix .a, $(addprefix $(LIBDIR)/lib, SLcommon))

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)), SLcommon))

all:: $(addsuffix .a, $(addprefix lib, SLtask))

$(addsuffix .a, $(addprefix lib, SLtask)): $(OBJS_TASK_SERVO)
	$(RM) $@
	$(AR) $@ $(OBJS_TASK_SERVO)
	$(RANLIB) $@

install:: $(addsuffix .a, $(addprefix lib, SLtask))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib, SLtask)) $(LIBDIR)
	$(RANLIB) $(RANLIBINSTFLAGS) $(addsuffix .a, $(addprefix $(LIBDIR)/lib, SLtask))

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)), SLtask))

all:: $(addsuffix .a, $(addprefix lib, SLmotor))

$(addsuffix .a, $(addprefix lib, SLmotor)): $(OBJS_MOTOR_SERVO)
	$(RM) $@
	$(AR) $@ $(OBJS_MOTOR_SERVO)
	$(RANLIB) $@

install:: $(addsuffix .a, $(addprefix lib, SLmotor))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib, SLmotor)) $(LIBDIR)
	$(RANLIB) $(RANLIBINSTFLAGS) $(addsuffix .a, $(addprefix $(LIBDIR)/lib, SLmotor))

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)), SLmotor))

all:: $(addsuffix .a, $(addprefix lib, SLsimulation))

$(addsuffix .a, $(addprefix lib, SLsimulation)): $(OBJS_SIM_SERVO)
	$(RM) $@
	$(AR) $@ $(OBJS_SIM_SERVO)
	$(RANLIB) $@

install:: $(addsuffix .a, $(addprefix lib, SLsimulation))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib, SLsimulation)) $(LIBDIR)
	$(RANLIB) $(RANLIBINSTFLAGS) $(addsuffix .a, $(addprefix $(LIBDIR)/lib, SLsimulation))

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)), SLsimulation))

all:: $(addsuffix .a, $(addprefix lib, SLopenGL))

$(addsuffix .a, $(addprefix lib, SLopenGL)): $(OBJS_GL_SERVO)
	$(RM) $@
	$(AR) $@ $(OBJS_GL_SERVO)
	$(RANLIB) $@

install:: $(addsuffix .a, $(addprefix lib, SLopenGL))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib, SLopenGL)) $(LIBDIR)
	$(RANLIB) $(RANLIBINSTFLAGS) $(addsuffix .a, $(addprefix $(LIBDIR)/lib, SLopenGL))

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)), SLopenGL))

all:: $(addsuffix .a, $(addprefix lib, SLvision))

$(addsuffix .a, $(addprefix lib, SLvision)): $(OBJS_VISION_SERVO)
	$(RM) $@
	$(AR) $@ $(OBJS_VISION_SERVO)
	$(RANLIB) $@

install:: $(addsuffix .a, $(addprefix lib, SLvision))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib, SLvision)) $(LIBDIR)
	$(RANLIB) $(RANLIBINSTFLAGS) $(addsuffix .a, $(addprefix $(LIBDIR)/lib, SLvision))

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)), SLvision))

ifdef ROS_ROOT

all:: $(addsuffix .a, $(addprefix lib, SLros))

$(addsuffix .a, $(addprefix lib, SLros)): $(OBJS_ROS_SERVO)
	$(RM) $@
	$(AR) $@ $(OBJS_ROS_SERVO)
	$(RANLIB) $@

install:: $(addsuffix .a, $(addprefix lib, SLros))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib, SLros)) $(LIBDIR)
	$(RANLIB) $(RANLIBINSTFLAGS) $(addsuffix .a, $(addprefix $(LIBDIR)/lib, SLros))

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)), SLros))

endif

$(sort   $(OBJECTS) ): %.o: $(SRCDIR)/%.c
	$(RM) $@
	$(info * $*.c)
	mkdir -p $(dir $*.c)
	$(CC) $(GCCDEPENDDEFINES) -o $*.o -c $(ALLINCLUDES) $(CFLAGS) $(NORMAL_CC_FLAGS)   $(PROFILING) $(SRCDIR)/$*.c

-include $(addsuffix .d, $(basename   $(OBJECTS) ))

ifdef ROS_ROOT

$(sort  $(ROS_OBJECTS)): %.o: $(SRCDIR)/%.cpp
	$(RM) $@
	$(info * $*.cpp)
	mkdir -p $(dir $*.cpp)
	$(CCPP) $(GCCDEPENDDEFINES) -o $*.o -Wall -Wredundant-decls -c $(ALLINCLUDES) $(CFLAGS) $(NORMAL_CC_FLAGS) $(addprefix -I, $(shell for i in $(ROS_PACKAGES)  ; do rospack cflags-only-I $$i; done)) $(PROFILING) $(SRCDIR)/$*.cpp

-include $(addsuffix .d, $(basename  $(ROS_OBJECTS)))

endif

#
#  These rules are common to all makefiles and SHOULD NOT BE EDITTED.
#

emptyrule::

clean::
	if [ $(notdir $(PWD)) = $(MACHTYPE) ]; then \
	   $(RM_CMD); \
	elif [ $(notdir $(PWD)) = "src" ]; then \
	   $(RM_CMD); \
	else \
	   $(RM) *.CKP *.ln *.BAK *.bak *.o core errs ,* *~ *.a .emacs_* TAGS make.log MakeOut *.68k *.ppc *.x40 *.map; \
	fi

Makefile:: Imakefile $(LAB_IMAKEDIR)/LAB.cf $(LAB_IMAKEDIR)/LAB_Imake.tmpl $(LAB_IMAKEDIR)/LAB_Imake.rules
	-@if [ -f Makefile ]; then \
		$(RM) Makefile.bak; $(MV) Makefile Makefile.bak; \
	else \
	exit 0; \
	fi
	$(IMAKE_CMD)
	@echo "Makefile in `pwd` has been updated."

header::
	@echo "Distribution of headers complete in `pwd`."

#
#  Empty rules for directories that have no subdirectory lists.
#

install::
	@echo "Install of program/library from `pwd` complete."

install.man::
	@echo "Install manual page from `pwd` complete."

install.doc::
	@echo "Install doc page from `pwd` complete."

doc::
	@echo "Documentation in `pwd` complete."

clean::
	@echo "Clean of `pwd` complete."

distclean::
	@echo "Clean of distribution from `pwd` complete."

tag::
	@echo "Tags of `pwd` complete."

Makefiles::
	@echo "Makefiles under `pwd` are up to date."

depend::
	@echo "Dependencies in `pwd` complete."

all::
	@echo "Make all in `pwd` complete."

headers::
	@echo "Headers installed in `pwd`."

#
#  Dependencies generated by makedepend.
#

