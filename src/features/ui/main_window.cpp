#include "main_window.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

namespace features::ui {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setupUI();
    connectSignals();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupUI() {
    setWindowTitle("CalLib - Document Manager");
    setGeometry(100, 100, 800, 600);

    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);
    
    auto *label = new QLabel("Welcome to CalLib", this);
    layout->addWidget(label);
    
    setCentralWidget(centralWidget);
    qDebug() << "[UI] Main Window initialized";
}

void MainWindow::connectSignals() {
    // Connect signals here
}

} // namespace features::ui
