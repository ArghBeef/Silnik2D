#ifndef POINT2D_H
#define POINT2D_H

#include <SFML/Graphics.hpp>
#include "TransformableObject.h"

class Point2D : public TransformableObject {
public:
    Point2D();
    Point2D(float x, float y);
    Point2D(float x, float y, sf::Color colorP);

    int getX() const;
    int getY() const;
    void setX(float x);
    void setY(float y);
    sf::Color getColor() const;
    void setColor(const sf::Color color);

    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factor) override;

private:
    float x, y;
    sf::Color colorP;
};

#endif
