#pragma once
#include <QStringList>

namespace core::interfaces {

class ISubjectManager {
public:
    virtual ~ISubjectManager() = default;
    virtual void addSubject(const QString &subject) = 0;
    virtual QStringList getSubjects() const = 0;
};

} // namespace core::interfaces
