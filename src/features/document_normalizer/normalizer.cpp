#include "normalizer.h"
#include <QDebug>

namespace features::document_normalizer {

QString DocumentNormalizer::normalize(const QString &document) {
    qDebug() << "[DocumentNormalizer] Normalizing document";
    return document;
}

} // namespace features::document_normalizer
