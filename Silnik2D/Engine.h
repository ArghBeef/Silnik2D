#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <vector>

#include "Point2D.h"
#include "PrimitiveRenderer.h"

class Engine {
public:

    Engine(int width, int height, const std::string& title, bool fullscreen);
    //Opisy sa w Source Files .cpp

    void init();


    void run();


    void close();

    //enum do primitivesState ktory steruje jaki typami primitives
    enum PrimitiveState {
        PIXEL,
        LINE,
        CIRCLE,
        SQUARE,
        TRIANGLE,
    };


private:
    sf::RenderWindow window;
    sf::Clock clock;
    float frameTime = 1.0f / 60.0f; //60 FPS
    std::string windowTitle;
    int windowWidth;
    int windowHeight;
    bool isFullscreen;

    PrimitiveRenderer* renderer; //obiekt do primitives
    enum PrimitiveState currentPrimitive; //jaki jest rysowany primitive
    int sizeTest; //rozmiar niektorych primitives

    //Kollekcje vector do schronienia linii, punktow
    std::vector<std::pair<Point2D, Point2D>> lines;
    std::vector<Point2D> points;
    std::vector<std::pair<Point2D, int>> circle;
    std::vector<std::pair<Point2D, int>> squares;
    std::vector<std::pair<Point2D, int>> triangles;

    void handleEvents();
    void draw();
};

#endif