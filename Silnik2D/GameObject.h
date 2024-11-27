#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void update() { return; }
    virtual void draw() { return; }
};

#endif
