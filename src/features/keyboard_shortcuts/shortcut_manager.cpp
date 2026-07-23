#include "shortcut_manager.h"

namespace features::keyboard_shortcuts {

void ShortcutManager::registerShortcut(const QString &sequence, std::function<void()> callback) {
    Q_UNUSED(sequence);
    Q_UNUSED(callback);
}

} // namespace features::keyboard_shortcuts
