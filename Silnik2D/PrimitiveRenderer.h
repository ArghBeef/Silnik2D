#ifndef PRIMITIVERENDERER_H
#define PRIMITIVERENDERER_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include <vector>
#include <queue>
#include <iostream>
#include "Circle.h"
#include "Polygon.h"

/**
 * @class PrimitiveRenderer
 * @brief Klasa renderowania prymitywów
 *
 * Jest klasa dla zarzadzania, rysowania prymitywów
 *
 */
class PrimitiveRenderer {
public:
    /**
    * @brief Constructor klasy PrimitiveRenderer
    *
    *
    * @param window Okno gdzie jest rysowane
    */
    PrimitiveRenderer(sf::RenderWindow& window);

    /**
    *Rysowanie wszystkich prymitywów
    */
    void draw();
    /**
    * @brief Rysowanie punktu
    *Rysuje punkt o podanym punkcie
    *
    * @param point punkt
    */
    void drawPoint(Point2D point);
    /**
    * @brief Rysowanie linii
    *Rysuje linie o podanych punktach i kolorze
    *
    * @param p0 punkt pierwszy
    * @param p1 punkt drugi
    * @param color kolor
    */
    void drawLine(Point2D p0, Point2D p1, sf::Color color);
    /**
     * @brief Wypełnianie kolorem
     * Wypełnia obszar kolorem, rozpoczynając od podanego punktu.
     * Proces konczy się, gdy napotka piksele w kolorze tła.
     *
     * @param origin punkt początkowy
     * @param fill_color kolor  do wypełnienia
     * @param background_color kolor tła
     */
    void fillColor(Point2D origin, sf::Color fill_color, sf::Color background_color);
    /**
     * @brief Wypełnianie obszaru z konturem
     * Wypełnia obszar kolorem do napotkania granicy (konturu) o podanym kolorze
     *
     * @param point punkt początkowy
     * @param fill_color kolor  do wypełnienia
     * @param boundary_color kolor granicy (konturu)
     */
    void boundaryFill(Point2D point, sf::Color fill_color, sf::Color boundary_color);
    /**
     * @brief Resetowanie bufora
     * Resetuje bufor renderowania
     * Wywolywana przy każdym cykle renderowania.
     */
    void resetBuffer();

private:
    sf::RenderWindow& window; ///<Okno programy
    sf::RenderTexture renderTexture; ///<Tekstura wykorzystana w buforze
};

#endif
