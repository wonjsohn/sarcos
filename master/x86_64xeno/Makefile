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

MATLAB_ROOT     =   /usr/local/matlab
MATLAB_INCLUDES =  -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include
MATLAB_LIBDIR   =  -L$(MATLAB_ROOT)/bin/$(MATLAB_ARCH)

CROSSMACHTYPE   =   $(SPARC)

LDOGHOST        =  argus

XENOMAI_ROOT    = /usr/xenomai

SARCOS_MASTER_HOST = xenomai
SARCOS_SLAVE_HOST  = xenomai
SARCOS_PRIMUS_HOST = pechstein

ARM_HOST = mandy

HERMES_HOST = hermes

LBR4_HOST = pechstein

APOLLO_HOST = pechstein

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
  NORMAL_CCPP_FLAGS = -D$(MACHTYPE) -D$(LAB) -DUNIX -Wall -Wno-unused -Wno-strict-aliasing -Wno-write-strings -march=native -mtune=native

  NORMAL_CC_FLAGS = -D$(MACHTYPE) -D$(LAB) -DUNIX -Wall -Wno-unused -Wno-strict-aliasing -Wno-write-strings -m64 -march=native -mtune=native -fPIC
  NORMAL_CCPP_FLAGS = -D$(MACHTYPE) -D$(LAB) -DUNIX -Wall -Wno-unused -Wno-strict-aliasing -Wno-write-strings -m64 -march=native -mtune=native -fPIC

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

      SYS_LDFLAGS = -L/usr/X11/lib64 -L/usr/X11/lib $(SYS_LIBDIR)

      LAB_LDFLAGS =  $(LAB_LIBDIR)
   MATLAB_LDFLAGS = MatlabLdFlags $(MATLAB_LIBDIR)
    LAB_VXLDFLAGS =  $(LAB_VXLIBDIR)
     PROJ_LDFLAGS =  $(PROJ_LIBDIR)
     PROJ_VXLDFLAGS =  $(PROJ_VXLIBDIR)

      LAB_DEFINES =
     PROJ_DEFINES =
    IMAKE_DEFINES = -TLAB_Imake.tmpl
DIRECTORY_DEFINES =

    PROJ_IMAKEDIR = $(LAB_ROOT)/config
     LAB_IMAKEDIR = $(LAB_ROOT)/config

    SYS_LIBRARIES = $(shell $(XENOMAI_ROOT)/bin/xeno-config --skin=native --ldflags) -lnative -lrtdk -lanalogy -lrtdm -ledit -lcurses
    LAB_LIBRARIES =
   PROJ_LIBRARIES =
 OPENGL_LIBRARIES = -lglut -lGL -lGLU -lX11 -lXmu
 MATLAB_LIBRARIES = -L$(MATLAB_ROOT)/bin/$(MATLAB_ARCH) -lmx -lmex -lmat -lm
     SYS_INCLUDES = $(shell $(XENOMAI_ROOT)/bin/xeno-config --skin=native --cflags)
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

INCLUDES               = -I../src                          -I../include                          -I../math 			 -I$(MY_INCLUDES) 			 -I$(SARCOSDTSHOME)/include 			 -I$(LAB_ROOT)/include/DextArm 			 -I/usr/X11/include                          -I/usr/local/glut/include

CFLAGS                 = $(OPTIMIZE_CC_FLAGS) $(INCLUDES) -D$(MACHTYPE)
SRCDIR                 = ../src
LDFLAGS                = $(LAB_LIBDIR)
LIBDIR                 = $(MYLIBDIR)/$(MACHTYPE)
HEADERDIR              = $(MYINCLUDEPATH)
LIBRARIES              =
BINDIR                 = .

SRCS_COMMON  = 	SL_user_commands.c 	SL_user_common.c 	SL_kinematics.c 	SL_dynamics.c 	SL_invDynNE.c 	SL_invDynArt.c 	SL_forDynComp.c 	SL_forDynArt.c

OBJS_COMMON  = 	SL_user_commands.o 	SL_user_common.o 	SL_kinematics.o 	SL_dynamics.o 	SL_invDynNE.o 	SL_invDynArt.o 	SL_forDynComp.o 	SL_forDynArt.o

