#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "DrawableObject.h"
#include "TransformableObject.h"
#include "AnimatedObject.h"

class SpriteObject : public DrawableObject, public TransformableObject, public AnimatedObject {
public:
    virtual ~SpriteObject() = default;

    virtual void translate(float dx, float dy) override = 0;
    virtual void rotate(float angle) override = 0;
    virtual void scale(float factor) override = 0;

    virtual void animate(float deltaTime) override = 0;

    //virtual void draw() override = 0;
};

#endif
