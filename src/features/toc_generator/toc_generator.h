#pragma once
#include "core/interfaces/i_toc_generator.h"

namespace features::toc_generator {

class TocGenerator : public core::interfaces::ITocGenerator {
public:
    QString generateToc(const QString &documentContent) override;
};

} // namespace features::toc_generator