SRCS_XMASTER = 	SL_main.c 	SL_user_common.c

OBJS_XMASTER = 	SL_main.o 	SL_user_common.o

SRCS_XRMASTER = 	SL_rmain.c 	SL_user_common.c

OBJS_XRMASTER = 	SL_rmain.o 	SL_user_common.o

SRCS_MOTOR = 	SL_user_motor.c 	SL_user_sensor_proc_unix.c

OBJS_MOTOR = 	SL_user_motor.o 	SL_user_sensor_proc_unix.o

SRCS_RMOTOR = 	SL_user_rmotor.c 	SL_user_sensor_proc_xeno.c 	ajc.c 	ajc_change_register.c 	ni6259_interface.c

OBJS_RMOTOR = 	SL_user_rmotor.o 	SL_user_sensor_proc_xeno.o 	ajc.o 	ajc_change_register.o 	ni6259_interface.o

SRCS_VISION = 	SL_user_vision.c

OBJS_VISION = 	SL_user_vision.o

SRCS_RVISION = 	SL_user_rvision.c 	ni6259_interface.c

OBJS_RVISION = 	SL_user_rvision.o 	ni6259_interface.o

SRCS_TASK = 	SL_user_task.c

OBJS_TASK = 	SL_user_task.o

SRCS_RTASK = 	SL_user_rtask.c 	ni6259_interface.c

OBJS_RTASK = 	SL_user_rtask.o 	ni6259_interface.o

LIBS_XMASTER = -lSLcommon -lutility -lX11 -lm

SRCS_XPEST = 	SL_parm_estimate.c $(SRCS_COMMON)

OBJS_XPEST = 	SL_parm_estimate.o $(OBJS_COMMON)

LIBS_XPEST = -lSLcommon -lutility -lm

SOURCES  = $(SRCS_COMMON) $(SRCS_MOTOR) $(SRCS_VISION) SL_parm_estimate.c SL_user_simulation.c SL_user_openGL.c SL_main.c SL_user_task.c

OBJECTS  = $(OBJS_COMMON) $(OBJS_MOTOR) $(OBJS_VISION) SL_parm_estimate.o SL_user_simulation.o SL_user_openGL.o SL_main.o SL_user_task.o

ifeq ($(HOST),$(SARCOS_MASTER_HOST))
SOURCES += SL_rmain.c $(SRCS_RMOTOR) SL_user_rvision.c SL_user_rtask.c
OBJECTS += SL_rmain.o $(OBJS_RMOTOR) SL_user_rvision.o SL_user_rtask.o
endif

HEADERS =

LIB_MOTOR     = -lSLmotor -lSLcommon -lutility $(COMM_LIBRARIES) -lcurses -lm
LIB_VISION    = -lSLvision -lSLcommon -llwpr -lutility $(COMM_LIBRARIES) -lm

all::
	if [ -f $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_kinematics.c) ] && [ -d  $(SRCDIR) ]; then \
	   if ! cmp -s  $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_kinematics.c) $(addprefix $(addprefix  $(SRCDIR),/),  SL_kinematics.c); then \
		($(INSTALL)  $(INSTBINFLAGS) $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_kinematics.c)  $(SRCDIR) ; \
		echo  SL_kinematics.c " was updated!") ; \
	   fi;	\
	else \
  	   echo "Warning: Cannot keep " SL_kinematics.c" update to date in " $(SRCDIR); \
	fi

all::
	if [ -f $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_dynamics.c) ] && [ -d  $(SRCDIR) ]; then \
	   if ! cmp -s  $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_dynamics.c) $(addprefix $(addprefix  $(SRCDIR),/),  SL_dynamics.c); then \
		($(INSTALL)  $(INSTBINFLAGS) $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_dynamics.c)  $(SRCDIR) ; \
		echo  SL_dynamics.c " was updated!") ; \
	   fi;	\
	else \
  	   echo "Warning: Cannot keep " SL_dynamics.c" update to date in " $(SRCDIR); \
	fi

