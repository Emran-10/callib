#pragma once
#include <QString>
#include <QList>
#include <QKeySequence>

namespace features::shortcuts {

struct ShortcutConfig {
    QString action_id;
    QString name_bangla;
    QString name_english;
    QString default_key;
    QKeySequence current_key;
    bool is_active;
};

class IShortcutManager {
public:
    virtual ~IShortcutManager() = default;
    virtual void registerShortcut(const QString &actionId, const ShortcutConfig &config) = 0;
    virtual void unregisterShortcut(const QString &actionId) = 0;
    virtual ShortcutConfig getShortcutConfig(const QString &actionId) const = 0;
    virtual QList<ShortcutConfig> getAllShortcuts() const = 0;
    virtual void saveShortcutSettings() = 0;
    virtual void loadShortcutSettings() = 0;
};

} // namespace features::shortcuts
