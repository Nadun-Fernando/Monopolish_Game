﻿# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Programming Softwares\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programming Softwares\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\CO2402Assignment.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\CO2402Assignment.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\CO2402Assignment.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\CO2402Assignment.dir\flags.make

CMakeFiles\CO2402Assignment.dir\main.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\main.cpp.obj: ..\main.cpp
CMakeFiles\CO2402Assignment.dir\main.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CO2402Assignment.dir/main.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\main.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\main.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\main.cpp"
<<

CMakeFiles\CO2402Assignment.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/main.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\main.cpp"
<<

CMakeFiles\CO2402Assignment.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/main.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\main.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\main.cpp"
<<

CMakeFiles\CO2402Assignment.dir\CSquare.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\CSquare.cpp.obj: ..\CSquare.cpp
CMakeFiles\CO2402Assignment.dir\CSquare.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CO2402Assignment.dir/CSquare.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\CSquare.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\CSquare.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\CSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\CSquare.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/CSquare.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\CSquare.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\CSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\CSquare.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/CSquare.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\CSquare.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\CSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\Player.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\Player.cpp.obj: ..\Player.cpp
CMakeFiles\CO2402Assignment.dir\Player.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CO2402Assignment.dir/Player.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\Player.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\Player.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\Player.cpp"
<<

CMakeFiles\CO2402Assignment.dir\Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/Player.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\Player.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\Player.cpp"
<<

CMakeFiles\CO2402Assignment.dir\Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/Player.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\Player.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\Player.cpp"
<<

CMakeFiles\CO2402Assignment.dir\Properties.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\Properties.cpp.obj: ..\Properties.cpp
CMakeFiles\CO2402Assignment.dir\Properties.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CO2402Assignment.dir/Properties.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\Properties.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\Properties.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\Properties.cpp"
<<

CMakeFiles\CO2402Assignment.dir\Properties.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/Properties.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\Properties.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\Properties.cpp"
<<

CMakeFiles\CO2402Assignment.dir\Properties.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/Properties.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\Properties.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\Properties.cpp"
<<

CMakeFiles\CO2402Assignment.dir\FileOperations.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\FileOperations.cpp.obj: ..\FileOperations.cpp
CMakeFiles\CO2402Assignment.dir\FileOperations.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CO2402Assignment.dir/FileOperations.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\FileOperations.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\FileOperations.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\FileOperations.cpp"
<<

CMakeFiles\CO2402Assignment.dir\FileOperations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/FileOperations.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\FileOperations.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\FileOperations.cpp"
<<

CMakeFiles\CO2402Assignment.dir\FileOperations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/FileOperations.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\FileOperations.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\FileOperations.cpp"
<<

CMakeFiles\CO2402Assignment.dir\UserInterface.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\UserInterface.cpp.obj: ..\UserInterface.cpp
CMakeFiles\CO2402Assignment.dir\UserInterface.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CO2402Assignment.dir/UserInterface.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\UserInterface.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\UserInterface.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\UserInterface.cpp"
<<

CMakeFiles\CO2402Assignment.dir\UserInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/UserInterface.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\UserInterface.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\UserInterface.cpp"
<<

CMakeFiles\CO2402Assignment.dir\UserInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/UserInterface.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\UserInterface.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\UserInterface.cpp"
<<

CMakeFiles\CO2402Assignment.dir\JailSquare.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\JailSquare.cpp.obj: ..\JailSquare.cpp
CMakeFiles\CO2402Assignment.dir\JailSquare.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CO2402Assignment.dir/JailSquare.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\JailSquare.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\JailSquare.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\JailSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\JailSquare.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/JailSquare.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\JailSquare.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\JailSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\JailSquare.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/JailSquare.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\JailSquare.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\JailSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\GotoJailSquare.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\GotoJailSquare.cpp.obj: ..\GotoJailSquare.cpp
CMakeFiles\CO2402Assignment.dir\GotoJailSquare.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CO2402Assignment.dir/GotoJailSquare.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\GotoJailSquare.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\GotoJailSquare.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\GotoJailSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\GotoJailSquare.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/GotoJailSquare.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\GotoJailSquare.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\GotoJailSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\GotoJailSquare.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/GotoJailSquare.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\GotoJailSquare.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\GotoJailSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\FreeParking.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\FreeParking.cpp.obj: ..\FreeParking.cpp
CMakeFiles\CO2402Assignment.dir\FreeParking.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CO2402Assignment.dir/FreeParking.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\FreeParking.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\FreeParking.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\FreeParking.cpp"
<<

CMakeFiles\CO2402Assignment.dir\FreeParking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/FreeParking.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\FreeParking.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\FreeParking.cpp"
<<

CMakeFiles\CO2402Assignment.dir\FreeParking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/FreeParking.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\FreeParking.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\FreeParking.cpp"
<<

