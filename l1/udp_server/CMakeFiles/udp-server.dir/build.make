# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mike/git/dzN1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mike/git/dzN1

# Include any dependencies generated for this target.
include l1/udp_server/CMakeFiles/udp-server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include l1/udp_server/CMakeFiles/udp-server.dir/compiler_depend.make

# Include the progress variables for this target.
include l1/udp_server/CMakeFiles/udp-server.dir/progress.make

# Include the compile flags for this target's objects.
include l1/udp_server/CMakeFiles/udp-server.dir/flags.make

l1/udp_server/CMakeFiles/udp-server.dir/main.cpp.o: l1/udp_server/CMakeFiles/udp-server.dir/flags.make
l1/udp_server/CMakeFiles/udp-server.dir/main.cpp.o: l1/udp_server/main.cpp
l1/udp_server/CMakeFiles/udp-server.dir/main.cpp.o: l1/udp_server/CMakeFiles/udp-server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mike/git/dzN1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object l1/udp_server/CMakeFiles/udp-server.dir/main.cpp.o"
	cd /home/mike/git/dzN1/l1/udp_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT l1/udp_server/CMakeFiles/udp-server.dir/main.cpp.o -MF CMakeFiles/udp-server.dir/main.cpp.o.d -o CMakeFiles/udp-server.dir/main.cpp.o -c /home/mike/git/dzN1/l1/udp_server/main.cpp

l1/udp_server/CMakeFiles/udp-server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp-server.dir/main.cpp.i"
	cd /home/mike/git/dzN1/l1/udp_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mike/git/dzN1/l1/udp_server/main.cpp > CMakeFiles/udp-server.dir/main.cpp.i

l1/udp_server/CMakeFiles/udp-server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp-server.dir/main.cpp.s"
	cd /home/mike/git/dzN1/l1/udp_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mike/git/dzN1/l1/udp_server/main.cpp -o CMakeFiles/udp-server.dir/main.cpp.s

# Object files for target udp-server
udp__server_OBJECTS = \
"CMakeFiles/udp-server.dir/main.cpp.o"

# External object files for target udp-server
udp__server_EXTERNAL_OBJECTS =

bin/udp-server: l1/udp_server/CMakeFiles/udp-server.dir/main.cpp.o
bin/udp-server: l1/udp_server/CMakeFiles/udp-server.dir/build.make
bin/udp-server: socket_wrapper/libsocket-wrapper.a
bin/udp-server: l1/udp_server/CMakeFiles/udp-server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mike/git/dzN1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/udp-server"
	cd /home/mike/git/dzN1/l1/udp_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp-server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
l1/udp_server/CMakeFiles/udp-server.dir/build: bin/udp-server
.PHONY : l1/udp_server/CMakeFiles/udp-server.dir/build

l1/udp_server/CMakeFiles/udp-server.dir/clean:
	cd /home/mike/git/dzN1/l1/udp_server && $(CMAKE_COMMAND) -P CMakeFiles/udp-server.dir/cmake_clean.cmake
.PHONY : l1/udp_server/CMakeFiles/udp-server.dir/clean

l1/udp_server/CMakeFiles/udp-server.dir/depend:
	cd /home/mike/git/dzN1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mike/git/dzN1 /home/mike/git/dzN1/l1/udp_server /home/mike/git/dzN1 /home/mike/git/dzN1/l1/udp_server /home/mike/git/dzN1/l1/udp_server/CMakeFiles/udp-server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : l1/udp_server/CMakeFiles/udp-server.dir/depend
