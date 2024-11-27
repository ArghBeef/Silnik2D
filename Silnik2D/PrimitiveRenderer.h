#ifndef PRIMITIVERENDERER_H
#define PRIMITIVERENDERER_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include <vector>
#include <queue>
#include <iostream>
#include "Circle.h"
#include "Polygon.h"

class PrimitiveRenderer {
public:
    PrimitiveRenderer(sf::RenderWindow& window);

    void draw();
    void drawPoint(Point2D point);
    void drawLine(Point2D p0, Point2D p1, sf::Color color);
    void fillColor(Point2D origin, sf::Color fill_color, sf::Color background_color);
    void boundaryFill(Point2D point, sf::Color fill_color, sf::Color boundary_color);

    void resetBuffer();

private:
    sf::RenderWindow& window;
    sf::RenderTexture renderTexture;
};

#endif
