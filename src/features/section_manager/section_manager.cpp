#include "section_manager.h"
#include <QDebug>

namespace features::section_manager {

void SectionManager::createSection(const QString &name) {
    if (!m_sections.contains(name)) {
        m_sections.append(name);
        qDebug() << "[SectionManager] Created section:" << name;
    }
}

QStringList SectionManager::getSections() const {
    return m_sections;
}

} // namespace features::section_manager
