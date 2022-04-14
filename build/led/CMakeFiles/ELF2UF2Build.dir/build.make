# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\VSARM\sdk\Pico\project\DAS-Driver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\VSARM\sdk\Pico\project\DAS-Driver\build

# Utility rule file for ELF2UF2Build.

# Include any custom commands dependencies for this target.
include led/CMakeFiles/ELF2UF2Build.dir/compiler_depend.make

# Include the progress variables for this target.
include led/CMakeFiles/ELF2UF2Build.dir/progress.make

led/CMakeFiles/ELF2UF2Build: led/CMakeFiles/ELF2UF2Build-complete

led/CMakeFiles/ELF2UF2Build-complete: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
led/CMakeFiles/ELF2UF2Build-complete: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
led/CMakeFiles/ELF2UF2Build-complete: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
led/CMakeFiles/ELF2UF2Build-complete: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
led/CMakeFiles/ELF2UF2Build-complete: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
led/CMakeFiles/ELF2UF2Build-complete: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
led/CMakeFiles/ELF2UF2Build-complete: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
led/CMakeFiles/ELF2UF2Build-complete: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\VSARM\sdk\Pico\project\DAS-Driver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'ELF2UF2Build'"
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E make_directory C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/CMakeFiles
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/CMakeFiles/ELF2UF2Build-complete
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-done

led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\VSARM\sdk\Pico\project\DAS-Driver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing build step for 'ELF2UF2Build'"
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\elf2uf2 && $(MAKE)

led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: led/elf2uf2/tmp/ELF2UF2Build-cfgcmd.txt
led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\VSARM\sdk\Pico\project\DAS-Driver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Performing configure step for 'ELF2UF2Build'"
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\elf2uf2 && "C:\Program Files\CMake\bin\cmake.exe" "-GMinGW Makefiles" C:/VSARM/sdk/Pico/pico-sdk/tools/elf2uf2
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\elf2uf2 && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure

led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\VSARM\sdk\Pico\project\DAS-Driver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'ELF2UF2Build'"
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download

led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\VSARM\sdk\Pico\project\DAS-Driver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'ELF2UF2Build'"
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\elf2uf2 && "C:\Program Files\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\elf2uf2 && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install

led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\VSARM\sdk\Pico\project\DAS-Driver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'ELF2UF2Build'"
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E make_directory C:/VSARM/sdk/Pico/pico-sdk/tools/elf2uf2
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E make_directory C:/VSARM/sdk/Pico/project/DAS-Driver/build/elf2uf2
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E make_directory C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E make_directory C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2/tmp
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E make_directory C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2/src/ELF2UF2Build-stamp
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E make_directory C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2/src
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E make_directory C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2/src/ELF2UF2Build-stamp
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir

led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\VSARM\sdk\Pico\project\DAS-Driver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'ELF2UF2Build'"
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch

led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\VSARM\sdk\Pico\project\DAS-Driver\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No update step for 'ELF2UF2Build'"
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/VSARM/sdk/Pico/project/DAS-Driver/build/led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update

ELF2UF2Build: led/CMakeFiles/ELF2UF2Build
ELF2UF2Build: led/CMakeFiles/ELF2UF2Build-complete
ELF2UF2Build: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
ELF2UF2Build: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
ELF2UF2Build: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
ELF2UF2Build: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
ELF2UF2Build: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
ELF2UF2Build: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
ELF2UF2Build: led/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
ELF2UF2Build: led/CMakeFiles/ELF2UF2Build.dir/build.make
.PHONY : ELF2UF2Build

# Rule to build all files generated by this target.
led/CMakeFiles/ELF2UF2Build.dir/build: ELF2UF2Build
.PHONY : led/CMakeFiles/ELF2UF2Build.dir/build

led/CMakeFiles/ELF2UF2Build.dir/clean:
	cd /d C:\VSARM\sdk\Pico\project\DAS-Driver\build\led && $(CMAKE_COMMAND) -P CMakeFiles\ELF2UF2Build.dir\cmake_clean.cmake
.PHONY : led/CMakeFiles/ELF2UF2Build.dir/clean

led/CMakeFiles/ELF2UF2Build.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\VSARM\sdk\Pico\project\DAS-Driver C:\VSARM\sdk\Pico\project\DAS-Driver\led C:\VSARM\sdk\Pico\project\DAS-Driver\build C:\VSARM\sdk\Pico\project\DAS-Driver\build\led C:\VSARM\sdk\Pico\project\DAS-Driver\build\led\CMakeFiles\ELF2UF2Build.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : led/CMakeFiles/ELF2UF2Build.dir/depend

