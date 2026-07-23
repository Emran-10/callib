cmake_minimum_required(VERSION 3.20)
project(callib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt6
find_package(Qt6 COMPONENTS 
    Core 
    Gui 
    Widgets 
    REQUIRED
)

# Add subdirectories
add_subdirectory(src/core)
add_subdirectory(src/utilities)
add_subdirectory(src/features)

# Main executable
add_executable(callib
    src/main.cpp
)

target_link_libraries(callib 
    PRIVATE 
        core_lib
        utilities_lib
        features_lib
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

target_include_directories(callib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
