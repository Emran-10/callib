#pragma once
#include "core/interfaces/i_section_manager.h"
#include <QStringList>

namespace features::section_manager {

class SectionManager : public core::interfaces::ISectionManager {
public:
    void createSection(const QString &name) override;
    QStringList getSections() const override;

private:
    QStringList m_sections;
};

} // namespace features::section_manager
