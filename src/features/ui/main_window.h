#pragma once
#include <QMainWindow>

namespace features::ui {

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onCaptureButtonClicked();
};

} // namespace features::ui
