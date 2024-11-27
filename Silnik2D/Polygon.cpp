#include "Polygon.h"
#include "PrimitiveRenderer.h"
#include <cmath>

Polygon::Polygon(const std::vector<Point2D>& points, bool closed)
    : points(points), closed(closed) {
}

void Polygon::setFillColor(sf::Color color) {
    fillColor = color;
    filled = true;
}

void Polygon::setOutlineColor(sf::Color color) {
    outlineColor = color;
}

void Polygon::draw(PrimitiveRenderer& renderer) {
    for (int i = 0; i < points.size() - 1; ++i) {
        renderer.drawLine(points[i], points[i + 1], outlineColor);
    }

    if (closed) {
        renderer.drawLine(points.back(), points[0], outlineColor);
    }

    if (filled) {
        //renderer.fillColor(origin, fillColor, sf::Color::Black);
        renderer.boundaryFill(origin, fillColor, outlineColor);
    }
}

void Polygon::translate(float dx, float dy) {
    for (auto& point : points) {
        point.translate(dx, dy);
    }
    origin.translate(dx, dy);
}

void Polygon::rotate(float angle) {
    float radians = angle * M_PI / 180.0f;
    for (auto& point : points) {
        point.rotate(angle);
    }
    origin.rotate(angle);
}

void Polygon::scale(float factor) {
    for (auto& point : points) {
        point.setX(origin.getX() + (point.getX() - origin.getX()) * factor);
        point.setY(origin.getY() + (point.getY() - origin.getY()) * factor);
    }
}