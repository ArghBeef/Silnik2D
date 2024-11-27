#ifndef POLYGON_H
#define POLYGON_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "ShapeObject.h"
#include <vector>

class PrimitiveRenderer;

class Polygon : public ShapeObject {
public:
    Polygon(const std::vector<Point2D>& points, bool closed);
    void draw(PrimitiveRenderer& renderer);

    void setFillColor(const sf::Color& fill);
    void setOutlineColor(const sf::Color& outline);

    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factor) override;

    std::vector<Point2D> points;
    Point2D origin;

private:
    bool closed = false;
    bool filled = false;
    sf::Color fillColor = sf::Color::White;
    sf::Color outlineColor = sf::Color::Red;
};

#endif