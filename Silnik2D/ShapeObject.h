#ifndef SHAPEOBJECT_H
#define SHAPEOBJECT_H

#include "DrawableObject.h"
#include "TransformableObject.h"

class PrimitiveRenderer;

/**
 * @class ShapeObject
 * @brief Klasa bazowa dla prymitywow
 *
 * Jest klasa bazowa ą dla wszystkich obiektów gry, które mogą zostać narysowane
z użyciem prymitywów
 *
 */
class ShapeObject : public DrawableObject, public TransformableObject {
public:
/**
* @brief Rysowanie obiektu
*
* Metoda rysuje obiekt
*/
    virtual void draw(PrimitiveRenderer& renderer) { return; }
    virtual void translate(float dx, float dy) override { return; }
    virtual void rotate(float angle) override { return; }
    virtual void scale(float factor) override { return; }
};

#endif
