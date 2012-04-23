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
	${OBJECTDIR}/LookEvent.o \
	${OBJECTDIR}/Rover.o \
	${OBJECTDIR}/Tile.o \
	${OBJECTDIR}/GetCommandEvent.o \
	${OBJECTDIR}/Thing.o \
	${OBJECTDIR}/Engine.o \
	${OBJECTDIR}/ThingFactory.o \
	${OBJECTDIR}/Result.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/model.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/model.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/model ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Logger.o: nbproject/Makefile-${CND_CONF}.mk Logger.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Logger.o Logger.C

${OBJECTDIR}/LookEvent.o: nbproject/Makefile-${CND_CONF}.mk LookEvent.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/LookEvent.o LookEvent.C

${OBJECTDIR}/Rover.o: nbproject/Makefile-${CND_CONF}.mk Rover.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Rover.o Rover.C

${OBJECTDIR}/Tile.o: nbproject/Makefile-${CND_CONF}.mk Tile.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tile.o Tile.C

${OBJECTDIR}/GetCommandEvent.o: nbproject/Makefile-${CND_CONF}.mk GetCommandEvent.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/GetCommandEvent.o GetCommandEvent.C

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

${OBJECTDIR}/Result.o: nbproject/Makefile-${CND_CONF}.mk Result.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Result.o Result.C

${OBJECTDIR}/RoverInterface.o: nbproject/Makefile-${CND_CONF}.mk RoverInterface.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/RoverInterface.o RoverInterface.C

${OBJECTDIR}/MoveEvent.o: nbproject/Makefile-${CND_CONF}.mk MoveEvent.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/MoveEvent.o MoveEvent.C

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/model.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
