#pragma once
#include "core/interfaces/i_section_manager.h"

namespace features::section_manager {

class SectionManager : public core::interfaces::ISectionManager {
public:
    void createSection(const QString &name) override;
    void deleteSection(const QString &name) override;
};

} // namespace features::section_manager
