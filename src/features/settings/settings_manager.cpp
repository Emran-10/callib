#include "settings_manager.h"
#include <QDebug>
#include <QSettings>

namespace features::settings {

void SettingsManager::setValue(const QString &key, const QVariant &value) {
    m_settings[key] = value;
    qDebug() << "[SettingsManager] Saved" << key << "->" << value.toString();
}

QVariant SettingsManager::getValue(const QString &key, const QVariant &defaultValue) const {
    qDebug() << "[SettingsManager] Loading" << key;
    return m_settings.value(key, defaultValue);
}

} // namespace features::settings
