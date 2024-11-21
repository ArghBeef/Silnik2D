#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

#include "Point2D.h"
#include "PrimitiveRenderer.h"

class Engine {
public:
    Engine(int width, int height, const std::string& title, bool fullscreen);
    void init();
    void run();
    void close();

    std::vector<Circle> circles;
    std::vector<Polygon> shapes;

private:
    sf::RenderWindow window;
    sf::Clock clock;
    std::string windowTitle;
    int windowWidth;
    int windowHeight;
    bool isFullscreen;

    PrimitiveRenderer* renderer;

    void handleEvents();
    void Render();
};

#endif
