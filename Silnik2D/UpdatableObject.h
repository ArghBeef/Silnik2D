#ifndef UPDATABLEOBJECT_H
#define UPDATABLEOBJECT_H

#include "GameObject.h"

class UpdatableObject : public virtual GameObject {
public:
    virtual void update() override {
        return;
    }
};

#endif
