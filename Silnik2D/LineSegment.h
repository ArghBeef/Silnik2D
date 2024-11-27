#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "Point2D.h"
#include "PrimitiveRenderer.h"

/**
 * @class LineSegment
 * @brief Klasa bazowa dla linii
 *
 * Jest klasa bazowa dla wszystkich linii
 *
 */
class LineSegment {
public:

    /**
    * @brief Constructor klasy LineSegment
    *
    *
    * @param p0 punkt pierwszy
    * @param p1 punkt drugi
    */
    LineSegment(const Point2D& p0, const Point2D& p1);

    /**
    * @brief Dostac punkt pierwszy
    * @return punkt pierwszy
    */
    const Point2D& getP0() const;
    /**
    * @brief Dostac punkt drugi
    * @return punkt drugi
    */
    const Point2D& getP1() const;

    /**
    * @brief Ustawic punkt pierwszy
    */
    void setP0(const Point2D& p0);
    /**
    * @brief Ustawic punkt drugi
    */
    void setP1(const Point2D& p1);


private:
    Point2D p0, p1; ///<Punkty linii
};

#endif
