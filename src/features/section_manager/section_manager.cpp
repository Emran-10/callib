#include "section_manager.h"

namespace features::section_manager {

void SectionManager::createSection(const QString &name) {
    m_sections.append(name);
}

QStringList SectionManager::getSections() const {
    return m_sections;
}

} // namespace features::section_manager
