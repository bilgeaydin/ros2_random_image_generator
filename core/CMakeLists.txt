ADD_LIBRARY (bilge_random_image_generator_core src/bilge_random_image_generator.cpp)

message("######################## Core-1 ############################################")

AMENT_TARGET_DEPENDENCIES(bilge_random_image_generator_core
  rclcpp
  std_msgs
  sensor_msgs
  cv_bridge
  image_transport
  OpenCV
  )

message("######################## Core-2 ############################################")

TARGET_INCLUDE_DIRECTORIES (
  bilge_random_image_generator_core PUBLIC $<INSTALL_INTERFACE:include>
                   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>)

message("######################## Core-3 ############################################")

TARGET_INCLUDE_DIRECTORIES (
  bilge_random_image_generator_core PUBLIC $<INSTALL_INTERFACE:include>
                   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)

message("######################## Core-4 ############################################")
