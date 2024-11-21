#include "Point2D.h"


Point2D::Point2D() {
    x = 0;
    y = 0;
    colorP = sf::Color::White;
}
Point2D::Point2D(int x, int y)
    : x(x), y(y) {
    colorP = sf::Color::White;
}

Point2D::Point2D(int x, int y,sf::Color color)
    : x(x), y(y), colorP(color) {}


// Function implementations

int Point2D::getX(){
    return x;
}

int Point2D::getY(){
    return y;
}

void Point2D::setX(int x) {
    this->x = x;
}

void Point2D::setY(int y) {
    this->y = y;
}

sf::Color Point2D::getColor(){
    return colorP;
}

void Point2D::setColor(const sf::Color color) {
    colorP = color;
}

