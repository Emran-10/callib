#include "main_window.h"
#include "core/service_locator.h"
#include "core/interfaces/i_image_capturer.h"
#include "core/interfaces/i_logger.h"

#include <QPushButton>
#include <QVBoxLayout>

namespace features::ui {

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("GraberNotes Architecture");
    resize(400, 200);

    auto *central = new QWidget(this);
    auto *layout = new QVBoxLayout(central);

    auto *btn = new QPushButton("Capture Screen", central);
    layout->addWidget(btn);

    connect(btn, &QPushButton::clicked, this, &MainWindow::onCaptureButtonClicked);
    setCentralWidget(central);
}

void MainWindow::onCaptureButtonClicked() {
    auto capturer = core::ServiceLocator::get<core::interfaces::IImageCapturer>();
    auto logger = core::ServiceLocator::get<core::interfaces::ILogger>();

    if (capturer && logger) {
        if (capturer->captureRegion()) {
            logger->logInfo("Image captured at path: " + capturer->getCapturedImagePath());
        }
    }
}

} // namespace features::ui
