cmake_minimum_required(VERSION 3.8)
project(bilge_random_image_generator)

message("######################## Prj-0 ############################################")

# Default to C++14
IF (NOT CMAKE_CXX_STANDARD)
  SET (CMAKE_CXX_STANDARD 14)
ENDIF ()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(cv_bridge_DIR /opt/ros/humble/share/cv_bridge/cmake)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


message("######################## Prj-1 ############################################")

ADD_SUBDIRECTORY(core)

message("######################## Prj-2 ############################################")

ADD_EXECUTABLE(bilge_random_image_generator_ros2_node node/main.cpp node/node.cpp)

message("######################## Prj-3 ############################################")

TARGET_LINK_LIBRARIES(bilge_random_image_generator_ros2_node
  PUBLIC bilge_random_image_generator_core
  )
message("######################## Prj-4 ############################################")

#ament_target_dependencies(bilge_random_image_generator_ros2_node
#  rclcpp
#  std_msgs
#  sensor_msgs
#  cv_bridge
#  image_transport
#  OpenCV
#  )

message("######################## Prj-5 ############################################")

install(TARGETS
   bilge_random_image_generator_ros2_node
   DESTINATION lib/${PROJECT_NAME}
 )

 message("######################## Prj-6 ############################################")

ament_package()

message("######################## Prj-7 ############################################")