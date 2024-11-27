#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "GameObject.h"

/**
 * @class DrawableObject
 * @brief Klasa bazowa dla obiektów, ktore są narysowane
 *
 * Jest klasa bazowa dla obiektow narysowanych, dziedziczy po klasie GameObject
 *
 */
class DrawableObject : public virtual GameObject {
public:
    virtual void draw() override {
        return;
    }
};

#endif
