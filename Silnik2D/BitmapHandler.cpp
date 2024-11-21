#include "BitmapHandler.h"

BitmapHandler::BitmapHandler() : isInitialized(false) {}

BitmapHandler::~BitmapHandler() {}

bool BitmapHandler::create(unsigned int width, unsigned int height, sf::Color color) {
    // Create a blank image with a specific size and fill color
    bitmap.create(width, height, color);
    isInitialized = true;
    return true;
}

bool BitmapHandler::loadFromFile(const std::string& filePath) {
    // Load image from file
    if (bitmap.loadFromFile(filePath)) {
        isInitialized = true;
        return true;
    }
    return false;
}

bool BitmapHandler::saveToFile(const std::string& filePath) {
    // Save image to file
    if (!isInitialized) {
        return false;
    }
    return bitmap.saveToFile(filePath);
}

void BitmapHandler::clear(sf::Color color) {
    if (!isInitialized) return;

    sf::Vector2u size = bitmap.getSize();
    bitmap.create(size.x, size.y, color);
}

bool BitmapHandler::copyFrom(const BitmapHandler& source) {
    if (!source.isInitialized) return false;

    bitmap = source.bitmap;
    isInitialized = true;
    return true;
}

sf::Image BitmapHandler::getImage() const {
    return bitmap;
}

sf::Vector2u BitmapHandler::getSize() const {
    return bitmap.getSize();
}
