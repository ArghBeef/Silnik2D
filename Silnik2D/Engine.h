#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

#include "Point2D.h"
#include "PrimitiveRenderer.h"
#include "BitmapObject.h"
#include "Ellipse.h"

class Engine {
public:
    Engine(int width, int height, const std::string& title, bool fullscreen);
    void init();
    void run();
    void close();

private:
    sf::RenderWindow window;
    sf::Clock clock;
    std::string windowTitle;
    int windowWidth;
    int windowHeight;
    bool isFullscreen;

    PrimitiveRenderer* renderer;
    std::vector<Circle> circles;
    std::vector<Ellipse> ellipses;
    std::vector<Polygon> shapes;
    std::vector<Point2D> mouseClickCoordinates;
    std::vector<BitmapObject> bitmapObjects;
    BitmapObject bitmapobj;

    enum sceneState {
        CIRCLE,
        POLYGON,
        BITMAP,
        ELLIPSE,
    };

    enum sceneState currentState;
    Point2D gizmo;

    int currentColor = 7;
    std::pair<sf::Color, std::string> sceneColors[7] = {
        {sf::Color::Red, "Red"},
        {sf::Color::Green, "Green"},
        {sf::Color::Blue, "Blue"},
        {sf::Color::Yellow, "Yellow"},
        {sf::Color::Magenta, "Magenta"},
        {sf::Color::Cyan, "Cyan"},
        {sf::Color::White, "White"}
    };

    void handleEvents();
    void Render();
};

#endif
