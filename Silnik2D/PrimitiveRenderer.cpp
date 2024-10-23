#include "PrimitiveRenderer.h"


PrimitiveRenderer::PrimitiveRenderer(sf::RenderWindow& window) : window(window) {}

//Rysowanie jednego punktu, tutaj wykorzystamy Vertex z SFML do rysowania tego punktu
void PrimitiveRenderer::drawPoint(const Point2D& point, sf::Color color) {
    sf::Vertex vertex(sf::Vector2f(point.getX(), point.getY()), color);
    window.draw(&vertex, 1, sf::Points);
}

//Rysowanie linii algorytmem przyrostowym (sa w laboratorium2 lub na drugim wykladzie mozecie zobaczyc)
void PrimitiveRenderer::drawLine(const Point2D& p0, const Point2D& p1, sf::Color color) {
    int x0 = p0.getX();
    int y0 = p0.getY();
    int x1 = p1.getX();
    int y1 = p1.getY();

    float x;
    float y;

    float dy = y1 - y0;
    float dx = x1 - x0;

    float m = dy / dx;

    //Jezeli dx == 0, oznacza ze linia jest pionowa i zmieniamy tylko wspolrzedne y
    if (dx == 0.0f) {
        //Wyznaczenie poczatkowej koordynaty Y. (Rysujemy od mniejszej do wiekszej)
        if (y0 < y1) {
            for (int y = y0; y <= y1; y++) {

                drawPoint(Point2D(x0, y), color);
            }
        }
        else {
            for (int y = y1; y <= y0; y++) {
                drawPoint(Point2D(x0, y), color);
            }
        }
        return;
    }

    y = y0;
    //Podobne do poprzedniego tylko robimy te na z X
    if (x0 < x1) {
        for (x = x0; x <= x1; x++) {
            drawPoint(Point2D(x, y + 0.5f), color);
            y += m;
        }
    }
    else {
        for (x = x1; x <= x0; x++) {
            drawPoint(Point2D(x, y + 0.5f), color);
            y += m;
        }
    }


}

//Rysowanie kola (wzor z wyklady drugiego)
void PrimitiveRenderer::drawCircle(const Point2D& center, float radius, sf::Color color) {
    float a, step;
    int x, y;
    int xc = center.getX();
    int yc = center.getY();

    step = 1.0 / radius;  // Jeden Krok petli

    for (a = 0; a < 2 * M_PI; a += step) {
        x = xc + radius * cos(a) + 0.5; //Zaokraglone X
        y = yc + radius * sin(a) + 0.5; //Zaokraglone Y

        drawPoint(Point2D(x, y), color);
    }
}

//Jak z trojkatem tylko z kwadratem
void PrimitiveRenderer::drawSquare(const Point2D& origin, float sizeX, float sizeY, sf::Color color) {
    std::vector<Point2D> square = {
        origin,
        Point2D(origin.getX() + sizeX, origin.getY()),
        Point2D(origin.getX() + sizeX, origin.getY() + sizeY),
        Point2D(origin.getX(), origin.getY() + sizeY)
    };
    drawPolyline(square, true, color);
}

//Elementarnie rysujemy trojkat 90 za pomocy drawPolyLine (najpierw wyliczamy punkty trojkata)
void PrimitiveRenderer::drawTriangle(const Point2D& origin,float size, sf::Color color) {
    std::vector<Point2D> triangle = {
    origin,
        Point2D(origin.getX() + size, origin.getY() + size),
        Point2D(origin.getX(), origin.getY() + size)
    };

    drawPolyline(triangle, true, color);
}

void PrimitiveRenderer::drawPolyline(const std::vector<Point2D>& points, bool closed, sf::Color color) {
    
    //Ta petla oglada wszystkie punkty oprocz ostatniego i dla kazdych 2 punktow rysuje linie
    for (int i = 0; i < points.size() - 1; ++i) {
        drawLine(points[i], points[i + 1], color);
    }

    //Jezeli zamkniety, to rysujemy jesze jedna linie z ostatniego punktu do pierwszego
    //a > 2 oznacza, czy sa 2 punkty do polaczenia
    if (closed && points.size() > 2) {
        drawLine(points.back(), points[0], color);
    }
}