CMakeFiles\CO2402Assignment.dir\Station.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\Station.cpp.obj: ..\Station.cpp
CMakeFiles\CO2402Assignment.dir\Station.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/CO2402Assignment.dir/Station.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\Station.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\Station.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\Station.cpp"
<<

CMakeFiles\CO2402Assignment.dir\Station.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/Station.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\Station.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\Station.cpp"
<<

CMakeFiles\CO2402Assignment.dir\Station.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/Station.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\Station.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\Station.cpp"
<<

CMakeFiles\CO2402Assignment.dir\BonusSquare.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\BonusSquare.cpp.obj: ..\BonusSquare.cpp
CMakeFiles\CO2402Assignment.dir\BonusSquare.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/CO2402Assignment.dir/BonusSquare.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\BonusSquare.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\BonusSquare.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\BonusSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\BonusSquare.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/BonusSquare.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\BonusSquare.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\BonusSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\BonusSquare.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/BonusSquare.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\BonusSquare.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\BonusSquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\PenaltySquare.cpp.obj: CMakeFiles\CO2402Assignment.dir\flags.make
CMakeFiles\CO2402Assignment.dir\PenaltySquare.cpp.obj: ..\PenaltySquare.cpp
CMakeFiles\CO2402Assignment.dir\PenaltySquare.cpp.obj: CMakeFiles\CO2402Assignment.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/CO2402Assignment.dir/PenaltySquare.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\CO2402Assignment.dir\PenaltySquare.cpp.obj.d --working-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\CO2402Assignment.dir\PenaltySquare.cpp.obj /FdCMakeFiles\CO2402Assignment.dir\ /FS -c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\PenaltySquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\PenaltySquare.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CO2402Assignment.dir/PenaltySquare.cpp.i"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" > CMakeFiles\CO2402Assignment.dir\PenaltySquare.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\PenaltySquare.cpp"
<<

CMakeFiles\CO2402Assignment.dir\PenaltySquare.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CO2402Assignment.dir/PenaltySquare.cpp.s"
	"D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CO2402Assignment.dir\PenaltySquare.cpp.s /c "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\PenaltySquare.cpp"
<<

# Object files for target CO2402Assignment
CO2402Assignment_OBJECTS = \
"CMakeFiles\CO2402Assignment.dir\main.cpp.obj" \
"CMakeFiles\CO2402Assignment.dir\CSquare.cpp.obj" \
"CMakeFiles\CO2402Assignment.dir\Player.cpp.obj" \
"CMakeFiles\CO2402Assignment.dir\Properties.cpp.obj" \
"CMakeFiles\CO2402Assignment.dir\FileOperations.cpp.obj" \
"CMakeFiles\CO2402Assignment.dir\UserInterface.cpp.obj" \
"CMakeFiles\CO2402Assignment.dir\JailSquare.cpp.obj" \
"CMakeFiles\CO2402Assignment.dir\GotoJailSquare.cpp.obj" \
"CMakeFiles\CO2402Assignment.dir\FreeParking.cpp.obj" \
"CMakeFiles\CO2402Assignment.dir\Station.cpp.obj" \
"CMakeFiles\CO2402Assignment.dir\BonusSquare.cpp.obj" \
"CMakeFiles\CO2402Assignment.dir\PenaltySquare.cpp.obj"

# External object files for target CO2402Assignment
CO2402Assignment_EXTERNAL_OBJECTS =

CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\main.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\CSquare.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\Player.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\Properties.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\FileOperations.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\UserInterface.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\JailSquare.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\GotoJailSquare.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\FreeParking.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\Station.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\BonusSquare.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\PenaltySquare.cpp.obj
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\build.make
CO2402Assignment.exe: CMakeFiles\CO2402Assignment.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable CO2402Assignment.exe"
	"D:\Programming Softwares\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\CO2402Assignment.dir --rc="D:\Windows Kits\10\bin\10.0.19041.0\x86\rc.exe" --mt="D:\Windows Kits\10\bin\10.0.19041.0\x86\mt.exe" --manifests -- "D:\Programming Softwares\VS\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x86\link.exe" /nologo @CMakeFiles\CO2402Assignment.dir\objects1.rsp @<<
 /out:CO2402Assignment.exe /implib:CO2402Assignment.lib /pdb:"D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CO2402Assignment.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\CO2402Assignment.dir\build: CO2402Assignment.exe
.PHONY : CMakeFiles\CO2402Assignment.dir\build

CMakeFiles\CO2402Assignment.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CO2402Assignment.dir\cmake_clean.cmake
.PHONY : CMakeFiles\CO2402Assignment.dir\clean

CMakeFiles\CO2402Assignment.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment" "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment" "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug" "D:\CO2402 Advanced Programming\Assignment\CO2402Assignment\cmake-build-debug\CMakeFiles\CO2402Assignment.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\CO2402Assignment.dir\depend

