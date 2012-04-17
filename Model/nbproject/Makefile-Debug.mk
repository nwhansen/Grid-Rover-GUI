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
	${OBJECTDIR}/source/Communication.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/source/StackTile.o \
	${OBJECTDIR}/source/Logger.o \
	${OBJECTDIR}/Engine.o \
	${OBJECTDIR}/source/RoverCommunication.o \
	${OBJECTDIR}/RoverInterface.o \
	${OBJECTDIR}/source/StackEngine.o


# C Compiler Flags
CFLAGS=-m32

# CC Compiler Flags
CCFLAGS=-m32
CXXFLAGS=-m32

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lpthread

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/model.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/model.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/model ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/source/Communication.o: source/Communication.C 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Communication.o source/Communication.C

${OBJECTDIR}/main.o: main.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.C

${OBJECTDIR}/source/StackTile.o: source/StackTile.C 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/StackTile.o source/StackTile.C

${OBJECTDIR}/source/Logger.o: source/Logger.C 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/Logger.o source/Logger.C

${OBJECTDIR}/Engine.o: Engine.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Engine.o Engine.C

${OBJECTDIR}/source/RoverCommunication.o: source/RoverCommunication.C 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/RoverCommunication.o source/RoverCommunication.C

${OBJECTDIR}/RoverInterface.o: RoverInterface.C 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/RoverInterface.o RoverInterface.C

${OBJECTDIR}/source/StackEngine.o: source/StackEngine.C 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/source/StackEngine.o source/StackEngine.C

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
