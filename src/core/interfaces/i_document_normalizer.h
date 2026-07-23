#pragma once
#include <QString>

namespace core::interfaces {

class IDocumentNormalizer {
public:
    virtual ~IDocumentNormalizer() = default;
    virtual QString normalize(const QString &input) = 0;
};

} // namespace core::interfaces
