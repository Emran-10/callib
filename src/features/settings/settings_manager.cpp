#include "settings_manager.h"

namespace features::settings {

void SettingsManager::setValue(const QString &key, const QVariant &value) {
    m_settings.setValue(key, value);
}

QVariant SettingsManager::getValue(const QString &key, const QVariant &defaultValue) const {
    return m_settings.value(key, defaultValue);
}

} // namespace features::settings
