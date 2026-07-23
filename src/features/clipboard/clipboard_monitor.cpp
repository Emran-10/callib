#include "clipboard_monitor.h"
#include <QGuiApplication>
#include <QClipboard>

namespace features::clipboard {

void ClipboardMonitor::startMonitoring() {}
void ClipboardMonitor::stopMonitoring() {}

QString ClipboardMonitor::getLastClipboardText() const {
    const QClipboard *clipboard = QGuiApplication::clipboard();
    return clipboard ? clipboard->text() : QString();
}

} // namespace features::clipboard
