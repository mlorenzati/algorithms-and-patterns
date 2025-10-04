cmake_minimum_required(VERSION 3.21)

project(maze LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/../../common
    )

# Create the executable
add_executable(maze
    ${CMAKE_CURRENT_LIST_DIR}/../../common/graphicsConsole.cpp
    ${CMAKE_CURRENT_LIST_DIR}/maze.cpp
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    )

# Link Qt libraries
target_link_libraries(maze PRIVATE Qt6::Core Qt6::Widgets)

# Enable automatic MOC, UIC, and RCC
set_target_properties(maze PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)