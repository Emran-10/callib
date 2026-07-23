#pragma once
#include <QString>
#include <QList>
#include <QSettings>
#include <memory>
#include "i_shortcuts_manager.h"

namespace features::shortcuts {

class ShortcutsManager : public IShortcutManager {
public:
    ShortcutsManager();
    ~ShortcutsManager();

    void registerShortcut(const QString &actionId, const ShortcutConfig &config) override;
    void unregisterShortcut(const QString &actionId) override;
    ShortcutConfig getShortcutConfig(const QString &actionId) const override;
    QList<ShortcutConfig> getAllShortcuts() const override;
    void saveShortcutSettings() override;
    void loadShortcutSettings() override;

private:
    QMap<QString, ShortcutConfig> m_shortcuts;
    std::unique_ptr<QSettings> m_settings;
    void initializeDefaultShortcuts();
};

} // namespace features::shortcuts
