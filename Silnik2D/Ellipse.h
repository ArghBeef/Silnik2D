#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "ShapeObject.h"

class PrimitiveRenderer;

/**
 * @class Ellipse
 * @brief Klasa bazowa dla ellipsow
 *
 * Jest klasa bazowa dla wszystkich ellipsow, ich rysowanie, wypelnianie kolorem i zmianna: translacja, rotacja, skalowanie
 *

 */
class Ellipse : public ShapeObject {
public:
/**
* @brief Constructor klasy Ellipse
*
*
* @param center Center ellipsu
* @param radiusX radius po X
* @param radiusY radius po Y
* @param rotationAngle zmienna obrotu
*/
    Ellipse(Point2D center, float radiusX, float radiusY, float rotationAngle = 0.0f);

    void draw(PrimitiveRenderer& renderer);

    void translate(float dx, float dy) override;
    void scale(float factor) override;
    void rotate(float angle) override;

    /**
    * @brief Ustawic kolor konturu
    *
    *
    * @param fill kolor konturu
    */
    void setOutlineColor(sf::Color color);
    /**
    * @brief Ustawic kolor wypełnienia
    *
    *
    * @param fill kolor wypełnienia
    */
    void setFillColor(sf::Color color);

private:
    Point2D center; ///<Center ellipsu
    float radiusX; ///<Radius po X
    float radiusY; ///<Radius po Y
    float rotationAngle; ///<Zmienna obrotu

    sf::Color outlineColor = sf::Color::White; ///<Kolor konturu
    sf::Color fillColor = sf::Color::White; ///<Kolor wypelniania
    bool filled = false; ///<Czy jest ellips wypelniony kolorem
};

#endif
