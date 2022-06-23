cmake_minimum_required(VERSION 3.5)
project(followme_turtlebot3)

# Default to C99
if (NOT CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 99)
endif ()

# Default to C++14
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif ()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

add_executable(follow_me src/follow_me.cpp include/followme_turtlebot3/follow_me.hpp)
ament_target_dependencies(follow_me rclcpp sensor_msgs)
install(TARGETS follow_me DESTINATION lib/${PROJECT_NAME})

# Install launch directory
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

ament_package()

