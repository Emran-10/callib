#include "subject_manager.h"
#include <QDebug>

namespace features::subject_management {

void SubjectManager::addSubject(const QString &subject) {
    if (!m_subjects.contains(subject)) {
        m_subjects.append(subject);
        qDebug() << "[SubjectManager] Added subject:" << subject;
    }
}

QStringList SubjectManager::getSubjects() const {
    return m_subjects;
}

} // namespace features::subject_management
