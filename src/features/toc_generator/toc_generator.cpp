#include "toc_generator.h"
#include <QDebug>
#include <QStringList>

namespace features::toc_generator {

QString TocGenerator::generateToc(const QString &documentContent) {
    qDebug() << "[TocGenerator] Generating table of contents";
    // Simple placeholder - would parse headings from documentContent
    return "Table of Contents\n1. Introduction\n2. Main Content\n3. Conclusion\n";
}

} // namespace features::toc_generator
