#ifndef GRAPHICSASSIGNMENT2_UTILS_H
#define GRAPHICSASSIGNMENT2_UTILS_H

#include <string>

void color(short r, short g, short b);

void color(long hex);

void cylinder(double radius, double height);

void drawText(const std::string& text, int x, int y, int color);

#endif //GRAPHICSASSIGNMENT2_UTILS_H
