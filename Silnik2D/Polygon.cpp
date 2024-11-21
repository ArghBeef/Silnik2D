#include "Polygon.h"
#include "PrimitiveRenderer.h"
#include <cmath>

Polygon::Polygon(const std::vector<Point2D>& points, bool closed)
    : points(points), closed(closed) {
    calculateCenter();
}

void Polygon::setFillColor(const sf::Color& fillColor) {
    this->fillColor = fillColor;
    filled = true;
}

void Polygon::setOutlineColor(const sf::Color& outlineColor) {
    this->outlineColor = outlineColor;
}

void Polygon::draw(PrimitiveRenderer& renderer) {
    for (size_t i = 0; i < points.size() - 1; ++i) {
        renderer.drawLine(points[i], points[i + 1], outlineColor);
    }

    if (closed) {
        renderer.drawLine(points.back(), points[0], outlineColor);
    }

    if (filled) {
        renderer.fillColor(origin, fillColor, sf::Color::Black);
    }
}

void Polygon::translate(float dx, float dy) {
    for (auto& point : points) {
        point.setX(point.getX() + dx);
        point.setY(point.getY() + dy);
    }
}

void Polygon::rotate(float angle) {
    float radians = angle * M_PI / 180.0f;
    for (auto& point : points) {
        int x = point.getX() - origin.getX();
        int y = point.getY() - origin.getY();
        point.setX(origin.getX() + (x * cos(radians) - y * sin(radians)));
        point.setY(origin.getY() + (x * sin(radians) + y * cos(radians)));
    }
}

void Polygon::scale(float factor) {
    for (auto& point : points) {
        point.setX(origin.getX() + (point.getX() - origin.getX()) * factor);
        point.setY(origin.getY() + (point.getY() - origin.getY()) * factor);
    }
}

void Polygon::calculateCenter(){
    int sumX = 0, sumY = 0;
    for (auto& point : points) {
        sumX += point.getX();
        sumY += point.getY();
    }

    origin.setX(sumX / points.size());
    origin.setY(sumY / points.size());
}