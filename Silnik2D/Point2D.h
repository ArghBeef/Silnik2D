#ifndef POINT2D_H
#define POINT2D_H

#include <SFML/Graphics.hpp>

// Forward declaration of sf::Color
namespace sf {
    class Color;
}

class Point2D {
public:
    Point2D();
    Point2D(int x, int y);
    Point2D(int x, int y, sf::Color colorP);

    int getX();
    int getY();

    void setX(int x);
    void setY(int y);

    sf::Color getColor();
    void setColor(const sf::Color color);

private:
    int x, y;
    sf::Color colorP;
};

#endif
