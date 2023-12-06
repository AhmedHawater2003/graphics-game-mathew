#ifndef GRAPHICSASSIGNMENT2_ANIMATINGVALUE_H
#define GRAPHICSASSIGNMENT2_ANIMATINGVALUE_H


class AnimatingValue {
    float value;
    float max;
    float speed;
    float direction = 1;
    bool animating = false;
    bool twoWay;
    bool repeating;

public:
    AnimatingValue(float value, float max, float speed, bool twoWay = false, bool repeating = true);

    void animate();

    void stop();

    void start();

    void toggle();

    double getValue();
};


#endif //GRAPHICSASSIGNMENT2_ANIMATINGVALUE_H