all::
	if [ -f $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_forDynArt.c) ] && [ -d  $(SRCDIR) ]; then \
	   if ! cmp -s  $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_forDynArt.c) $(addprefix $(addprefix  $(SRCDIR),/),  SL_forDynArt.c); then \
		($(INSTALL)  $(INSTBINFLAGS) $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_forDynArt.c)  $(SRCDIR) ; \
		echo  SL_forDynArt.c " was updated!") ; \
	   fi;	\
	else \
  	   echo "Warning: Cannot keep " SL_forDynArt.c" update to date in " $(SRCDIR); \
	fi

all::
	if [ -f $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_forDynComp.c) ] && [ -d  $(SRCDIR) ]; then \
	   if ! cmp -s  $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_forDynComp.c) $(addprefix $(addprefix  $(SRCDIR),/),  SL_forDynComp.c); then \
		($(INSTALL)  $(INSTBINFLAGS) $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_forDynComp.c)  $(SRCDIR) ; \
		echo  SL_forDynComp.c " was updated!") ; \
	   fi;	\
	else \
  	   echo "Warning: Cannot keep " SL_forDynComp.c" update to date in " $(SRCDIR); \
	fi

all::
	if [ -f $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_invDynNE.c) ] && [ -d  $(SRCDIR) ]; then \
	   if ! cmp -s  $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_invDynNE.c) $(addprefix $(addprefix  $(SRCDIR),/),  SL_invDynNE.c); then \
		($(INSTALL)  $(INSTBINFLAGS) $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_invDynNE.c)  $(SRCDIR) ; \
		echo  SL_invDynNE.c " was updated!") ; \
	   fi;	\
	else \
  	   echo "Warning: Cannot keep " SL_invDynNE.c" update to date in " $(SRCDIR); \
	fi

all::
	if [ -f $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_invDynArt.c) ] && [ -d  $(SRCDIR) ]; then \
	   if ! cmp -s  $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_invDynArt.c) $(addprefix $(addprefix  $(SRCDIR),/),  SL_invDynArt.c); then \
		($(INSTALL)  $(INSTBINFLAGS) $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_invDynArt.c)  $(SRCDIR) ; \
		echo  SL_invDynArt.c " was updated!") ; \
	   fi;	\
	else \
  	   echo "Warning: Cannot keep " SL_invDynArt.c" update to date in " $(SRCDIR); \
	fi

all::
	if [ -f $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_parm_estimate.c) ] && [ -d  $(SRCDIR) ]; then \
	   if ! cmp -s  $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_parm_estimate.c) $(addprefix $(addprefix  $(SRCDIR),/),  SL_parm_estimate.c); then \
		($(INSTALL)  $(INSTBINFLAGS) $(addprefix $(addprefix  $(LAB_ROOT)/SL/src,/),  SL_parm_estimate.c)  $(SRCDIR) ; \
		echo  SL_parm_estimate.c " was updated!") ; \
	   fi;	\
	else \
  	   echo "Warning: Cannot keep " SL_parm_estimate.c" update to date in " $(SRCDIR); \
	fi

all::  xmaster

 xmaster:  $(OBJS_XMASTER)
	$(RM) $@
	$(CC) $(GCCDEPENDDEFINES) -o $@  $(OBJS_XMASTER) $(ALLLDFLAGS)  $(LIBS_XMASTER)  $(ALLLIBRARIES)

install::  xmaster
	if [ ! -d $(BINDIR) ]; then \
		$(MKDIR) $(BINDIR) ; \
	fi
	if cmp -s   xmaster $(addprefix $(addprefix $(BINDIR), /),  xmaster) ; then \
		echo "Source and destination for  xmaster do not differ -- not installed!" ; \
	else	\
		$(INSTALL)  $(INSTBINFLAGS)    xmaster $(BINDIR) ; \
	fi

distclean::
	$(RM) $(addprefix $(addprefix $(BINDIR), /), $(notdir  xmaster))

clean::
	$(RM)  xmaster

all::  xpest

 xpest:  $(OBJS_XPEST)
	$(RM) $@
	$(CC) $(GCCDEPENDDEFINES) -o $@  $(OBJS_XPEST) $(ALLLDFLAGS)  $(LIBS_XPEST)  $(ALLLIBRARIES)

