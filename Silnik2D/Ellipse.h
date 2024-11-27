#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "ShapeObject.h"

class PrimitiveRenderer;

class Ellipse : public ShapeObject {
public:
    Ellipse(Point2D center, float radiusX, float radiusY, float rotationAngle = 0.0f);

    void draw(PrimitiveRenderer& renderer);

    void translate(float dx, float dy) override;
    void scale(float factor) override;
    void rotate(float angle) override;

    void setOutlineColor(sf::Color color);
    void setFillColor(sf::Color color);

private:
    Point2D center;
    float radiusX;
    float radiusY;
    float rotationAngle;

    sf::Color outlineColor = sf::Color::White;
    sf::Color fillColor = sf::Color::White;
    bool filled = false;
};

#endif
