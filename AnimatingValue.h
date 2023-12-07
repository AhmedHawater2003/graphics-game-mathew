#ifndef GRAPHICSASSIGNMENT2_ANIMATINGVALUE_H
#define GRAPHICSASSIGNMENT2_ANIMATINGVALUE_H


class AnimatingValue {
    float value;
    float max;
    float speed;
    float direction = 1;
    bool animating = false;
    bool twoWay = false;
    bool repeating = true;

public:
    AnimatingValue(float value, float max, float speed);

    void animate();

    void stop();

    void start();

    void toggle();

    double getValue();

    AnimatingValue *setTwoWay(bool twoWay);

    AnimatingValue *setRepeating(bool repeating);
};


#endif //GRAPHICSASSIGNMENT2_ANIMATINGVALUE_H
