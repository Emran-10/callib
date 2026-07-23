#include "clipboard_monitor.h"
#include <QDebug>

namespace features::clipboard {

void ClipboardMonitor::startMonitoring() {
    qDebug() << "[ClipboardMonitor] Started monitoring clipboard";
    m_lastText = "";
}

void ClipboardMonitor::stopMonitoring() {
    qDebug() << "[ClipboardMonitor] Stopped monitoring clipboard";
}

QString ClipboardMonitor::getLastClipboardText() const {
    return m_lastText;
}

} // namespace features::clipboard
