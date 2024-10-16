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
        logError("Nie udało się otworzyć okna!");
    }
}

void Engine::run() {
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        handleEvents();
        update(deltaTime);
        render();
    }

    close();
}

void Engine::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                std::cout << "Lewy przycisk myszy wciśnięty: "
                   << event.mouseButton.x << ", " << event.mouseButton.y << std::endl;
            }
        }
    }
}

void Engine::update(float deltaTime) {

}


void Engine::render() {
    window.clear(clearColor);


    window.display();
}

void Engine::logError(const std::string& message) {
    std::cerr << "Błąd: " << message << std::endl;
    std::ofstream logFile("error_log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
    }
}

void Engine::close() {
    window.close();
    std::cout << "Gra została zamknięta." << std::endl;
}
