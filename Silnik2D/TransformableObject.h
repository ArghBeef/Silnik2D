#ifndef TRANSFORMABLEOBJECT_H
#define TRANSFORMABLEOBJECT_H

class TransformableObject {
public:
    virtual ~TransformableObject() = default;

    // Abstract methods for geometric transformations
    virtual void translate(float dx, float dy) = 0;
    virtual void rotate(float angle) = 0;
    virtual void scale(float factor) = 0;
};

#endif
