#ifndef GRAPHICSASSIGNMENT2_GAMESETTINGS_H
#define GRAPHICSASSIGNMENT2_GAMESETTINGS_H


#include <stdexcept>

class GameSettings {
    double windowWidth, windowHeight;
    bool collisionBoxesShown = false;
public:
    bool isCollisionBoxesShown() const;

public:
    GameSettings(double windowWidth, double windowHeight, bool collisionBoxesShown);

    [[nodiscard]] double getWindowWidth() const;

    [[nodiscard]] double getWindowHeight() const;

    [[nodiscard]] double getAspectRatio() const;
};


class GameSettingsBuilder {
    double windowWidth{}, windowHeight{};
    bool isWindowWidthSet = false, isWindowHeightSet = false;

    bool showCollisionBoxes = false;
public:
    GameSettingsBuilder &setWindowWidth(double newWindowWidth);

    GameSettingsBuilder &setWindowHeight(double newWindowHeight);

    GameSettingsBuilder &setShowCollisionBoxes(bool newShowCollisionBoxes);

    [[nodiscard]] GameSettings *build() const;
};


#endif //GRAPHICSASSIGNMENT2_GAMESETTINGS_H
