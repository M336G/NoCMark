#include <Geode/Geode.hpp>
#include <Geode/modify/ShareLevelLayer.hpp>
#include "../managers/SettingsManager.h"

using namespace geode::prelude;

// i did NOT have a great time modifying GD's ui so as long as this works i'm not touching this ever again LOL
class $modify(ShareLevelLayer) {
    bool init(GJGameLevel *level) {
        if (!ShareLevelLayer::init(level))
            return false;

        if (SettingsManager::DisableMod || !level || !level->m_originalLevel)
            return true;

        if (auto *acknowledgementText = m_mainLayer->getChildByType<TextArea>(2)) {
            acknowledgementText->setPositionY(acknowledgementText->getPositionY() + 10.f);

            auto *warningText = TextArea::create(
                "<cy>This level will not show the (C) mark.</c>",
                "chatFont.fnt",
                1.0f,
                acknowledgementText->getContentWidth() / acknowledgementText->getScale(),
                acknowledgementText->getAnchorPoint(),
                acknowledgementText->getContentHeight() / acknowledgementText->getScale(),
                false
            );

            warningText->setScale(acknowledgementText->getScale());
            warningText->setPosition({
                acknowledgementText->getPositionX(),
                acknowledgementText->getPositionY() - 25.f
            });

            warningText->setID("no-c-mark-warning-text-area"_spr);
            m_mainLayer->addChild(warningText);
        }

        return true;
    }
};