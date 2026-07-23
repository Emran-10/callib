#pragma once
#include "core/interfaces/i_logger.h"

namespace utilities {

class Logger : public core::interfaces::ILogger {
public:
    void logInfo(const QString &message) override;
    void logError(const QString &message) override;
};

} // namespace utilities
