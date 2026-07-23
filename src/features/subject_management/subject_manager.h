#pragma once
#include "core/interfaces/i_subject_manager.h"

namespace features::subject_management {

class SubjectManager : public core::interfaces::ISubjectManager {
public:
    void addSubject(const QString &subject) override;
    void removeSubject(const QString &subject) override;
};

} // namespace features::subject_management
