#pragma once
#include "core/interfaces/i_file_handler.h"

namespace utilities {

class FileHandler : public core::interfaces::IFileHandler {
public:
    bool writeToFile(const QString &filePath, const QString &content) override;
    QString readFromFile(const QString &filePath) override;
};

} // namespace utilities
