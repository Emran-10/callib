#include "toc_generator.h"
#include <QDebug>

namespace features::toc_generator {

QString TocGenerator::generateTOC(const QString &document) {
    qDebug() << "[TocGenerator] Generating table of contents";
    return "Table of Contents\n";
}

} // namespace features::toc_generator
