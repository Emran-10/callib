add_library(subject_management_lib subject_manager.cpp subject_manager.h)

target_include_directories(subject_management_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_link_libraries(subject_management_lib PUBLIC core_lib Qt6::Core)
