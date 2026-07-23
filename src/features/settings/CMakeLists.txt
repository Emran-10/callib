add_library(settings_lib 
    settings_manager.cpp 
    settings_manager.h 
    settings_dialog.cpp 
    settings_dialog.h
)
target_include_directories(settings_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_link_libraries(settings_lib PUBLIC core_lib Qt6::Widgets)
