#pragma once
#include <QString>

namespace core::interfaces {

class IClipboardMonitor {
public:
    virtual ~IClipboardMonitor() = default;
    virtual void startMonitoring() = 0;
    virtual void stopMonitoring() = 0;
    virtual QString getLastClipboardText() const = 0;
};

} // namespace core::interfaces
