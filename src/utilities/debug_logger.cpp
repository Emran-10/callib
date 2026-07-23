#include "debug_logger.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

namespace utilities::logging {

void DebugLogger::log(const QString &message) {
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString logMessage = QString("[%1] %2").arg(timestamp, message);
    
    qDebug() << logMessage;
    
    QString filePath = getLogFilePath();
    logToFile(filePath, logMessage);
}

void DebugLogger::logToFile(const QString &filePath, const QString &message) {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << message << "\n";
        file.close();
    }
}

QString DebugLogger::getLogFilePath() {
    QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(appDataPath);
    return appDataPath + "/callib_debug.log";
}

void DebugLogger::clearLogs() {
    QString filePath = getLogFilePath();
    QFile file(filePath);
    if (file.exists()) {
        file.remove();
    }
}

} // namespace utilities::logging
