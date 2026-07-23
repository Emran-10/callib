#include "application.h"
#include "service_locator.h"

// Qt Utilities
#include <QFontDatabase>
#include <QFont>
#include <QDebug>

// Abstract Interfaces
#include "core/interfaces/i_logger.h"
#include "core/interfaces/i_file_handler.h"
#include "core/interfaces/i_clipboard_monitor.h"
#include "core/interfaces/i_subject_manager.h"
#include "core/interfaces/i_document_normalizer.h"
#include "core/interfaces/i_toc_generator.h"
#include "core/interfaces/i_section_manager.h"
#include "core/interfaces/i_image_capturer.h"
#include "core/interfaces/i_shortcut_manager.h"
#include "core/interfaces/i_settings_manager.h"

// Concrete Utilities
#include "utilities/logger.h"
#include "utilities/file_handler.h"

// Concrete Features
#include "features/clipboard/clipboard_monitor.h"
#include "features/subject_management/subject_manager.h"
#include "features/document_normalizer/normalizer.h"
#include "features/toc_generator/toc_generator.h"
#include "features/section_manager/section_manager.h"
#include "features/image_capture/image_capturer.h"
#include "features/keyboard_shortcuts/shortcut_manager.h"
#include "features/settings/settings_manager.h"
#include "features/ui/main_window.h"

namespace core {

Application::Application(int argc, char *argv[]) {
    // 1. Initialize QApplication before any Qt objects
    m_app = std::make_unique<QApplication>(argc, argv);

    // 2. Register all abstract services into Service Locator
    initializeServices();
}

Application::~Application() = default;

void Application::initializeServices() {
    // Register Utilities
    ServiceLocator::provide<interfaces::ILogger>(std::make_shared<utilities::Logger>());
    ServiceLocator::provide<interfaces::IFileHandler>(std::make_shared<utilities::FileHandler>());

    // Register Features
    ServiceLocator::provide<interfaces::ISettingsManager>(std::make_shared<features::settings::SettingsManager>());
    ServiceLocator::provide<interfaces::IClipboardMonitor>(std::make_shared<features::clipboard::ClipboardMonitor>());
    ServiceLocator::provide<interfaces::ISubjectManager>(std::make_shared<features::subject_management::SubjectManager>());
    ServiceLocator::provide<interfaces::IDocumentNormalizer>(std::make_shared<features::document_normalizer::DocumentNormalizer>());
    ServiceLocator::provide<interfaces::ITocGenerator>(std::make_shared<features::toc_generator::TocGenerator>());
    ServiceLocator::provide<interfaces::ISectionManager>(std::make_shared<features::section_manager::SectionManager>());
    ServiceLocator::provide<interfaces::IImageCapturer>(std::make_shared<features::image_capture::ImageCapturer>());
    ServiceLocator::provide<interfaces::IShortcutManager>(std::make_shared<features::keyboard_shortcuts::ShortcutManager>());
}

int Application::exec() {
    // Set default system font if custom fonts are unavailable
    QFont defaultFont("Ubuntu", 10);
    QApplication::setFont(defaultFont);
    qDebug() << "[Font Manager] Using system default font";

    // Instantiate Main Window on Heap and display
    m_mainWindow = std::make_unique<features::ui::MainWindow>();
    m_mainWindow->show();

    return m_app->exec();
}

} // namespace core
