#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>

class Engine {
public:

    Engine(int width, int height, const std::string& title, bool fullscreen = false);


    void init();


    void run();


    void close();

private:
    sf::RenderWindow window;
    sf::Color clearColor = sf::Color::Black;
    sf::Clock clock;
    float frameTime = 1.0f / 60.0f;
    std::string windowTitle;
    int windowWidth;
    int windowHeight;
    bool isFullscreen;

    void handleEvents();
    void update(float deltaTime);
    void render();
    void logError(const std::string& message);
};

#endif
