# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/UI.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UI.dir/flags.make

CMakeFiles/UI.dir/main.c.obj: CMakeFiles/UI.dir/flags.make
CMakeFiles/UI.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/UI.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\UI.dir\main.c.obj   -c "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\main.c"

CMakeFiles/UI.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UI.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\main.c" > CMakeFiles\UI.dir\main.c.i

CMakeFiles/UI.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UI.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\main.c" -o CMakeFiles\UI.dir\main.c.s

# Object files for target UI
UI_OBJECTS = \
"CMakeFiles/UI.dir/main.c.obj"

# External object files for target UI
UI_EXTERNAL_OBJECTS =

UI.exe: CMakeFiles/UI.dir/main.c.obj
UI.exe: CMakeFiles/UI.dir/build.make
UI.exe: CMakeFiles/UI.dir/linklibs.rsp
UI.exe: CMakeFiles/UI.dir/objects1.rsp
UI.exe: CMakeFiles/UI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable UI.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\UI.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UI.dir/build: UI.exe

.PHONY : CMakeFiles/UI.dir/build

CMakeFiles/UI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\UI.dir\cmake_clean.cmake
.PHONY : CMakeFiles/UI.dir/clean

CMakeFiles/UI.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI" "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI" "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug" "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug" "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\CMakeFiles\UI.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/UI.dir/depend

