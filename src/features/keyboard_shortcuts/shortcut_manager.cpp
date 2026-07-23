#include "shortcut_manager.h"
#include <QDebug>

namespace features::keyboard_shortcuts {

void ShortcutManager::registerShortcut(const QString &name, const QString &key) {
    qDebug() << "[ShortcutManager] Registering shortcut" << name << "->" << key;
}

void ShortcutManager::triggerAction(const QString &name) {
    qDebug() << "[ShortcutManager] Triggering action:" << name;
}

} // namespace features::keyboard_shortcuts
