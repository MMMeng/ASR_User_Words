# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/turtlebot2/ros_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/turtlebot2/ros_ws/build

# Include any dependencies generated for this target.
include facedetect/CMakeFiles/faceDetect_server.dir/depend.make

# Include the progress variables for this target.
include facedetect/CMakeFiles/faceDetect_server.dir/progress.make

# Include the compile flags for this target's objects.
include facedetect/CMakeFiles/faceDetect_server.dir/flags.make

facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o: facedetect/CMakeFiles/faceDetect_server.dir/flags.make
facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o: /home/turtlebot2/ros_ws/src/facedetect/src/faceDetect_server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/turtlebot2/ros_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o"
	cd /home/turtlebot2/ros_ws/build/facedetect && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o -c /home/turtlebot2/ros_ws/src/facedetect/src/faceDetect_server.cpp

facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.i"
	cd /home/turtlebot2/ros_ws/build/facedetect && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/turtlebot2/ros_ws/src/facedetect/src/faceDetect_server.cpp > CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.i

facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.s"
	cd /home/turtlebot2/ros_ws/build/facedetect && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/turtlebot2/ros_ws/src/facedetect/src/faceDetect_server.cpp -o CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.s

facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o.requires:
.PHONY : facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o.requires

facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o.provides: facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o.requires
	$(MAKE) -f facedetect/CMakeFiles/faceDetect_server.dir/build.make facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o.provides.build
.PHONY : facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o.provides

facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o.provides.build: facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o

# Object files for target faceDetect_server
faceDetect_server_OBJECTS = \
"CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o"

# External object files for target faceDetect_server
faceDetect_server_EXTERNAL_OBJECTS =

/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: facedetect/CMakeFiles/faceDetect_server.dir/build.make
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /opt/ros/indigo/lib/libroscpp.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/lib/i386-linux-gnu/libboost_signals.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/lib/i386-linux-gnu/libboost_filesystem.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /opt/ros/indigo/lib/librosconsole.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/lib/liblog4cxx.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/lib/i386-linux-gnu/libboost_regex.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /opt/ros/indigo/lib/librostime.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/lib/i386-linux-gnu/libboost_date_time.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /opt/ros/indigo/lib/libcpp_common.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/lib/i386-linux-gnu/libboost_system.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/lib/i386-linux-gnu/libboost_thread.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/lib/i386-linux-gnu/libpthread.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/lib/i386-linux-gnu/libconsole_bridge.so
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_viz.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_videostab.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_videoio.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_video.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_superres.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_stitching.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_shape.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_photo.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_objdetect.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_ml.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_imgproc.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_highgui.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_hal.a
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_flann.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_features2d.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_core.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_calib3d.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_features2d.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_ml.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_highgui.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_videoio.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_flann.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_video.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_imgproc.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_core.so.3.0.0
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: /usr/local/lib/libopencv_hal.a
/home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server: facedetect/CMakeFiles/faceDetect_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server"
	cd /home/turtlebot2/ros_ws/build/facedetect && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/faceDetect_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
facedetect/CMakeFiles/faceDetect_server.dir/build: /home/turtlebot2/ros_ws/devel/lib/facedetect/faceDetect_server
.PHONY : facedetect/CMakeFiles/faceDetect_server.dir/build

facedetect/CMakeFiles/faceDetect_server.dir/requires: facedetect/CMakeFiles/faceDetect_server.dir/src/faceDetect_server.cpp.o.requires
.PHONY : facedetect/CMakeFiles/faceDetect_server.dir/requires

facedetect/CMakeFiles/faceDetect_server.dir/clean:
	cd /home/turtlebot2/ros_ws/build/facedetect && $(CMAKE_COMMAND) -P CMakeFiles/faceDetect_server.dir/cmake_clean.cmake
.PHONY : facedetect/CMakeFiles/faceDetect_server.dir/clean

facedetect/CMakeFiles/faceDetect_server.dir/depend:
	cd /home/turtlebot2/ros_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/turtlebot2/ros_ws/src /home/turtlebot2/ros_ws/src/facedetect /home/turtlebot2/ros_ws/build /home/turtlebot2/ros_ws/build/facedetect /home/turtlebot2/ros_ws/build/facedetect/CMakeFiles/faceDetect_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : facedetect/CMakeFiles/faceDetect_server.dir/depend

