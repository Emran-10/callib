#pragma once
#include "core/interfaces/i_settings_manager.h"

namespace features::settings {

class SettingsManager : public core::interfaces::ISettingsManager {
public:
    void saveSetting(const QString &key, const QString &value) override;
    QString loadSetting(const QString &key) override;
};

} // namespace features::settings
