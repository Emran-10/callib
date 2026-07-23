#include "heading_dialog.h"

namespace features::heading_search {

HeadingDialog::HeadingDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Heading Search");
}

void HeadingDialog::showDialog() {
    this->exec();
}

} // namespace features::heading_search
