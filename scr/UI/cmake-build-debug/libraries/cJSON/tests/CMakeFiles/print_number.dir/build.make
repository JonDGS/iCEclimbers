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
include libraries/cJSON/tests/CMakeFiles/print_number.dir/depend.make

# Include the progress variables for this target.
include libraries/cJSON/tests/CMakeFiles/print_number.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/cJSON/tests/CMakeFiles/print_number.dir/flags.make

libraries/cJSON/tests/CMakeFiles/print_number.dir/print_number.c.obj: libraries/cJSON/tests/CMakeFiles/print_number.dir/flags.make
libraries/cJSON/tests/CMakeFiles/print_number.dir/print_number.c.obj: ../libraries/cJSON/tests/print_number.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object libraries/cJSON/tests/CMakeFiles/print_number.dir/print_number.c.obj"
	cd /d "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\libraries\cJSON\tests" && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\print_number.dir\print_number.c.obj   -c "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\libraries\cJSON\tests\print_number.c"

libraries/cJSON/tests/CMakeFiles/print_number.dir/print_number.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/print_number.dir/print_number.c.i"
	cd /d "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\libraries\cJSON\tests" && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\libraries\cJSON\tests\print_number.c" > CMakeFiles\print_number.dir\print_number.c.i

libraries/cJSON/tests/CMakeFiles/print_number.dir/print_number.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/print_number.dir/print_number.c.s"
	cd /d "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\libraries\cJSON\tests" && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\libraries\cJSON\tests\print_number.c" -o CMakeFiles\print_number.dir\print_number.c.s

# Object files for target print_number
print_number_OBJECTS = \
"CMakeFiles/print_number.dir/print_number.c.obj"

# External object files for target print_number
print_number_EXTERNAL_OBJECTS =

libraries/cJSON/tests/print_number.exe: libraries/cJSON/tests/CMakeFiles/print_number.dir/print_number.c.obj
libraries/cJSON/tests/print_number.exe: libraries/cJSON/tests/CMakeFiles/print_number.dir/build.make
libraries/cJSON/tests/print_number.exe: libraries/cJSON/libcjson.dll.a
libraries/cJSON/tests/print_number.exe: libraries/cJSON/tests/libunity.a
libraries/cJSON/tests/print_number.exe: libraries/cJSON/tests/CMakeFiles/print_number.dir/linklibs.rsp
libraries/cJSON/tests/print_number.exe: libraries/cJSON/tests/CMakeFiles/print_number.dir/objects1.rsp
libraries/cJSON/tests/print_number.exe: libraries/cJSON/tests/CMakeFiles/print_number.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable print_number.exe"
	cd /d "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\libraries\cJSON\tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\print_number.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/cJSON/tests/CMakeFiles/print_number.dir/build: libraries/cJSON/tests/print_number.exe

.PHONY : libraries/cJSON/tests/CMakeFiles/print_number.dir/build

libraries/cJSON/tests/CMakeFiles/print_number.dir/clean:
	cd /d "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\libraries\cJSON\tests" && $(CMAKE_COMMAND) -P CMakeFiles\print_number.dir\cmake_clean.cmake
.PHONY : libraries/cJSON/tests/CMakeFiles/print_number.dir/clean

libraries/cJSON/tests/CMakeFiles/print_number.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI" "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\libraries\cJSON\tests" "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug" "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\libraries\cJSON\tests" "D:\OneDrive TEC\OneDrive - Estudiantes ITCR\GITHUB\iCEclimbers\iCEclimbers\scr\UI\cmake-build-debug\libraries\cJSON\tests\CMakeFiles\print_number.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : libraries/cJSON/tests/CMakeFiles/print_number.dir/depend

