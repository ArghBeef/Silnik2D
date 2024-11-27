#include "PrimitiveRenderer.h"

PrimitiveRenderer::PrimitiveRenderer(sf::RenderWindow& window) : window(window) {
    renderTexture.create(window.getSize().x, window.getSize().y);
    resetBuffer();
}

void PrimitiveRenderer::drawPoint(Point2D point) {
    if (point.getX() < 0 || point.getX() >= renderTexture.getSize().x ||
        point.getY() < 0 || point.getY() >= renderTexture.getSize().y) {
        return;
    }
    sf::Vertex pixel(sf::Vector2f(point.getX(), point.getY()), point.getColor());
    renderTexture.draw(&pixel, 1, sf::Points);
}

void PrimitiveRenderer::drawLine(Point2D p0, Point2D p1, sf::Color color) {
    int x0 = p0.getX();
    int y0 = p0.getY();
    int x1 = p1.getX();
    int y1 = p1.getY();

    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);

    int stepX = (x0 < x1) ? 1 : -1;
    int stepY = (y0 < y1) ? 1 : -1;

    int err = dx - dy;

    while (true) {
        drawPoint(Point2D(x0, y0, color));

        if (x0 == x1 && y0 == y1) break;

        int err2 = err * 2;

        if (err2 > -dy) {
            err -= dy;
            x0 += stepX;
        }
        if (err2 < dx) {
            err += dx;
            y0 += stepY;
        }
    }
}

void PrimitiveRenderer::fillColor(Point2D origin, sf::Color fill_color, sf::Color background_color) {
    sf::Image image = renderTexture.getTexture().copyToImage();

    int startX = origin.getX();
    int startY = origin.getY();

    if (startX < 0 || startX >= renderTexture.getSize().x ||
        startY < 0 || startY >= renderTexture.getSize().y) {
        return;
    }

    sf::Color targetColor = image.getPixel(startX, startY);

    if (targetColor == fill_color || targetColor != background_color) {
        return;
    }

    std::queue<sf::Vector2i> points;
    points.emplace(startX, startY);

    while (!points.empty()) {
        sf::Vector2i p = points.front();
        points.pop();

        int px = p.x;
        int py = p.y;

        if (px < 0 || px >= renderTexture.getSize().x ||
            py < 0 || py >= renderTexture.getSize().y) {
            continue;
        }

        if (image.getPixel(px, py) == targetColor) {
            drawPoint(Point2D(px, py, fill_color));
            image.setPixel(px, py, fill_color);

            points.emplace(px + 1, py);
            points.emplace(px - 1, py);
            points.emplace(px, py + 1);
            points.emplace(px, py - 1);
        }
    }

    renderTexture.display();
}

void PrimitiveRenderer::boundaryFill(Point2D startPoint, sf::Color fill_color, sf::Color boundary_color) {
    sf::Image image = renderTexture.getTexture().copyToImage();

    if (startPoint.getX() < 0 || startPoint.getX() >= renderTexture.getSize().x ||
        startPoint.getY() < 0 || startPoint.getY() >= renderTexture.getSize().y) {
        return;
    }

    sf::Color currentColor = image.getPixel(startPoint.getX(), startPoint.getY());

    if (currentColor == fill_color || currentColor == boundary_color) {
        return;
    }

    std::queue<Point2D> points;
    points.push(startPoint);

    while (!points.empty()) {
        Point2D point = points.front();
        points.pop();

        int x = point.getX();
        int y = point.getY();

        if (x < 0 || x >= renderTexture.getSize().x || y < 0 || y >= renderTexture.getSize().y) {
            continue;
        }

        sf::Color colorAtPixel = image.getPixel(x, y);

        if (colorAtPixel == fill_color || colorAtPixel == boundary_color) {
            continue;
        }

        drawPoint(Point2D(x, y, fill_color));
        image.setPixel(x, y, fill_color);

        points.push(Point2D(x + 1, y));
        points.push(Point2D(x - 1, y));
        points.push(Point2D(x, y + 1));
        points.push(Point2D(x, y - 1));
    }

    renderTexture.display();
}


void PrimitiveRenderer::draw() {
    renderTexture.display();
    sf::Sprite sprite(renderTexture.getTexture());
    window.draw(sprite);
}

void PrimitiveRenderer::resetBuffer() {
    renderTexture.clear(sf::Color::Black);
    renderTexture.display();
}
