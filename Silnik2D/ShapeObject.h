#ifndef SHAPEOBJECT_H
#define SHAPEOBJECT_H

#include "DrawableObject.h"
#include "TransformableObject.h"

class PrimitiveRenderer;

class ShapeObject : public DrawableObject, public TransformableObject {
public:
    virtual void draw(PrimitiveRenderer& renderer) { return; }
    virtual void translate(float dx, float dy) override { return; }
    virtual void rotate(float angle) override { return; }
    virtual void scale(float factor) override { return; }
};

#endif
