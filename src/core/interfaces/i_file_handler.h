#pragma once
#include <QString>

namespace core::interfaces {

class IFileHandler {
public:
    virtual ~IFileHandler() = default;
    virtual bool writeToFile(const QString &filePath, const QString &content) = 0;
    virtual QString readFromFile(const QString &filePath) = 0;
};

} // namespace core::interfaces
