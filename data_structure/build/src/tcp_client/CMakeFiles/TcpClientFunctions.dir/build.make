# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shuai/my_code/ilike/data_structure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shuai/my_code/ilike/data_structure/build

# Include any dependencies generated for this target.
include src/tcp_client/CMakeFiles/TcpClientFunctions.dir/depend.make

# Include the progress variables for this target.
include src/tcp_client/CMakeFiles/TcpClientFunctions.dir/progress.make

# Include the compile flags for this target's objects.
include src/tcp_client/CMakeFiles/TcpClientFunctions.dir/flags.make

src/tcp_client/CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.o: src/tcp_client/CMakeFiles/TcpClientFunctions.dir/flags.make
src/tcp_client/CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.o: ../src/tcp_client/TcpClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shuai/my_code/ilike/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/tcp_client/CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.o"
	cd /home/shuai/my_code/ilike/data_structure/build/src/tcp_client && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.o -c /home/shuai/my_code/ilike/data_structure/src/tcp_client/TcpClient.cpp

src/tcp_client/CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.i"
	cd /home/shuai/my_code/ilike/data_structure/build/src/tcp_client && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shuai/my_code/ilike/data_structure/src/tcp_client/TcpClient.cpp > CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.i

src/tcp_client/CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.s"
	cd /home/shuai/my_code/ilike/data_structure/build/src/tcp_client && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shuai/my_code/ilike/data_structure/src/tcp_client/TcpClient.cpp -o CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.s

# Object files for target TcpClientFunctions
TcpClientFunctions_OBJECTS = \
"CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.o"

# External object files for target TcpClientFunctions
TcpClientFunctions_EXTERNAL_OBJECTS =

../lib/libTcpClientFunctions.a: src/tcp_client/CMakeFiles/TcpClientFunctions.dir/TcpClient.cpp.o
../lib/libTcpClientFunctions.a: src/tcp_client/CMakeFiles/TcpClientFunctions.dir/build.make
../lib/libTcpClientFunctions.a: src/tcp_client/CMakeFiles/TcpClientFunctions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shuai/my_code/ilike/data_structure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libTcpClientFunctions.a"
	cd /home/shuai/my_code/ilike/data_structure/build/src/tcp_client && $(CMAKE_COMMAND) -P CMakeFiles/TcpClientFunctions.dir/cmake_clean_target.cmake
	cd /home/shuai/my_code/ilike/data_structure/build/src/tcp_client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TcpClientFunctions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/tcp_client/CMakeFiles/TcpClientFunctions.dir/build: ../lib/libTcpClientFunctions.a

.PHONY : src/tcp_client/CMakeFiles/TcpClientFunctions.dir/build

src/tcp_client/CMakeFiles/TcpClientFunctions.dir/clean:
	cd /home/shuai/my_code/ilike/data_structure/build/src/tcp_client && $(CMAKE_COMMAND) -P CMakeFiles/TcpClientFunctions.dir/cmake_clean.cmake
.PHONY : src/tcp_client/CMakeFiles/TcpClientFunctions.dir/clean

src/tcp_client/CMakeFiles/TcpClientFunctions.dir/depend:
	cd /home/shuai/my_code/ilike/data_structure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shuai/my_code/ilike/data_structure /home/shuai/my_code/ilike/data_structure/src/tcp_client /home/shuai/my_code/ilike/data_structure/build /home/shuai/my_code/ilike/data_structure/build/src/tcp_client /home/shuai/my_code/ilike/data_structure/build/src/tcp_client/CMakeFiles/TcpClientFunctions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/tcp_client/CMakeFiles/TcpClientFunctions.dir/depend
