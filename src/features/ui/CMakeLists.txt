# Enable Qt Resource Compiler (RCC)
set(CMAKE_AUTORCC ON)

add_library(ui_lib 
    main_window.cpp 
    main_window.h 
    resources.qrc
)

target_include_directories(ui_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_link_libraries(ui_lib PUBLIC core_lib Qt6::Widgets)
