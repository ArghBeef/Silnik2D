#ifndef PRIMITIVERENDERER_H
#define PRIMITIVERENDERER_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include <vector>
#include <cmath>
#define M_PI 3.14159265358979323846

class PrimitiveRenderer {
public:
    PrimitiveRenderer(sf::RenderWindow& window);

    //Opisy sa w Source Files .cpp
    void drawPoint(const Point2D& point, sf::Color color);
    void drawLine(const Point2D& p0, const Point2D& p1, sf::Color color);
    void drawCircle(const Point2D& center, float radius, sf::Color color);
    void drawSquare(const Point2D& origin, float sizeX, float sizeY, sf::Color color);
    void drawTriangle(const Point2D& origin, float size, sf::Color color);
    void drawPolyline(const std::vector<Point2D>& points, bool closed , sf::Color color);


private:
    sf::RenderWindow& window;
};

#endif
