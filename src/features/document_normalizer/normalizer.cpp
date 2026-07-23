#include "normalizer.h"

namespace features::document_normalizer {

QString DocumentNormalizer::normalize(const QString &input) {
    return input.trimmed();
}

} // namespace features::document_normalizer
