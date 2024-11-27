#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "ShapeObject.h"
#include <vector>

class PrimitiveRenderer;

/**
 * @class Circle
 * @brief Klasa bazowa dla okregow
 *
 * Jest klasa bazowa dla wszystkich okręgów, ich rysowanie, wypelnianie kolorem i zmianna: translacja, rotacja, skalowanie
 *
 */
class Circle : public ShapeObject {
public:
/**
* @brief Constructor klasy Circle
*
*
* @param center Center okregu
* @param radius radius
*/
    Circle(Point2D center, float radius);
    void draw(PrimitiveRenderer& renderer);

/**
* @brief Ustawic kolor wypełnienia
*
*
* @param fill kolor wypełnienia
*/
    void setFillColor(sf::Color fill);
    /**
    * @brief Ustawic kolor konturu
    *
    *
    * @param outline kolor konturu
    */
    void setOutlineColor(sf::Color outline);

    void translate(float dx, float dy) override;
    void scale(float factor) override;
    void rotate(float angle) override;


    Point2D center; ///<Punkt środka okręgu
    float radius; ///<Radius okręgu

private:
    bool filled = false; ///<Czy jest okręg wypelniony kolorem
    sf::Color fillColor = sf::Color::White; ///<Kolor wypelniania
    sf::Color outlineColor = sf::Color::White; ///<Kolor konturu
};

#endif