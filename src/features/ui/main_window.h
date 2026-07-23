#pragma once
#include <QMainWindow>
#include <memory>

namespace features::ui {

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupUI();
    void connectSignals();
};

} // namespace features::ui
