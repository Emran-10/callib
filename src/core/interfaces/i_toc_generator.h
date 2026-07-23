#pragma once
#include <QString>

namespace core::interfaces {

class ITocGenerator {
public:
    virtual ~ITocGenerator() = default;
    virtual QString generateToc(const QString &documentContent) = 0;
};

} // namespace core::interfaces
