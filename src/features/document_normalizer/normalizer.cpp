#include "normalizer.h"
#include <QDebug>

namespace features::document_normalizer {

QString DocumentNormalizer::normalize(const QString &input) {
    qDebug() << "[DocumentNormalizer] Normalizing document";
    return input;
}

} // namespace features::document_normalizer
