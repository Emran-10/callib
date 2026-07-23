# Core library with abstract interfaces and application bootstrap
add_library(core_lib
    application.cpp
    application.h
    service_locator.h
    resources.qrc
    interfaces/i_logger.h
    interfaces/i_file_handler.h
    interfaces/i_clipboard_monitor.h
    interfaces/i_subject_manager.h
    interfaces/i_heading_dialog.h
    interfaces/i_document_normalizer.h
    interfaces/i_toc_generator.h
    interfaces/i_section_manager.h
    interfaces/i_image_capturer.h
    interfaces/i_shortcut_manager.h
    interfaces/i_settings_manager.h
)

target_include_directories(core_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(core_lib PUBLIC Qt6::Widgets)
