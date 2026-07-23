#pragma once
#include <QString>

namespace core::interfaces {

class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void logInfo(const QString &message) = 0;
    virtual void logError(const QString &message) = 0;
};

} // namespace core::interfaces
