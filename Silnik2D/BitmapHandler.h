#ifndef BITMAPHANDLER_H
#define BITMAPHANDLER_H

#include <SFML/Graphics.hpp>
#include <string>

class BitmapHandler {
public:
    BitmapHandler();
    ~BitmapHandler();

    bool create(unsigned int width, unsigned int height, sf::Color color = sf::Color::White);
    bool loadFromFile(const std::string& filePath);
    bool saveToFile(const std::string& filePath);
    void clear(sf::Color color = sf::Color::White);
    bool copyFrom(const BitmapHandler& source);

    const sf::Image& getImage() const;
    sf::Vector2u getSize() const;

private:
    sf::Image bitmap;
    bool isInitialized;
};

#endif
