#include "Engine.h"
#include "Circle.h"
#include "Polygon.h"

Engine::Engine(int width, int height, const std::string& title, bool fullscreen)
    : windowWidth(width), windowHeight(height), windowTitle(title), isFullscreen(fullscreen) {}

void Engine::init() {
    sf::VideoMode videoMode(windowWidth, windowHeight);

    if (isFullscreen) {
        window.create(videoMode, windowTitle, sf::Style::Fullscreen);
    }
    else {
        window.create(videoMode, windowTitle, sf::Style::Close | sf::Style::Resize);
    }

    window.setFramerateLimit(60);


    renderer = new PrimitiveRenderer(window);


}

void Engine::run() {
    while (window.isOpen()) {
        clock.restart();
        handleEvents();
        Render();
    }

    close();
}

void Engine::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            // Press X to create a circle
            if (event.key.code == sf::Keyboard::X) {
                Point2D center(windowWidth / 2, windowHeight / 2, sf::Color::White);
                float radius = 50.0f; // Example radius
                Circle newCircle(center, radius);
                newCircle.setFillColor(sf::Color::Blue);
                newCircle.setOutlineColor(sf::Color::Red);
                circles.push_back(newCircle); // Add the new circle to the list
            }

            // Press T to create a square
            if (event.key.code == sf::Keyboard::T) {
                int size = 50; // Side length of the square
                Point2D topLeft(windowWidth / 2 - size / 2, windowHeight / 2 - size / 2);
                Point2D topRight(windowWidth / 2 + size / 2, windowHeight / 2 - size / 2);
                Point2D bottomRight(windowWidth / 2 + size / 2, windowHeight / 2 + size / 2);
                Point2D bottomLeft(windowWidth / 2 - size / 2, windowHeight / 2 + size / 2);

                std::vector<Point2D> squarePoints = { topLeft, topRight, bottomRight, bottomLeft };
                Polygon newSquare(squarePoints, true); // Closed polygon
                newSquare.setFillColor(sf::Color::Green);
                newSquare.setOutlineColor(sf::Color::Yellow);
                shapes.push_back(newSquare); // Add the square to the shapes vector
            }

            // Translate all circles to the right
            if (event.key.code == sf::Keyboard::A) {
                for (auto& circle : circles) {
                    circle.translate(10, 0); // Move 10 pixels to the right
                }
            }

            // Translate all circles to the left
            if (event.key.code == sf::Keyboard::D) {
                for (auto& circle : circles) {
                    circle.translate(-10, 0); // Move 10 pixels to the left
                }
            }

            // Scale all circles up
            if (event.key.code == sf::Keyboard::S) {
                for (auto& circle : circles) {
                    circle.scale(1.1f); // Increase radius by 10%
                }
            }

            // Scale all circles down
            if (event.key.code == sf::Keyboard::W) {
                for (auto& circle : circles) {
                    circle.scale(0.9f); // Decrease radius by 10%
                }
            }

            // Rotate polygons (if any are present)
            if (event.key.code == sf::Keyboard::R) {
                for (auto& polygon : shapes) {
                    polygon.scale(1.1); // Rotate polygons by 15 degrees
                }
            }
        }
    }
}

void Engine::Render() {
    window.clear(sf::Color::Black);

    // Clear the drawing buffer for dynamic updates
    renderer->drawingBuffer.create(window.getSize().x, window.getSize().y, sf::Color::Black);

    // Redraw all circles
    for (auto& circle : circles) {
        circle.draw(*renderer);
    }

    for (auto& shape : shapes) {
        shape.draw(*renderer);
    }

    // Render the updated drawing buffer
    sf::Texture texture;
    texture.loadFromImage(renderer->drawingBuffer);
    sf::Sprite sprite(texture);
    window.draw(sprite);

    window.display();
}

void Engine::close() {
    window.close();
}
