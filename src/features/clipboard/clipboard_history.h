#pragma once
#include <QString>
#include <QList>
#include <QQueue>
#include "i_clipboard_history.h"

namespace features::clipboard {

class ClipboardHistory : public IClipboardHistory {
public:
    ClipboardHistory(int maxSize = 100);
    ~ClipboardHistory();

    void addEntry(const ClipboardEntry &entry) override;
    QList<ClipboardEntry> getHistory(int limit = 50) const override;
    void clearHistory() override;
    ClipboardEntry getLastEntry() const override;

private:
    QQueue<ClipboardEntry> m_history;
    int m_maxSize;
};

} // namespace features::clipboard
