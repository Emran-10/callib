#include "logger.h"
#include <QDebug>

namespace utilities {

void Logger::logInfo(const QString &message) {
    qInfo() << "[INFO]:" << message;
}

void Logger::logError(const QString &message) {
    qCritical() << "[ERROR]:" << message;
}

} // namespace utilities
