#include "section_manager.h"
#include <QDebug>

namespace features::section_manager {

void SectionManager::createSection(const QString &name) {
    qDebug() << "[SectionManager] Creating section:" << name;
}

void SectionManager::deleteSection(const QString &name) {
    qDebug() << "[SectionManager] Deleting section:" << name;
}

} // namespace features::section_manager
