#pragma once
#include <QString>
#include <QList>
#include <QDateTime>

namespace features::clipboard {

struct ClipboardEntry {
    QString content;
    QString timestamp;
    bool isImage;
    QString imagePath;
};

class IClipboardHistory {
public:
    virtual ~IClipboardHistory() = default;
    virtual void addEntry(const ClipboardEntry &entry) = 0;
    virtual QList<ClipboardEntry> getHistory(int limit = 50) const = 0;
    virtual void clearHistory() = 0;
    virtual ClipboardEntry getLastEntry() const = 0;
};

} // namespace features::clipboard
