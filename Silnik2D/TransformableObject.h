#ifndef TRANSFORMABLEOBJECT_H
#define TRANSFORMABLEOBJECT_H

#include <cmath>
#define M_PI 3.14159265358979323846

class TransformableObject {
public:
    virtual ~TransformableObject() = default;

    virtual void translate(float dx, float dy){return;}
    virtual void rotate(float angle) { return; }
    virtual void scale(float factor) { return; }
};

#endif
