# Enable AUTOMOC for this specific library
set(CMAKE_AUTOMOC ON)

add_library(keyboard_shortcuts_lib shortcut_manager.cpp shortcut_manager.h)

target_include_directories(keyboard_shortcuts_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)

# Note: If ShortcutManager uses Q_OBJECT, it needs Qt6::Widgets or Qt6::Gui linked here too
target_link_libraries(keyboard_shortcuts_lib PUBLIC core_lib Qt6::Widgets)
