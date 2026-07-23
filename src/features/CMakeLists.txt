# Features library - placeholder for feature modules
add_library(features_lib
    # UI Module - Basic main window placeholder
    ui/main_window.cpp
    ui/main_window.h
    
    # Clipboard Feature - placeholder
    clipboard/clipboard_monitor.cpp
    clipboard/clipboard_monitor.h
    
    # Document Normalizer - placeholder
    document_normalizer/normalizer.cpp
    document_normalizer/normalizer.h
    
    # TOC Generator - placeholder
    toc_generator/toc_generator.cpp
    toc_generator/toc_generator.h
    
    # Section Manager - placeholder
    section_manager/section_manager.cpp
    section_manager/section_manager.h
    
    # Image Capturer - placeholder
    image_capture/image_capturer.cpp
    image_capture/image_capturer.h
    
    # Subject Manager - placeholder
    subject_management/subject_manager.cpp
    subject_management/subject_manager.h
    
    # Keyboard Shortcuts - placeholder
    keyboard_shortcuts/shortcut_manager.cpp
    keyboard_shortcuts/shortcut_manager.h
    
    # Settings Manager - placeholder
    settings/settings_manager.cpp
    settings/settings_manager.h
    
    # Heading Search - placeholder
    heading_search/heading_search.cpp
    heading_search/heading_search.h
)

target_include_directories(features_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(features_lib PUBLIC core_lib utilities_lib Qt6::Widgets Qt6::Gui)
