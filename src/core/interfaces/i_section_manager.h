#pragma once
#include <QStringList>

namespace core::interfaces {

class ISectionManager {
public:
    virtual ~ISectionManager() = default;
    virtual void createSection(const QString &name) = 0;
    virtual QStringList getSections() const = 0;
};

} // namespace core::interfaces
