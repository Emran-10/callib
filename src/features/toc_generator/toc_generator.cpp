#include "toc_generator.h"

namespace features::toc_generator {

QString TocGenerator::generateToc(const QString &documentContent) {
    Q_UNUSED(documentContent);
    return "Table of Contents\n1. Introduction\n2. Content";
}

} // namespace features::toc_generator
