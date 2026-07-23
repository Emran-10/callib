#pragma once
#include <QString>
#include <QList>

namespace utilities::logging {

class DebugLogger {
public:
    static void log(const QString &message);
    static void logToFile(const QString &filePath, const QString &message);
    static QString getLogFilePath();
    static void clearLogs();

private:
    DebugLogger();
};

} // namespace utilities::logging
