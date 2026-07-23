#include "file_handler.h"
#include <QFile>
#include <QTextStream>

namespace utilities {

bool FileHandler::writeToFile(const QString &filePath, const QString &content) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
    QTextStream out(&file);
    out << content;
    return true;
}

QString FileHandler::readFromFile(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return {};
    QTextStream in(&file);
    return in.readAll();
}

} // namespace utilities
