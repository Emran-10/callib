#include "shortcuts_manager.h"
#include <QDebug>
#include <QStandardPaths>
#include <QDir>

namespace features::shortcuts {

ShortcutsManager::ShortcutsManager() {
    QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(appDataPath);
    
    m_settings = std::make_unique<QSettings>(
        appDataPath + "/callib.ini", 
        QSettings::IniFormat
    );
    
    initializeDefaultShortcuts();
    loadShortcutSettings();
}

ShortcutsManager::~ShortcutsManager() = default;

void ShortcutsManager::initializeDefaultShortcuts() {
    ShortcutConfig captureConfig{
        "capture_screenshot",
        "স্ক্রিনশট ক্যাপচার",
        "Capture Screenshot",
        "Ctrl+C",
        QKeySequence("Ctrl+C"),
        true
    };
    m_shortcuts["capture_screenshot"] = captureConfig;

    ShortcutConfig startCapture{
        "start_capture",
        "ক্যাপচার শুরু করুন",
        "Start Capture",
        "Ctrl+S",
        QKeySequence("Ctrl+S"),
        true
    };
    m_shortcuts["start_capture"] = startCapture;

    ShortcutConfig stopCapture{
        "stop_capture",
        "ক্যাপচার থামান",
        "Stop Capture",
        "Ctrl+E",
        QKeySequence("Ctrl+E"),
        true
    };
    m_shortcuts["stop_capture"] = stopCapture;

    ShortcutConfig addImage{
        "add_image",
        "ছবি যুক্ত করুন",
        "Add Image",
        "Ctrl+I",
        QKeySequence("Ctrl+I"),
        true
    };
    m_shortcuts["add_image"] = addImage;
}

void ShortcutsManager::registerShortcut(const QString &actionId, const ShortcutConfig &config) {
    m_shortcuts[actionId] = config;
    qDebug() << "[ShortcutsManager] Registered shortcut:" << actionId;
}

void ShortcutsManager::unregisterShortcut(const QString &actionId) {
    m_shortcuts.remove(actionId);
    qDebug() << "[ShortcutsManager] Unregistered shortcut:" << actionId;
}

ShortcutConfig ShortcutsManager::getShortcutConfig(const QString &actionId) const {
    return m_shortcuts.value(actionId);
}

QList<ShortcutConfig> ShortcutsManager::getAllShortcuts() const {
    return m_shortcuts.values();
}

void ShortcutsManager::saveShortcutSettings() {
    if (!m_settings) return;
    
    m_settings->beginGroup("Shortcuts");
    for (auto it = m_shortcuts.begin(); it != m_shortcuts.end(); ++it) {
        m_settings->setValue(it.key(), it.value().current_key.toString());
    }
    m_settings->endGroup();
    m_settings->sync();
    qDebug() << "[ShortcutsManager] Shortcuts saved";
}

void ShortcutsManager::loadShortcutSettings() {
    if (!m_settings) return;
    
    m_settings->beginGroup("Shortcuts");
    for (auto it = m_shortcuts.begin(); it != m_shortcuts.end(); ++it) {
        QString savedKey = m_settings->value(it.key(), it.value().default_key).toString();
        it.value().current_key = QKeySequence(savedKey);
    }
    m_settings->endGroup();
    qDebug() << "[ShortcutsManager] Shortcuts loaded";
}

} // namespace features::shortcuts
