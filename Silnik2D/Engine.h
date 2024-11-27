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

/**
 * @class Engine
 * @brief Klasa glowna gry
 *
 * Jest klasa glowna gry - silnik, przez ktora wszystkie robimy wszystkie operacje - Rysowanie, inicjalizacje, aktualizowanie
 *
 */

class Engine {
public:
    /**
    * @brief Constructor klasy Engine
    *
    *
    * @param width szerokosc stworzonego okna programy
    * @param height wysokosc stworzonego okna programy
    * @param title nazwa okna programy
    * @param fullscreen czy okno jest na pełnym ekranie
    */
    Engine(int width, int height, const std::string& title, bool fullscreen);
    /**
    *Inicjalizacja silnika
    */
    void init();
    /**
    *Główny proces silnika, aktualizujący wszystkie operacje
    */
    void run();
    /**
    *Zamkniecie silnika (okna)
    */
    void close();

private:
    sf::RenderWindow window; ///<Oknow programu
    sf::Clock clock; ///<Licznik - zegar
    std::string windowTitle; ///<Nazwa okna programu
    int windowWidth; ///<szerokość
    int windowHeight; ///<wysokość
    bool isFullscreen; ///<czy okno jest na pełnym ekranie

    PrimitiveRenderer* renderer; ///<Obiekt renderowania - PrimitiveRenderer
    std::vector<Circle> circles; ///<Kolekcja wszystkich okregów
    std::vector<Ellipse> ellipses; ///<Kolekcja wszystkich ellipsów
    std::vector<Polygon> shapes; ///<Kolekcja wszystkich polygonów
    std::vector<Point2D> mouseClickCoordinates; ///<Kolekcja do punktów przez mysze (do rysowania polygonów)
    std::vector<BitmapObject> bitmapObjects; ///<Kolekcja bitmapów
    BitmapObject bitmapobj; ///<Obiekt bitmapy do zarządzania

    /**
    *Enum do zarządzania obiektami w oknie silnika
    */
    enum sceneState {
        CIRCLE,
        POLYGON,
        BITMAP,
        ELLIPSE,
    };

    enum sceneState currentState; ///<Jaki jest stan silnika
    Point2D gizmo; ///<Punkt do zarządzania operacjami na polygonach

    int currentColor = 7; ///<stan kolorow
    /**
    *Kolekcja do zarządzania kolorem (do rysowania prymitowów)
    */
    std::pair<sf::Color, std::string> sceneColors[7] = {
        {sf::Color::Red, "Red"},
        {sf::Color::Green, "Green"},
        {sf::Color::Blue, "Blue"},
        {sf::Color::Yellow, "Yellow"},
        {sf::Color::Magenta, "Magenta"},
        {sf::Color::Cyan, "Cyan"},
        {sf::Color::White, "White"}
    };

    /**
    *Metod do zarządzania i obsługi klawiatury i myszy
    */
    void handleEvents();
    /**
    *Metod do renderowania (rysowania) wszystkich obiektow i zmiana buferow
    */
    void Render();
};

#endif
