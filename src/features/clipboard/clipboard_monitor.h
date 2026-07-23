#pragma once
#include "core/interfaces/i_clipboard_monitor.h"

namespace features::clipboard {

class ClipboardMonitor : public core::interfaces::IClipboardMonitor {
public:
    void startMonitoring() override;
    void stopMonitoring() override;
    QString getLastClipboardText() const override;
};

} // namespace features::clipboard
