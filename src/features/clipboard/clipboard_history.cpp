#include "clipboard_history.h"
#include <QDebug>
#include <QDateTime>

namespace features::clipboard {

ClipboardHistory::ClipboardHistory(int maxSize)
    : m_maxSize(maxSize) {
    qDebug() << "[ClipboardHistory] Initialized with max size:" << maxSize;
}

ClipboardHistory::~ClipboardHistory() = default;

void ClipboardHistory::addEntry(const ClipboardEntry &entry) {
    ClipboardEntry newEntry = entry;
    if (newEntry.timestamp.isEmpty()) {
        newEntry.timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    }
    
    m_history.enqueue(newEntry);
    
    // Keep history within max size
    while (m_history.size() > m_maxSize) {
        m_history.dequeue();
    }
    
    qDebug() << "[ClipboardHistory] Added entry. History size:" << m_history.size();
}

QList<ClipboardEntry> ClipboardHistory::getHistory(int limit) const {
    QList<ClipboardEntry> result;
    int start = qMax(0, m_history.size() - limit);
    for (int i = start; i < m_history.size(); ++i) {
        result.append(m_history.at(i));
    }
    return result;
}

void ClipboardHistory::clearHistory() {
    m_history.clear();
    qDebug() << "[ClipboardHistory] History cleared";
}

ClipboardEntry ClipboardHistory::getLastEntry() const {
    if (!m_history.isEmpty()) {
        return m_history.last();
    }
    return ClipboardEntry();
}

} // namespace features::clipboard
