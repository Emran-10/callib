#pragma once
#include <QVariant>
#include <QString>

namespace core::interfaces {

class ISettingsManager {
public:
    virtual ~ISettingsManager() = default;
    virtual void setValue(const QString &key, const QVariant &value) = 0;
    virtual QVariant getValue(const QString &key, const QVariant &defaultValue = QVariant()) const = 0;
};

} // namespace core::interfaces
