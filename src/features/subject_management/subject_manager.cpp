#include "subject_manager.h"

namespace features::subject_management {

void SubjectManager::addSubject(const QString &subject) {
    if (!m_subjects.contains(subject)) m_subjects.append(subject);
}

QStringList SubjectManager::getSubjects() const {
    return m_subjects;
}

} // namespace features::subject_management
