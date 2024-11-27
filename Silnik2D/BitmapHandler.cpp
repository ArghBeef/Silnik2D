#include "BitmapHandler.h"

BitmapHandler::BitmapHandler() : isInitialized(false) {}


bool BitmapHandler::create(unsigned int width, unsigned int height, sf::Color color) {
    bitmap.create(width, height, color);
    isInitialized = true;
    return true;
}

bool BitmapHandler::loadFromFile(const std::string& filePath) {
    if (bitmap.loadFromFile(filePath)) {
        isInitialized = true;
        return true;
    }
    return false;
}

bool BitmapHandler::saveToFile(const std::string& filePath) {
    if (!isInitialized) {
        return false;
    }
    return bitmap.saveToFile(filePath);
}

void BitmapHandler::clear(sf::Color color) {
    if (!isInitialized) return;

    sf::Vector2u size = bitmap.getSize();
    for (unsigned int y = 0; y < size.y; ++y) {
        for (unsigned int x = 0; x < size.x; ++x) {
            bitmap.setPixel(x, y, color);
        }
    }
}

bool BitmapHandler::copyFrom(const BitmapHandler& source) {
    if (!source.isInitialized) return false;

    bitmap = source.bitmap;
    isInitialized = true;
    return true;
}

const sf::Image& BitmapHandler::getImage() const {
    return bitmap;
}

sf::Vector2u BitmapHandler::getSize() const {
    return bitmap.getSize();
}
