#include "settings_manager.h"
#include <QDebug>
#include <QSettings>

namespace features::settings {

void SettingsManager::saveSetting(const QString &key, const QString &value) {
    QSettings settings("CalLib", "CalLib");
    settings.setValue(key, value);
    qDebug() << "[SettingsManager] Saved" << key << "->" << value;
}

QString SettingsManager::loadSetting(const QString &key) {
    QSettings settings("CalLib", "CalLib");
    qDebug() << "[SettingsManager] Loading" << key;
    return settings.value(key, "").toString();
}

} // namespace features::settings
