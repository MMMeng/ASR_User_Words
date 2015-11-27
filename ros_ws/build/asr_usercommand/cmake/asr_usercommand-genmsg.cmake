# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "asr_usercommand: 1 messages, 1 services")

set(MSG_I_FLAGS "-Iasr_usercommand:/home/turtlebot2/ros_ws/src/asr_usercommand/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(asr_usercommand_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/turtlebot2/ros_ws/src/asr_usercommand/msg/Command.msg" NAME_WE)
add_custom_target(_asr_usercommand_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "asr_usercommand" "/home/turtlebot2/ros_ws/src/asr_usercommand/msg/Command.msg" ""
)

get_filename_component(_filename "/home/turtlebot2/ros_ws/src/asr_usercommand/srv/UserCommand.srv" NAME_WE)
add_custom_target(_asr_usercommand_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "asr_usercommand" "/home/turtlebot2/ros_ws/src/asr_usercommand/srv/UserCommand.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(asr_usercommand
  "/home/turtlebot2/ros_ws/src/asr_usercommand/msg/Command.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/asr_usercommand
)

### Generating Services
_generate_srv_cpp(asr_usercommand
  "/home/turtlebot2/ros_ws/src/asr_usercommand/srv/UserCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/asr_usercommand
)

### Generating Module File
_generate_module_cpp(asr_usercommand
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/asr_usercommand
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(asr_usercommand_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(asr_usercommand_generate_messages asr_usercommand_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/turtlebot2/ros_ws/src/asr_usercommand/msg/Command.msg" NAME_WE)
add_dependencies(asr_usercommand_generate_messages_cpp _asr_usercommand_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/turtlebot2/ros_ws/src/asr_usercommand/srv/UserCommand.srv" NAME_WE)
add_dependencies(asr_usercommand_generate_messages_cpp _asr_usercommand_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(asr_usercommand_gencpp)
add_dependencies(asr_usercommand_gencpp asr_usercommand_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS asr_usercommand_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(asr_usercommand
  "/home/turtlebot2/ros_ws/src/asr_usercommand/msg/Command.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/asr_usercommand
)

### Generating Services
_generate_srv_lisp(asr_usercommand
  "/home/turtlebot2/ros_ws/src/asr_usercommand/srv/UserCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/asr_usercommand
)

### Generating Module File
_generate_module_lisp(asr_usercommand
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/asr_usercommand
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(asr_usercommand_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(asr_usercommand_generate_messages asr_usercommand_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/turtlebot2/ros_ws/src/asr_usercommand/msg/Command.msg" NAME_WE)
add_dependencies(asr_usercommand_generate_messages_lisp _asr_usercommand_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/turtlebot2/ros_ws/src/asr_usercommand/srv/UserCommand.srv" NAME_WE)
add_dependencies(asr_usercommand_generate_messages_lisp _asr_usercommand_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(asr_usercommand_genlisp)
add_dependencies(asr_usercommand_genlisp asr_usercommand_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS asr_usercommand_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(asr_usercommand
  "/home/turtlebot2/ros_ws/src/asr_usercommand/msg/Command.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asr_usercommand
)

### Generating Services
_generate_srv_py(asr_usercommand
  "/home/turtlebot2/ros_ws/src/asr_usercommand/srv/UserCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asr_usercommand
)

### Generating Module File
_generate_module_py(asr_usercommand
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asr_usercommand
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(asr_usercommand_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(asr_usercommand_generate_messages asr_usercommand_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/turtlebot2/ros_ws/src/asr_usercommand/msg/Command.msg" NAME_WE)
add_dependencies(asr_usercommand_generate_messages_py _asr_usercommand_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/turtlebot2/ros_ws/src/asr_usercommand/srv/UserCommand.srv" NAME_WE)
add_dependencies(asr_usercommand_generate_messages_py _asr_usercommand_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(asr_usercommand_genpy)
add_dependencies(asr_usercommand_genpy asr_usercommand_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS asr_usercommand_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/asr_usercommand)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/asr_usercommand
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(asr_usercommand_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/asr_usercommand)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/asr_usercommand
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(asr_usercommand_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asr_usercommand)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asr_usercommand\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/asr_usercommand
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(asr_usercommand_generate_messages_py std_msgs_generate_messages_py)
