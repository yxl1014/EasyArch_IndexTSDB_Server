# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/yxl/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.6682.181/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/yxl/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.6682.181/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yxl/CLionProjects/ms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yxl/CLionProjects/ms/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sqlite_storage.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sqlite_storage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sqlite_storage.dir/flags.make

CMakeFiles/sqlite_storage.dir/main.cpp.o: CMakeFiles/sqlite_storage.dir/flags.make
CMakeFiles/sqlite_storage.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yxl/CLionProjects/ms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sqlite_storage.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sqlite_storage.dir/main.cpp.o -c /home/yxl/CLionProjects/ms/main.cpp

CMakeFiles/sqlite_storage.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sqlite_storage.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yxl/CLionProjects/ms/main.cpp > CMakeFiles/sqlite_storage.dir/main.cpp.i

CMakeFiles/sqlite_storage.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sqlite_storage.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yxl/CLionProjects/ms/main.cpp -o CMakeFiles/sqlite_storage.dir/main.cpp.s

CMakeFiles/sqlite_storage.dir/Mms/do.cpp.o: CMakeFiles/sqlite_storage.dir/flags.make
CMakeFiles/sqlite_storage.dir/Mms/do.cpp.o: ../Mms/do.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yxl/CLionProjects/ms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sqlite_storage.dir/Mms/do.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sqlite_storage.dir/Mms/do.cpp.o -c /home/yxl/CLionProjects/ms/Mms/do.cpp

CMakeFiles/sqlite_storage.dir/Mms/do.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sqlite_storage.dir/Mms/do.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yxl/CLionProjects/ms/Mms/do.cpp > CMakeFiles/sqlite_storage.dir/Mms/do.cpp.i

CMakeFiles/sqlite_storage.dir/Mms/do.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sqlite_storage.dir/Mms/do.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yxl/CLionProjects/ms/Mms/do.cpp -o CMakeFiles/sqlite_storage.dir/Mms/do.cpp.s

CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.o: CMakeFiles/sqlite_storage.dir/flags.make
CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.o: ../Tools/tools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yxl/CLionProjects/ms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.o -c /home/yxl/CLionProjects/ms/Tools/tools.cpp

CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yxl/CLionProjects/ms/Tools/tools.cpp > CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.i

CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yxl/CLionProjects/ms/Tools/tools.cpp -o CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.s

CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.o: CMakeFiles/sqlite_storage.dir/flags.make
CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.o: ../User/operationUser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yxl/CLionProjects/ms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.o -c /home/yxl/CLionProjects/ms/User/operationUser.cpp

CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yxl/CLionProjects/ms/User/operationUser.cpp > CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.i

CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yxl/CLionProjects/ms/User/operationUser.cpp -o CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.s

CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.o: CMakeFiles/sqlite_storage.dir/flags.make
CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.o: ../MTools/Mtools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yxl/CLionProjects/ms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.o -c /home/yxl/CLionProjects/ms/MTools/Mtools.cpp

CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yxl/CLionProjects/ms/MTools/Mtools.cpp > CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.i

CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yxl/CLionProjects/ms/MTools/Mtools.cpp -o CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.s

# Object files for target sqlite_storage
sqlite_storage_OBJECTS = \
"CMakeFiles/sqlite_storage.dir/main.cpp.o" \
"CMakeFiles/sqlite_storage.dir/Mms/do.cpp.o" \
"CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.o" \
"CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.o" \
"CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.o"

# External object files for target sqlite_storage
sqlite_storage_EXTERNAL_OBJECTS =

sqlite_storage: CMakeFiles/sqlite_storage.dir/main.cpp.o
sqlite_storage: CMakeFiles/sqlite_storage.dir/Mms/do.cpp.o
sqlite_storage: CMakeFiles/sqlite_storage.dir/Tools/tools.cpp.o
sqlite_storage: CMakeFiles/sqlite_storage.dir/User/operationUser.cpp.o
sqlite_storage: CMakeFiles/sqlite_storage.dir/MTools/Mtools.cpp.o
sqlite_storage: CMakeFiles/sqlite_storage.dir/build.make
sqlite_storage: CMakeFiles/sqlite_storage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yxl/CLionProjects/ms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable sqlite_storage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sqlite_storage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sqlite_storage.dir/build: sqlite_storage

.PHONY : CMakeFiles/sqlite_storage.dir/build

CMakeFiles/sqlite_storage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sqlite_storage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sqlite_storage.dir/clean

CMakeFiles/sqlite_storage.dir/depend:
	cd /home/yxl/CLionProjects/ms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yxl/CLionProjects/ms /home/yxl/CLionProjects/ms /home/yxl/CLionProjects/ms/cmake-build-debug /home/yxl/CLionProjects/ms/cmake-build-debug /home/yxl/CLionProjects/ms/cmake-build-debug/CMakeFiles/sqlite_storage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sqlite_storage.dir/depend
