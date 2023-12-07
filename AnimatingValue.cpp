#include "AnimatingValue.h"

AnimatingValue::AnimatingValue(float value, float max, float speed)
        : value(value), max(max), speed(speed) {}

void AnimatingValue::animate() {
    if (animating) {
        value += speed * direction;

        if (value >= max) {
            value = max;
            if (repeating || twoWay) {
                direction = -1;
            }
            else {
                animating = false;
            }
        } else {
            if (twoWay) {
                if (value <= -max) {
                    if (repeating) {
                        direction = 1;
                    }
                    else {
                        animating = false;
                    }
                }
            } else {
                if (value <= 0) {
                    value = 0;
                    if (repeating) {
                        direction = 1;
                    }
                    else {
                        animating = false;
                    }
                }
            }
        }
    }
}

void AnimatingValue::stop() {
    animating = false;
}

void AnimatingValue::start() {
    animating = true;
}

void AnimatingValue::toggle() {
    animating = !animating;
}

double AnimatingValue::getValue() {
    return value;
}

AnimatingValue* AnimatingValue::setTwoWay(bool twoWay)
{
    this->twoWay = twoWay;
	return this;
}

AnimatingValue* AnimatingValue::setRepeating(bool repeating)
{
    this->repeating = repeating;
	return this;
}
