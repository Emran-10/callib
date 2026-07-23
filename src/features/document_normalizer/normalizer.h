#pragma once
#include "core/interfaces/i_document_normalizer.h"

namespace features::document_normalizer {

class DocumentNormalizer : public core::interfaces::IDocumentNormalizer {
public:
    QString normalize(const QString &input) override;
};

} // namespace features::document_normalizer
