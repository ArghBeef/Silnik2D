#ifndef BITMAPHANDLER_H
#define BITMAPHANDLER_H

#include <SFML/Graphics.hpp>
#include <string>

class BitmapHandler {
public:
    BitmapHandler();  // Default constructor
    ~BitmapHandler(); // Destructor

    // Functionality
    bool create(unsigned int width, unsigned int height, sf::Color color = sf::Color::White); // Create a blank bitmap
    bool loadFromFile(const std::string& filePath);                                          // Load bitmap from file
    bool saveToFile(const std::string& filePath);                                            // Save bitmap to file
    void clear(sf::Color color = sf::Color::White);                                          // Clear the bitmap with a specific color
    bool copyFrom(const BitmapHandler& source);                                              // Copy content from another bitmap

    // Accessors
    sf::Image getImage() const;                                                              // Get the underlying image
    sf::Vector2u getSize() const;                                                            // Get the bitmap size

private:
    sf::Image bitmap; // The bitmap data
    bool isInitialized; // Flag to track if the bitmap is initialized
};

#endif
