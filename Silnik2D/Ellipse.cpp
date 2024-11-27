#include "Ellipse.h"
#include "PrimitiveRenderer.h"

Ellipse::Ellipse(Point2D center, float radiusX, float radiusY, float rotationAngle)
    : center(center), radiusX(radiusX), radiusY(radiusY), rotationAngle(rotationAngle) {}

void Ellipse::draw(PrimitiveRenderer& renderer) {
    float a, step;
    int x, y;
    int xc = center.getX();
    int yc = center.getY();

    step = 1.0f / std::max(radiusX, radiusY);

    float cosAngle = cos(rotationAngle * M_PI / 180.0f);
    float sinAngle = sin(rotationAngle * M_PI / 180.0f);

    for (a = 0; a < 2 * M_PI; a += step) {
        float localX = radiusX * cos(a);
        float localY = radiusY * sin(a);

        int rotatedX = static_cast<int>(localX * cosAngle - localY * sinAngle + 0.5f);
        int rotatedY = static_cast<int>(localX * sinAngle + localY * cosAngle + 0.5f);

        Point2D point(xc + rotatedX, yc + rotatedY, outlineColor);
        renderer.drawPoint(point);
    }

    if (filled) {
        renderer.boundaryFill(center, fillColor, outlineColor);
    }
}

void Ellipse::translate(float dx, float dy) {
    center.translate(dx, dy);
}

void Ellipse::scale(float factor) {
    radiusX *= factor;
    radiusY *= factor;
}

void Ellipse::rotate(float angle) {
    rotationAngle += angle;
}

void Ellipse::setOutlineColor(sf::Color color) {
    outlineColor = color;
}

void Ellipse::setFillColor(sf::Color color) {
    fillColor = color;
    filled = true;
}
