add_library(clipboard_lib clipboard_monitor.cpp clipboard_monitor.h)
target_include_directories(clipboard_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_link_libraries(clipboard_lib PUBLIC core_lib Qt6::Gui)
