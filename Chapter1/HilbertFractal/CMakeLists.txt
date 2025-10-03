cmake_minimum_required(VERSION 3.21)

project(hilbertFractal LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Create the executable
add_executable(hilbertFractal
    graphicsConsole.cpp
    hilbert.cpp
    main.cpp
    )

# Link Qt libraries
target_link_libraries(hilbertFractal PRIVATE Qt6::Core Qt6::Widgets)

# Enable automatic MOC, UIC, and RCC
set_target_properties(hilbertFractal PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)