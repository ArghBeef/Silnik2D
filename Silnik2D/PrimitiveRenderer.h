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
    std::vector<Point2D> points;
    sf::Image drawingBuffer;
    std::vector<Point2D> filledAreas;
    PrimitiveRenderer(sf::RenderWindow& window);

    void draw();
    void drawPoint(Point2D point);
    void drawLine(Point2D p0, Point2D p1, sf::Color color);
    void fillColor(Point2D origin, sf::Color fill_color, sf::Color background_color);

    const sf::Image& getDrawingBuffer() const {
        return drawingBuffer;
    }

private:
    sf::RenderWindow& window;
};

#endif
