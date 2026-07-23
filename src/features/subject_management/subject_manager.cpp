#include "subject_manager.h"
#include <QDebug>

namespace features::subject_management {

void SubjectManager::addSubject(const QString &subject) {
    qDebug() << "[SubjectManager] Adding subject:" << subject;
}

void SubjectManager::removeSubject(const QString &subject) {
    qDebug() << "[SubjectManager] Removing subject:" << subject;
}

} // namespace features::subject_management
