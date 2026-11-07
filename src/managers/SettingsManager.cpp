#include "SettingsManager.hpp"

using namespace geode::prelude;

bool SettingsManager::DisableMod = Mod::get()->getSettingValue<bool>("disable-mod");

$execute {
    listenForSettingChanges<bool>("disable-mod", [](bool enabled) {
        SettingsManager::DisableMod = enabled;
    });
};