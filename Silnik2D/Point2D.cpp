#include "Point2D.h"

Point2D::Point2D() : x(0), y(0), colorP(sf::Color::White) {}
Point2D::Point2D(float x, float y) : x(x), y(y), colorP(sf::Color::White) {}
Point2D::Point2D(float x, float y, sf::Color color) : x(x), y(y), colorP(color) {}

int Point2D::getX() const { return x; }
int Point2D::getY() const { return y; }
void Point2D::setX(float x) { this->x = x; }
void Point2D::setY(float y) { this->y = y; }
sf::Color Point2D::getColor() const { return colorP; }
void Point2D::setColor(const sf::Color color) { colorP = color; }

void Point2D::translate(float dx, float dy) {
    x += dx;
    y += dy;
}

void Point2D::rotate(float angle) {
	double radians = angle * M_PI / 180.0;
	x = x * cos(radians) - y * sin(radians);
	y = x * sin(radians) + y * cos(radians);
}

void Point2D::scale(float factor) {
    x *= factor;
    y *= factor;
}
