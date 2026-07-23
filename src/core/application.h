#pragma once

#include <QApplication>
#include <memory>

namespace features::ui {
class MainWindow;
}

namespace core {

class Application {
public:
    Application(int argc, char *argv[]);
    ~Application();

    int exec();

private:
    std::unique_ptr<QApplication> m_app;
    std::unique_ptr<features::ui::MainWindow> m_mainWindow;
    void initializeServices();
};

} // namespace core
