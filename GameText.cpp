#include "GameText.h"
#include "utils.h"


void GameText::draw() {
    if(Game::getInstance()->isIsFirstScene())
        drawText(text, 0.9f, 0.9f, 0xFF0000); // Red color for visibility
    else
        drawText(text, 0.9f, 0.9f, 0xFFFF00); // Red color for visibility
}

GameText *GameText::setText(std::string newText)
{
    text = newText;
    return this;
}
