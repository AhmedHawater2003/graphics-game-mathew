#include "GameSettings.h"

GameSettings::GameSettings(double windowWidth, double windowHeight, bool collisionBoxesShown)
        : windowWidth(windowWidth),
          windowHeight(windowHeight),
          collisionBoxesShown(collisionBoxesShown) {}

double GameSettings::getWindowWidth() const {
    return windowWidth;
}

double GameSettings::getWindowHeight() const {
    return windowHeight;
}

double GameSettings::getAspectRatio() const {
    return windowWidth / windowHeight;
}

bool GameSettings::isCollisionBoxesShown() const {
    return collisionBoxesShown;
}

GameSettingsBuilder &GameSettingsBuilder::setWindowWidth(double newWindowWidth) {
    windowWidth = newWindowWidth;
    isWindowWidthSet = true;
    return *this;
}

GameSettingsBuilder &GameSettingsBuilder::setWindowHeight(double newWindowHeight) {
    windowHeight = newWindowHeight;
    isWindowHeightSet = true;
    return *this;
}

GameSettings *GameSettingsBuilder::build() const {
    if (!isWindowWidthSet || !isWindowHeightSet) {
        throw std::runtime_error("Window width and height must be set");
    }

    return new GameSettings(windowWidth, windowHeight, showCollisionBoxes);
}

GameSettingsBuilder &GameSettingsBuilder::setShowCollisionBoxes(bool newShowCollisionBoxes) {
    showCollisionBoxes = newShowCollisionBoxes;
    return *this;
}