install::  xpest
	if [ ! -d $(BINDIR) ]; then \
		$(MKDIR) $(BINDIR) ; \
	fi
	if cmp -s   xpest $(addprefix $(addprefix $(BINDIR), /),  xpest) ; then \
		echo "Source and destination for  xpest do not differ -- not installed!" ; \
	else	\
		$(INSTALL)  $(INSTBINFLAGS)    xpest $(BINDIR) ; \
	fi

distclean::
	$(RM) $(addprefix $(addprefix $(BINDIR), /), $(notdir  xpest))

clean::
	$(RM)  xpest

all::  xmotor

 xmotor:  $(OBJS_COMMON) $(OBJS_MOTOR)
	$(RM) $@
	$(CC) $(GCCDEPENDDEFINES) -o $@  $(OBJS_COMMON) $(OBJS_MOTOR) $(ALLLDFLAGS)  $(LIB_MOTOR)  $(ALLLIBRARIES)

install::  xmotor
	if [ ! -d $(BINDIR) ]; then \
		$(MKDIR) $(BINDIR) ; \
	fi
	if cmp -s   xmotor $(addprefix $(addprefix $(BINDIR), /),  xmotor) ; then \
		echo "Source and destination for  xmotor do not differ -- not installed!" ; \
	else	\
		$(INSTALL)  $(INSTBINFLAGS)    xmotor $(BINDIR) ; \
	fi

distclean::
	$(RM) $(addprefix $(addprefix $(BINDIR), /), $(notdir  xmotor))

clean::
	$(RM)  xmotor

all::  xvision

 xvision:  $(OBJS_COMMON) $(OBJS_VISION)
	$(RM) $@
	$(CC) $(GCCDEPENDDEFINES) -o $@  $(OBJS_COMMON) $(OBJS_VISION)  $(ALLLDFLAGS)  $(LIB_VISION)  $(ALLLIBRARIES)

install::  xvision
	if [ ! -d $(BINDIR) ]; then \
		$(MKDIR) $(BINDIR) ; \
	fi
	if cmp -s   xvision $(addprefix $(addprefix $(BINDIR), /),  xvision) ; then \
		echo "Source and destination for  xvision do not differ -- not installed!" ; \
	else	\
		$(INSTALL)  $(INSTBINFLAGS)    xvision $(BINDIR) ; \
	fi

distclean::
	$(RM) $(addprefix $(addprefix $(BINDIR), /), $(notdir  xvision))

clean::
	$(RM)  xvision

all:: $(addsuffix .a, $(addprefix lib,  master))

$(addsuffix .a, $(addprefix lib,  master)):  $(OBJS_COMMON)
	$(RM) $@
	$(LD) -r -o $@  $(OBJS_COMMON) $(ALLLDFLAGS)

install:: $(addsuffix .a, $(addprefix lib,  master))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib,  master)) $(LIBDIR)

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)),  master))

all:: $(addsuffix .a, $(addprefix lib,  master_openGL))

$(addsuffix .a, $(addprefix lib,  master_openGL)):  SL_user_openGL.o
	$(RM) $@
	$(LD) -r -o $@  SL_user_openGL.o  $(ALLLDFLAGS)

install:: $(addsuffix .a, $(addprefix lib,  master_openGL))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib,  master_openGL)) $(LIBDIR)

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)),  master_openGL))

all:: $(addsuffix .a, $(addprefix lib,  master_task))

$(addsuffix .a, $(addprefix lib,  master_task)):  $(OBJS_TASK)
	$(RM) $@
	$(LD) -r -o $@  $(OBJS_TASK) $(ALLLDFLAGS)

install:: $(addsuffix .a, $(addprefix lib,  master_task))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib,  master_task)) $(LIBDIR)

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)),  master_task))

all:: $(addsuffix .a, $(addprefix lib,  master_simulation))

$(addsuffix .a, $(addprefix lib,  master_simulation)):  SL_user_simulation.o
	$(RM) $@
	$(LD) -r -o $@  SL_user_simulation.o  $(ALLLDFLAGS)

install:: $(addsuffix .a, $(addprefix lib,  master_simulation))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib,  master_simulation)) $(LIBDIR)

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)),  master_simulation))

ifeq ($(HOST),$(SARCOS_MASTER_HOST))

