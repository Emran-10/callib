add_library(toc_generator_lib toc_generator.cpp toc_generator.h)

target_include_directories(toc_generator_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_link_libraries(toc_generator_lib PUBLIC core_lib Qt6::Core)
