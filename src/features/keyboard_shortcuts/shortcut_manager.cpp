#include "shortcut_manager.h"
#include <QDebug>

namespace features::keyboard_shortcuts {

void ShortcutManager::registerShortcut(const QString &sequence, std::function<void()> callback) {
    qDebug() << "[ShortcutManager] Registering shortcut:" << sequence;
    if (callback) {
        callback();
    }
}

} // namespace features::keyboard_shortcuts
