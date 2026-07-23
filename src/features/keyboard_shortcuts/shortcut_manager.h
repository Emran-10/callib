#pragma once
#include "core/interfaces/i_shortcut_manager.h"

namespace features::keyboard_shortcuts {

class ShortcutManager : public core::interfaces::IShortcutManager {
public:
    void registerShortcut(const QString &sequence, std::function<void()> callback) override;
};

} // namespace features::keyboard_shortcuts
