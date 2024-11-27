#ifndef UPDATABLEOBJECT_H
#define UPDATABLEOBJECT_H

#include "GameObject.h"

/**
 * @class UpdatableObject
 * @brief Klasa bazowa dla obiektów, ktore są aktualizowane
 *
 * Jest klasa bazowa dla obiektow aktualizowanych, dziedziczy po klasie GameObject
 *
 */
class UpdatableObject : public virtual GameObject {
public:
    virtual void update() override {
        return;
    }
};

#endif
