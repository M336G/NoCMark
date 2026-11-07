#include <Geode/Geode.hpp>
#include <Geode/modify/GameLevelManager.hpp>
#include "../managers/SettingsManager.hpp"

using namespace geode::prelude;

class $modify(GameLevelManager) {
    void uploadLevel(GJGameLevel *level) {
        if (SettingsManager::DisableMod || !level || !level->m_originalLevel)
            return GameLevelManager::uploadLevel(level);

        auto originalLevelId = level->m_originalLevel;

        level->m_originalLevel = 0;
        GameLevelManager::uploadLevel(level);
        level->m_originalLevel = originalLevelId;
    }
};