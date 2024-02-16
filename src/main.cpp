#include <Geode/Geode.hpp>
#include <Geode/modify/MusicDownloadManager.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/GameLevelManager.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;
            
        auto alert = FLAlertLayer::create("why would you do this", "I love gd cologne", "uh oh");
        alert->m_scene = this;
        alert->show();
        return true;
    }
};

class $modify(MusicDownloadManager) {
    SongInfoObject* getSongInfoObject(int p0) {
        return SongInfoObject::create(477402);
    }
};

class $modify(LevelInfoLayer) {
    bool init(GJGameLevel* p0, bool p1) {
        if (!LevelInfoLayer::init(p0, p1))
            return false;

        if (this->m_level->isPlatformer()) {
            return true;
        }

        GameLevelManager::sharedState()->downloadLevel(57436521, false);
        this->m_level = GameLevelManager::sharedState()->getSavedLevel(57436521);

        return true;
    }
};