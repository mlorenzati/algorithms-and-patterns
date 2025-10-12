cmake_minimum_required(VERSION 3.21)

project(graph LANGUAGES CXX)

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
add_executable(graph
    ${CMAKE_CURRENT_LIST_DIR}/../../common/graphicsConsole.cpp
    ${CMAKE_CURRENT_LIST_DIR}/graph.cpp
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    )

# Copy required files to build folder
configure_file(graph.conf graph.conf)

# Link Qt libraries
target_link_libraries(graph PRIVATE Qt6::Core Qt6::Widgets)

# Enable automatic MOC, UIC, and RCC
set_target_properties(graph PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)