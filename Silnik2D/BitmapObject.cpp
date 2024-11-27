#include "BitmapObject.h"

BitmapObject::BitmapObject() = default;

BitmapObject::~BitmapObject() {
    bitmaps.clear();
}


void BitmapObject::draw(sf::RenderWindow& window) {
    if (bitmaps.empty()) return;

    sf::Sprite sprite;

    const BitmapHandler& activeBitmap = bitmaps[activeBitmapIndex];
    if (texture.loadFromImage(activeBitmap.getImage())) {
        sprite.setTexture(texture);

        sprite.setPosition(transform.transformPoint(0, 0));
        window.draw(sprite);
    }
}

void BitmapObject::animate(float deltaTime) {
    frameTimer += deltaTime;

    if (frameTimer >= frame) {
        frameTimer -= frame;

        activeBitmapIndex = (activeBitmapIndex + 1) % bitmaps.size();
    }
}
void BitmapObject::translate(float dx, float dy) {
    transform.translate(dx, dy);
}

void BitmapObject::rotate(float angle) {
    transform.rotate(angle);
}

void BitmapObject::scale(float factor) {
    transform.scale(factor, factor);
}

void BitmapObject::addBitmap(const BitmapHandler& bitmap) {
    bitmaps.push_back(bitmap);
}

void BitmapObject::removeBitmap(int index) {
    if (index < bitmaps.size()) {
        bitmaps.erase(bitmaps.begin() + index);
    }
}

void BitmapObject::setActiveBitmap(int index) {
    if (index < bitmaps.size()) {
        activeBitmapIndex = index;
    }
}
