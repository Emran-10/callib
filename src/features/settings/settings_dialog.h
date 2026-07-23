#pragma once
#include <QDialog>

namespace features::settings {

class SettingsDialog : public QDialog {
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget *parent = nullptr);
};

} // namespace features::settings
