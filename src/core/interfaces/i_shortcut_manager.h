#pragma once
#include <QString>

namespace core::interfaces {

class IShortcutManager {
public:
    virtual ~IShortcutManager() = default;
    virtual void registerShortcut(const QString &sequence, std::function<void()> callback) = 0;
};

} // namespace core::interfaces
