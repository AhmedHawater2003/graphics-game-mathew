#include "GameText.h"
#include "utils.h"

void GameText::draw() {
    drawText(text, 0, 0, 0xFF0000);
}

GameText *GameText::setText(std::string newText)
{
    text = newText;
    return this;
}
