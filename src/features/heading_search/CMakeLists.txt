add_library(heading_search_lib heading_dialog.cpp heading_dialog.h)
target_include_directories(heading_search_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_link_libraries(heading_search_lib PUBLIC core_lib Qt6::Widgets)
