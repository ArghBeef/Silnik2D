#include "Engine.h"

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
    if (!window.isOpen()) {
        std::cout << "Fail";
    }

    renderer = new PrimitiveRenderer(window);  //Primitive renderer
    currentPrimitive = PIXEL; //enum do zmiany current primitive
    sizeTest = 35; //rozmiar
    
}

//Wykorzystamy w mejnie. Methoda gdzie wszystkie loopy, update, draw etc are
void Engine::run() {
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        handleEvents();
        draw();
    }

    close();
}

void Engine::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        //Zamkniecie po esc
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        //Zmiana typu primitive po przycisku numerow liczby idk
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            currentPrimitive = PIXEL;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            currentPrimitive = LINE;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            currentPrimitive = CIRCLE;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
            currentPrimitive = SQUARE;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
            currentPrimitive = TRIANGLE;
        }

        // Rysowanie po przycisku myszy
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                
                //Zapisanie koordynat myszy
                Point2D point(event.mouseButton.x, event.mouseButton.y);

                //Od currentPrimitive, wpisujemy do kolekcji dane obiektow (point skad rysujemy, rozmiar(radius) i color))
                switch (currentPrimitive) {
                case PIXEL:
                    points.emplace_back(point);
                    break;
                case LINE:
                    lines.emplace_back(point, Point2D(point.getX() + sizeTest, point.getY() + sizeTest));
                    break;
                case CIRCLE:
                    circle.emplace_back(point, sizeTest);
                    break;
                case SQUARE:
                    squares.emplace_back(point, sizeTest);
                    break;
                case TRIANGLE:
                    triangles.emplace_back(point, sizeTest);
                    break;
                }
            }
        }

        //Po prostu robi zeby wszystkie figury moves wlewo po W
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            for (auto& p : points) {
                if (p.getX() > windowWidth)
                    p.setX(0);
                p.setX(p.getX() + 10);
            }
            for (auto& line : lines) {

                if (line.first.getX() > windowWidth && line.second.getX() > windowWidth) {
                    line.first.setX(800.0 - line.first.getX());
                    line.second.setX(800.0 - line.second.getX());
                }

                line.first.setX(line.first.getX() + 10);
                line.second.setX(line.second.getX() + 10);
            }

            for (auto& c : circle) {
                auto& center = c.first;

                if (center.getX() > windowWidth) {
                    center.setX(0);
                }

                center.setX(center.getX() + 10);
            }

            for (auto& s : squares) {
                if (s.first.getX() > windowWidth)
                    s.first.setX(0);
                s.first.setX(s.first.getX() + 10);
            }

            for (auto& t : triangles) {
                if (t.first.getX() > windowWidth)
                    t.first.setX(0);
                t.first.setX(t.first.getX() + 10);
            }
        }

        //Ponizsze dwa if`a sa do zwiekszenia lub zmniejszenia sizeTest (do kontrolu rozmiaru)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            if (sizeTest != 150) {
                std::cout << sizeTest << std::endl;
                sizeTest += 5;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            if (sizeTest != 5) {
                std::cout << sizeTest << std::endl;
                sizeTest -= 5;
            }
        }

        //Clearing wszystkich primitives z ekranu (toczne clear co jest w kolekcji vector)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
            points.clear();
            lines.clear();
            circle.clear();
            squares.clear();
            triangles.clear();
        }
    }
}

void Engine::draw() {
    window.clear(sf::Color::Black);

    //Rysowanie w zaleznosci od currentPrimitive
    switch (currentPrimitive) {
    case PIXEL:
        for (const auto& p : points) {
            renderer->drawPoint(p, sf::Color::White);
        }
        break;

    case LINE:
        for (const auto& l : lines) {
            renderer->drawLine(l.first, l.second, sf::Color::Green);
        }
        break;

    case CIRCLE:
        for (const auto& c : circle) {
            renderer->drawCircle(c.first, c.second, sf::Color::Red);
        }
        break;

    case SQUARE:
        for (const auto& s : squares) {
            renderer->drawSquare(s.first,s.second,s.second, sf::Color::Yellow);
        }
        break;

    case TRIANGLE:
        for (const auto& t : triangles) {
            renderer->drawTriangle(t.first, t.second, sf::Color::Cyan);
        }
        break;
    }

    window.display();
}

//Zamkniecie, moze byc pozniej cos jeszcze
void Engine::close() {
    window.close();
}