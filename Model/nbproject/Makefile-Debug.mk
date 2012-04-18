#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran
AS=as.exe

# Macros
CND_PLATFORM=Cygwin-Windows
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Logger.o \
	${OBJECTDIR}/Rover.o \
	${OBJECTDIR}/Tile.o \
	${OBJECTDIR}/Thing.o \
	${OBJECTDIR}/Engine.o \
	${OBJECTDIR}/ThingFactory.o \
	${OBJECTDIR}/RoverInterface.o \
	${OBJECTDIR}/MoveEvent.o


# C Compiler Flags
CFLAGS=-lpthread

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lpthread -lglib-2.0

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libModel.dll

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libModel.dll: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -mno-cygwin -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libModel.dll ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Logger.o: Logger.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Logger.o Logger.C

${OBJECTDIR}/Rover.o: Rover.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Rover.o Rover.C

${OBJECTDIR}/Tile.o: Tile.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tile.o Tile.C

${OBJECTDIR}/Thing.o: Thing.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Thing.o Thing.C

${OBJECTDIR}/Engine.o: Engine.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Engine.o Engine.C

${OBJECTDIR}/ThingFactory.o: ThingFactory.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ThingFactory.o ThingFactory.C

${OBJECTDIR}/RoverInterface.o: RoverInterface.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude  -MMD -MP -MF $@.d -o ${OBJECTDIR}/RoverInterface.o RoverInterface.C

${OBJECTDIR}/MoveEvent.o: MoveEvent.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude  -MMD -MP -MF $@.d -o ${OBJECTDIR}/MoveEvent.o MoveEvent.C

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libModel.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
