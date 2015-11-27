# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "facedetect: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(facedetect_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/turtlebot2/ros_ws/src/facedetect/srv/FacePosition.srv" NAME_WE)
add_custom_target(_facedetect_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "facedetect" "/home/turtlebot2/ros_ws/src/facedetect/srv/FacePosition.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(facedetect
  "/home/turtlebot2/ros_ws/src/facedetect/srv/FacePosition.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/facedetect
)

### Generating Module File
_generate_module_cpp(facedetect
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/facedetect
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(facedetect_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(facedetect_generate_messages facedetect_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/turtlebot2/ros_ws/src/facedetect/srv/FacePosition.srv" NAME_WE)
add_dependencies(facedetect_generate_messages_cpp _facedetect_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(facedetect_gencpp)
add_dependencies(facedetect_gencpp facedetect_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS facedetect_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(facedetect
  "/home/turtlebot2/ros_ws/src/facedetect/srv/FacePosition.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/facedetect
)

### Generating Module File
_generate_module_lisp(facedetect
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/facedetect
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(facedetect_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(facedetect_generate_messages facedetect_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/turtlebot2/ros_ws/src/facedetect/srv/FacePosition.srv" NAME_WE)
add_dependencies(facedetect_generate_messages_lisp _facedetect_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(facedetect_genlisp)
add_dependencies(facedetect_genlisp facedetect_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS facedetect_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(facedetect
  "/home/turtlebot2/ros_ws/src/facedetect/srv/FacePosition.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/facedetect
)

### Generating Module File
_generate_module_py(facedetect
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/facedetect
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(facedetect_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(facedetect_generate_messages facedetect_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/turtlebot2/ros_ws/src/facedetect/srv/FacePosition.srv" NAME_WE)
add_dependencies(facedetect_generate_messages_py _facedetect_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(facedetect_genpy)
add_dependencies(facedetect_genpy facedetect_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS facedetect_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/facedetect)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/facedetect
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(facedetect_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/facedetect)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/facedetect
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(facedetect_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/facedetect)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/facedetect\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/facedetect
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(facedetect_generate_messages_py std_msgs_generate_messages_py)
