add_library(document_normalizer_lib normalizer.cpp normalizer.h)

target_include_directories(document_normalizer_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_link_libraries(document_normalizer_lib PUBLIC core_lib Qt6::Core)
