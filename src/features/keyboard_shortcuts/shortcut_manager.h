#pragma once
#include "core/interfaces/i_shortcut_manager.h"

namespace features::keyboard_shortcuts {

class ShortcutManager : public core::interfaces::IShortcutManager {
public:
    void registerShortcut(const QString &name, const QString &key) override;
    void triggerAction(const QString &name) override;
};

} // namespace features::keyboard_shortcuts
