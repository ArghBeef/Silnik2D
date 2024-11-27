#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "ShapeObject.h"
#include <vector>

class PrimitiveRenderer;

class Circle : public ShapeObject {
public:
    Circle(Point2D center, float radius);
    void draw(PrimitiveRenderer& renderer);

    void setFillColor(sf::Color fill);
    void setOutlineColor(sf::Color outline);

    void translate(float dx, float dy) override;
    void scale(float factor) override;
    void rotate(float angle) override;


    Point2D center;
    float radius;

private:
    bool filled = false;
    sf::Color fillColor = sf::Color::White;
    sf::Color outlineColor = sf::Color::White;
};

#endif