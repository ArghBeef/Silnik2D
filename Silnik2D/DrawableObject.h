#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "GameObject.h"

class DrawableObject : public virtual GameObject {
public:
    virtual void draw() override {
        return;
    }
};

#endif
