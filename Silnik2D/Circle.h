#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "TransformableObject.h"
#include <vector>
#include <cmath>
#define M_PI 3.14159265358979323846

class PrimitiveRenderer; // Forward declaration of PrimitiveRenderer

class Circle : public TransformableObject {
public:
    Circle(Point2D center, float radius);
    void draw(PrimitiveRenderer& renderer);

    void setFillColor(sf::Color fill);
    void setOutlineColor(sf::Color outline);

    // TransformableObject methods
    void translate(float dx, float dy) override;
    void rotate(float angle) override; // Rotation doesn't apply directly to circles
    void scale(float factor) override;

    Point2D center;
    float radius;

private:
    bool filled = false;
    sf::Color fillColor = sf::Color::White;
    sf::Color outlineColor = sf::Color::White;
};

#endif
