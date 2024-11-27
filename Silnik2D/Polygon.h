#ifndef POLYGON_H
#define POLYGON_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include "ShapeObject.h"
#include <vector>

class PrimitiveRenderer;

/**
 * @class Polygon
 * @brief Klasa bazowa dla prymitywów (które nie są okręgami)
 *
 * Jest klasa bazowa dla wszystkich prymitywów, ich rysowanie, wypelnianie kolorem i zmianna: translacja, rotacja, skalowanie
 *
 */
class Polygon : public ShapeObject {
public:
/**
* @brief Constructor klasy Polygon
*
*
* @param points kolekcja punktow prymitywu
* @param closed czy jest dany prymityw zamkniety
*/
    Polygon(const std::vector<Point2D>& points, bool closed);
    void draw(PrimitiveRenderer& renderer);

    /**
    * @brief Ustawic kolor wypełnienia
    *
    *
    * @param color kolor wypełnienia
    */
    void setFillColor(sf::Color color);
    /**
    * @brief Ustawic kolor konturu
    *
    *
    * @param color kolor konturu
    */
    void setOutlineColor(sf::Color color);

    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factor) override;

    std::vector<Point2D> points; ///<Kolekcja punktow prymitywu
    Point2D origin;///<Punkt oryginalny prymitywu (punkt z ktorego wykonamy opercje wypelnianie kolorem)

private:
    bool closed = false; ///<Czy jest to prymityw zamnkiety
    bool filled = false; ///<Czy jest wypelniony kolorem
    sf::Color fillColor = sf::Color::White; ///<Kolor wypelniania
    sf::Color outlineColor = sf::Color::Red; ///<Kolor konturu
};

#endif