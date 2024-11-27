#ifndef BITMAPOBJECT_H
#define BITMAPOBJECT_H

#include "SpriteObject.h"
#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>
#include <vector>

class BitmapObject : public SpriteObject {
public:
    BitmapObject();
    ~BitmapObject() override;

    void draw(sf::RenderWindow& window);
    void animate(float deltaTime) override;

    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factor) override;

    void addBitmap(const BitmapHandler& bitmap);
    void removeBitmap(int index);
    void setActiveBitmap(int index);

    float frame = 0.2f;

private:
    sf::Texture texture;
    std::vector<BitmapHandler> bitmaps;
    sf::Transform transform;
    int activeBitmapIndex = 0;

    float frameTimer = 0.0f;
};

#endif
