#ifndef POINT2D_H
#define POINT2D_H

#include <SFML/Graphics.hpp>
#include "TransformableObject.h"

/**
 * @class Point2D
 * @brief Klasa bazowa dla punktow
 *
 * Jest klasa bazowa dla wszystkich punktow
 *
 */
class Point2D : public TransformableObject {
public:
/**
* @brief Bazowy constructor klasy Point2D
*
*
*/
    Point2D();
    /**
    * @brief Constructor klasy Point2D
    *
    *
    * @param x wspolrzedna X
    * @param y wspolrzedna Y
    */
    Point2D(float x, float y);
    /**
    * @brief Constructor klasy Point2D
    *
    *
    * @param x wspolrzedna X
    * @param y wspolrzedna Y
    * @param colorP kolor punktu
    */
    Point2D(float x, float y, sf::Color colorP);

    /**
    * @brief Dostac punkt X
    * @return punkt X
    */
    int getX() const;
    /**
    * @brief Dostac punkt Y
    * @return punkt Y
    */
    int getY() const;
    /**
    * @brief Ustawic punkt X
    *
    *
    * @param x nowy punkt X
    */
    void setX(float x);
    /**
    * @brief Ustawic punkt Y
    *
    *
    * @param y nowy punkt Y
    */
    void setY(float y);
    /**
    * @brief Dostac kolor punktu
    * @return Kolor
    */
    sf::Color getColor() const;
    /**
    * @brief Ustawic kolor punktu
    *
    *
    * @param color nowy kolor punktu
    */
    void setColor(const sf::Color color);

    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factor) override;

private:
    float x, y; ///<Wspolrzedne punktu
    sf::Color colorP; ///<Kolor punktu
};

#endif
