#include "PrimitiveRenderer.h"

PrimitiveRenderer::PrimitiveRenderer(sf::RenderWindow& window) : window(window) {
    drawingBuffer.create(window.getSize().x, window.getSize().y, sf::Color::Black);
}

void PrimitiveRenderer::drawPoint(Point2D point) {
    unsigned int x = static_cast<unsigned int>(point.getX());
    unsigned int y = static_cast<unsigned int>(point.getY());

    if (x < drawingBuffer.getSize().x && y < drawingBuffer.getSize().y) {
        drawingBuffer.setPixel(x, y, point.getColor());
    }

    sf::Vertex vertex(sf::Vector2f(point.getX(), point.getY()), point.getColor());
    window.draw(&vertex, 1, sf::Points);
}

void PrimitiveRenderer::drawLine(Point2D p0, Point2D p1, sf::Color color) {
    int x0 = p0.getX();
    int y0 = p0.getY();
    int x1 = p1.getX();
    int y1 = p1.getY();

    float x, y;
    float dy = y1 - y0;
    float dx = x1 - x0;
    float m = dy / dx;

    if (dx == 0.0f) {
        if (y0 < y1) {
            for (int y = y0; y <= y1; y++) {
                drawPoint(Point2D(x0, y, color));
            }
        }
        else {
            for (int y = y1; y <= y0; y++) {
                drawPoint(Point2D(x0, y, color));
            }
        }
        return;
    }

    y = y0;
    if (x0 < x1) {
        for (x = x0; x <= x1; x++) {
            drawPoint(Point2D(x, y + 0.5f, color));
            y += m;
        }
    }
    else {
        for (x = x1; x <= x0; x++) {
            drawPoint(Point2D(x, y + 0.5f, color));
            y += m;
        }
    }
}

void PrimitiveRenderer::fillColor(Point2D origin, sf::Color fill_color, sf::Color background_color) {
    std::queue<Point2D> DSD;
    DSD.push(origin);

    while (!DSD.empty()) {
        Point2D P = DSD.front();
        DSD.pop();

        unsigned int x = static_cast<unsigned int>(P.getX());
        unsigned int y = static_cast<unsigned int>(P.getY());

        if (x >= drawingBuffer.getSize().x || y >= drawingBuffer.getSize().y) continue;

        sf::Color currentColor = drawingBuffer.getPixel(x, y);
        if (currentColor == fill_color || currentColor != background_color) continue;

        drawingBuffer.setPixel(x, y, fill_color);
        filledAreas.push_back(P);

        // Add neighboring pixels
        if (y > 0) DSD.push(Point2D(x, y - 1)); // North
        if (y < drawingBuffer.getSize().y - 1) DSD.push(Point2D(x, y + 1)); // South
        if (x > 0) DSD.push(Point2D(x - 1, y)); // West
        if (x < drawingBuffer.getSize().x - 1) DSD.push(Point2D(x + 1, y)); // East
    }
}

void PrimitiveRenderer::draw() {
    for (const auto& point : filledAreas) {
        drawPoint(point);
    }
}
