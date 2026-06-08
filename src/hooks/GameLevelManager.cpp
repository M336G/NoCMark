#include <Geode/Geode.hpp>
#include <Geode/modify/GameLevelManager.hpp>
#include "../managers/SettingsManager.h"

using namespace geode::prelude;

class $modify(GameLevelManager) {
    void uploadLevel(GJGameLevel *level) {
        if (SettingsManager::DisableMod || !level)
            return GameLevelManager::uploadLevel(level);

        level->m_originalLevel = 0;

        GameLevelManager::uploadLevel(level);
    }
};