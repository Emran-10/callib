#pragma once
#include "core/interfaces/i_settings_manager.h"
#include <QVariant>
#include <QMap>

namespace features::settings {

class SettingsManager : public core::interfaces::ISettingsManager {
public:
    void setValue(const QString &key, const QVariant &value) override;
    QVariant getValue(const QString &key, const QVariant &defaultValue = QVariant()) const override;

private:
    QMap<QString, QVariant> m_settings;
};

} // namespace features::settings
