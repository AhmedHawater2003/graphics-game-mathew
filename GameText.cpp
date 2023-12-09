#include "GameText.h"
#include "utils.h"

void GameText::draw() {
    drawText(text, 0, 0, 0xFFFFFF);
}

GameText *GameText::setText(std::string newText)
{
    text = newText;
    return this;
}
