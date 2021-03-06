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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
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
	${OBJECTDIR}/Tile.o \
	${OBJECTDIR}/Rover.o \
	${OBJECTDIR}/Thing.o \
	${OBJECTDIR}/Engine.o \
	${OBJECTDIR}/ThingFactory.o \
	${OBJECTDIR}/RoverInterface.o \
	${OBJECTDIR}/MoveEvent.o\
	${OBJECTDIR}/GetCommandEvent.o\
	${OBJECTDIR}/LookEvent.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmodel.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmodel.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmodel.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmodel.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmodel.a

${OBJECTDIR}/Logger.o: nbproject/Makefile-${CND_CONF}.mk Logger.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Logger.o Logger.C

${OBJECTDIR}/Tile.o: nbproject/Makefile-${CND_CONF}.mk Tile.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tile.o Tile.C

${OBJECTDIR}/Rover.o: nbproject/Makefile-${CND_CONF}.mk Rover.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Rover.o Rover.C

${OBJECTDIR}/Thing.o: nbproject/Makefile-${CND_CONF}.mk Thing.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Thing.o Thing.C

${OBJECTDIR}/Engine.o: nbproject/Makefile-${CND_CONF}.mk Engine.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Engine.o Engine.C

${OBJECTDIR}/ThingFactory.o: nbproject/Makefile-${CND_CONF}.mk ThingFactory.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/ThingFactory.o ThingFactory.C

${OBJECTDIR}/RoverInterface.o: nbproject/Makefile-${CND_CONF}.mk RoverInterface.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/RoverInterface.o RoverInterface.C

${OBJECTDIR}/MoveEvent.o: nbproject/Makefile-${CND_CONF}.mk MoveEvent.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/MoveEvent.o MoveEvent.C

${OBJECTDIR}/GetCommandEvent.o: nbproject/Makefile-${CND_CONF}.mk GetCommandEvent.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/GetCommandEvent.o GetCommandEvent.C

${OBJECTDIR}/LookEvent.o: nbproject/Makefile-${CND_CONF}.mk LookEvent.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/LookEvent.o LookEvent.C

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmodel.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
