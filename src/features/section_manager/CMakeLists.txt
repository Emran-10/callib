add_library(section_manager_lib section_manager.cpp section_manager.h)

target_include_directories(section_manager_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_link_libraries(section_manager_lib PUBLIC core_lib Qt6::Core)
