#include "Engine.h"
#include "Circle.h"
#include "Polygon.h"

Engine::Engine(int width, int height, const std::string& title, bool fullscreen)
    : windowWidth(width), windowHeight(height), windowTitle(title), isFullscreen(fullscreen), currentState(CIRCLE) {}

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

    BitmapHandler bhandler1, bhandler2;
    if (bhandler1.loadFromFile("example1.png"))
        std::cout << "Porzadek" << std::endl;
    bhandler2.loadFromFile("example2.png");

    bitmapobj.addBitmap(bhandler1);
    bitmapobj.addBitmap(bhandler2);

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
            if (event.key.code == sf::Keyboard::Num1) {
                std::cout << "Current mode: CIRCLE" << std::endl;
                currentState = CIRCLE;
            }
            if (event.key.code == sf::Keyboard::Num2) {
                std::cout << "Current mode: POLYGON" << std::endl;
                currentState = POLYGON;
            }
            if (event.key.code == sf::Keyboard::Num3) {
                std::cout << "Current mode: BITMAP" << std::endl;
                currentState = BITMAP;
            }
            if (event.key.code == sf::Keyboard::Num4) {
                std::cout << "Current mode: ELLIPSE" << std::endl;
                currentState = ELLIPSE;
            }
            if (event.key.code == sf::Keyboard::C) {
                currentColor = (currentColor + 1) % 7;
                std::cout << "Current color: " << sceneColors[currentColor].second << std::endl;
            }

            if (event.key.code == sf::Keyboard::X) {
                switch (currentState) {
                case CIRCLE: {
                    circles.clear();
                    break;
                }
                case POLYGON:
                    shapes.clear();
                    break;
                case BITMAP:
                    bitmapObjects.clear();
                    break;
                case ELLIPSE:
                    ellipses.clear();
                    break;
                }
            }
            if (event.key.code == sf::Keyboard::S) {
                switch (currentState) {
                case CIRCLE: {
                    for (auto& circle : circles) {
                        circle.scale(1.1f);
                    }
                    break;
                }
                case POLYGON:
                    for (auto& shape : shapes) {
                        shape.scale(1.1f);
                    }
                    break;
                case BITMAP:
                    for (auto& bitmap : bitmapObjects) {
                        bitmap.scale(1.5f);
                    }
                    break;
                case ELLIPSE:
                    for (auto& ellipse : ellipses) {
                        ellipse.scale(1.5f);
                    }
                    break;
                }
            }
            if (event.key.code == sf::Keyboard::R) {
                switch (currentState) {
                case CIRCLE: {
                    for (auto& circle : circles) {
                        circle.rotate(1.0f);
                    }
                    break;
                }
                case POLYGON:
                    for (auto& shape : shapes) {
                        shape.rotate(1.0f);
                    }
                    break;
                case BITMAP:
                    for (auto& bitmap : bitmapObjects) {
                        bitmap.rotate(1.0f);
                    }
                    break;
                case ELLIPSE:
                    for (auto& ellipse : ellipses) {
                        ellipse.rotate(1.0f);
                    }
                    break;
                }
            }
            if (event.key.code == sf::Keyboard::D) {
                switch (currentState) {
                case CIRCLE: {
                    for (auto& circle : circles) {
                        circle.translate(1.0f, 0.0f);
                    }
                    break;
                }
                case POLYGON:
                    for (auto& shape : shapes) {
                        shape.translate(1.0f, 0.0f);
                    }
                    break;
                case BITMAP:
                    for (auto& bitmap : bitmapObjects) {
                        bitmap.translate(1.0f, 0.0f);
                    }
                    break;
                case ELLIPSE:
                    for (auto& ellipse : ellipses) {
                        ellipse.translate(1.0f, 0.0f);
                    }
                    break;
                }
            }
            if (event.key.code == sf::Keyboard::Enter && currentState == POLYGON) {
                if (!mouseClickCoordinates.empty()) {
                    Polygon newPolygon(mouseClickCoordinates, true);
                    newPolygon.origin = gizmo;
                    newPolygon.setFillColor(sceneColors[currentColor].first);
                    newPolygon.setOutlineColor(sceneColors[(currentColor + 1) % 7].first);
                    shapes.push_back(newPolygon);
                    mouseClickCoordinates.clear();
                }
            }
        }
    }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                std::cout << "Wspolrzedna: "
                    << event.mouseButton.x << ", " << event.mouseButton.y << std::endl;

                Point2D point(event.mouseButton.x, event.mouseButton.y);

                switch (currentState) {
                case CIRCLE: {
                    float radius = 50.0f;
                    Circle newCircle(point, radius);
                    newCircle.setFillColor(sceneColors[currentColor].first);
                    newCircle.setOutlineColor(sceneColors[(currentColor + 1) % 7].first);
                    circles.push_back(newCircle);
                    break;
                }
                case POLYGON: {
                    mouseClickCoordinates.push_back(point);
                    break;
                }
                case BITMAP: {
                    BitmapObject newBitmapObject = bitmapobj;
                    newBitmapObject.translate(event.mouseButton.x, event.mouseButton.y);
                    bitmapObjects.push_back(newBitmapObject);
                    break;
                }
                case ELLIPSE: {
                    float radiusX = 60.0f;
                    float radiusY = 40.0f;
                    Ellipse newEllipse(point, radiusX, radiusY, 0.0f);
                    newEllipse.setFillColor(sceneColors[currentColor].first);
                    newEllipse.setOutlineColor(sceneColors[(currentColor + 1) % 7].first);
                    ellipses.push_back(newEllipse);
                    break;
                }
                }
            }

            if (event.mouseButton.button == sf::Mouse::Right && currentState == POLYGON) {
                gizmo.setX(event.mouseButton.x);
                gizmo.setY(event.mouseButton.y);


            }
        }
}

void Engine::Render() {
    window.clear(sf::Color::Black);

    renderer->resetBuffer();

    for (auto& circle : circles) {
        circle.draw(*renderer);
    }

    for (auto& shape : shapes) {
        shape.draw(*renderer);
    }

    for (auto& ellipse : ellipses) {
        ellipse.draw(*renderer);
    }

    renderer->draw();

    float deltaTime = clock.restart().asSeconds();

    for (auto& bitmap : bitmapObjects) {
        bitmap.animate(deltaTime);
        bitmap.draw(window);
    }

    window.display();
}

void Engine::close() {
    window.close();
}