all::  xrmaster

 xrmaster:  $(OBJS_XRMASTER)
	$(RM) $@
	$(CC) $(GCCDEPENDDEFINES) -o $@  $(OBJS_XRMASTER) $(ALLLDFLAGS)  $(LIBS_XMASTER)  $(ALLLIBRARIES)

install::  xrmaster
	if [ ! -d $(BINDIR) ]; then \
		$(MKDIR) $(BINDIR) ; \
	fi
	if cmp -s   xrmaster $(addprefix $(addprefix $(BINDIR), /),  xrmaster) ; then \
		echo "Source and destination for  xrmaster do not differ -- not installed!" ; \
	else	\
		$(INSTALL)  $(INSTBINFLAGS)    xrmaster $(BINDIR) ; \
	fi

distclean::
	$(RM) $(addprefix $(addprefix $(BINDIR), /), $(notdir  xrmaster))

clean::
	$(RM)  xrmaster

all::  xrmotor

 xrmotor:  $(OBJS_COMMON) $(OBJS_RMOTOR)
	$(RM) $@
	$(CC) $(GCCDEPENDDEFINES) -o $@  $(OBJS_COMMON) $(OBJS_RMOTOR) $(ALLLDFLAGS)  $(LIB_MOTOR)  $(ALLLIBRARIES)

install::  xrmotor
	if [ ! -d $(BINDIR) ]; then \
		$(MKDIR) $(BINDIR) ; \
	fi
	if cmp -s   xrmotor $(addprefix $(addprefix $(BINDIR), /),  xrmotor) ; then \
		echo "Source and destination for  xrmotor do not differ -- not installed!" ; \
	else	\
		$(INSTALL)  $(INSTBINFLAGS)    xrmotor $(BINDIR) ; \
	fi

distclean::
	$(RM) $(addprefix $(addprefix $(BINDIR), /), $(notdir  xrmotor))

clean::
	$(RM)  xrmotor

all::  xrvision

 xrvision:  $(OBJS_COMMON) $(OBJS_RVISION)
	$(RM) $@
	$(CC) $(GCCDEPENDDEFINES) -o $@  $(OBJS_COMMON) $(OBJS_RVISION)  $(ALLLDFLAGS)  $(LIB_VISION)  $(ALLLIBRARIES)

install::  xrvision
	if [ ! -d $(BINDIR) ]; then \
		$(MKDIR) $(BINDIR) ; \
	fi
	if cmp -s   xrvision $(addprefix $(addprefix $(BINDIR), /),  xrvision) ; then \
		echo "Source and destination for  xrvision do not differ -- not installed!" ; \
	else	\
		$(INSTALL)  $(INSTBINFLAGS)    xrvision $(BINDIR) ; \
	fi

distclean::
	$(RM) $(addprefix $(addprefix $(BINDIR), /), $(notdir  xrvision))

clean::
	$(RM)  xrvision

all:: $(addsuffix .a, $(addprefix lib,  rmaster_task))

$(addsuffix .a, $(addprefix lib,  rmaster_task)):  $(OBJS_RTASK)
	$(RM) $@
	$(LD) -r -o $@  $(OBJS_RTASK)  $(ALLLDFLAGS)

install:: $(addsuffix .a, $(addprefix lib,  rmaster_task))
	if [ ! -d $(LIBDIR) ]; then \
		$(MKDIR) $(LIBDIR) ; \
	fi
	$(INSTALL)  $(INSTLIBFLAGS) $(addsuffix .a, $(addprefix lib,  rmaster_task)) $(LIBDIR)

distclean::
	$(RM) $(addsuffix .a, $(addprefix $(addsuffix /lib, $(LIBDIR)),  rmaster_task))

endif

$(sort   $(OBJECTS) ): %.o: $(SRCDIR)/%.c
	$(RM) $@
	$(info * $*.c)
	mkdir -p $(dir $*.c)
	$(CC) $(GCCDEPENDDEFINES) -o $*.o -c $(ALLINCLUDES) $(CFLAGS) $(NORMAL_CC_FLAGS)   $(PROFILING) $(SRCDIR)/$*.c

-include $(addsuffix .d, $(basename   $(OBJECTS) ))

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

