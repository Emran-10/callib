add_library(utilities_lib
    logger.cpp
    logger.h
    file_handler.cpp
    file_handler.h
)

target_include_directories(utilities_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(utilities_lib PUBLIC core_lib Qt6::Core)
