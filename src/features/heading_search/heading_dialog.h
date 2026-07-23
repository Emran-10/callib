#pragma once
#include "core/interfaces/i_heading_dialog.h"
#include <QDialog>

namespace features::heading_search {

class HeadingDialog : public QDialog, public core::interfaces::IHeadingDialog {
    Q_OBJECT
public:
    explicit HeadingDialog(QWidget *parent = nullptr);
    void showDialog() override;
};

} // namespace features::heading_search
