#include "clipboard_monitor.h"
#include <QDebug>

namespace features::clipboard {

void ClipboardMonitor::startMonitoring() {
    qDebug() << "[ClipboardMonitor] Started monitoring clipboard";
}

void ClipboardMonitor::stopMonitoring() {
    qDebug() << "[ClipboardMonitor] Stopped monitoring clipboard";
}

} // namespace features::clipboard
