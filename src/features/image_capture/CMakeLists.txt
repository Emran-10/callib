add_library(image_capture_lib image_capturer.cpp image_capturer.h)
target_include_directories(image_capture_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_link_libraries(image_capture_lib PUBLIC core_lib Qt6::Core)
