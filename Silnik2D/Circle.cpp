#include "Circle.h"
#include "PrimitiveRenderer.h"

Circle::Circle(Point2D center, float radius)
    : center(center), radius(radius) {}


void Circle::draw(PrimitiveRenderer& renderer) {
    float a, step;
    int x, y;
    int xc = center.getX();
    int yc = center.getY();

    step = 1.0f / radius;

    for (a = 0; a < 2 * M_PI; a += step) {
        x = xc + radius * cos(a) + 0.5f;
        y = yc + radius * sin(a) + 0.5f;

        Point2D point(x, y, outlineColor);
        renderer.drawPoint(point);
    }

    if (filled) {
        //renderer.fillColor(center, fillColor, sf::Color::Black);
        renderer.boundaryFill(center, fillColor, outlineColor);
    }
}

void Circle::setFillColor(sf::Color fillColor) {
    this->fillColor = fillColor;
    filled = true;
}

void Circle::setOutlineColor(sf::Color outlineColor) {
    this->outlineColor = outlineColor;
}

void Circle::translate(float dx, float dy) {
    center.translate(dx, dy);
}

void Circle::rotate(float angle) {
    center.rotate(angle);
}

void Circle::scale(float factor) {
    radius *= factor;
}