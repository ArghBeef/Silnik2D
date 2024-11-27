#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H


class AnimatedObject{
public:
    virtual ~AnimatedObject() {}

    virtual void animate(float deltaTime) { return; }

};

#endif
