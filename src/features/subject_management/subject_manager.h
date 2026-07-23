#pragma once
#include "core/interfaces/i_subject_manager.h"

namespace features::subject_management {

class SubjectManager : public core::interfaces::ISubjectManager {
public:
    void addSubject(const QString &subject) override;
    QStringList getSubjects() const override;
private:
    QStringList m_subjects;
};

} // namespace features::subject_management
