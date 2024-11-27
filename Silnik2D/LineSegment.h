#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "Point2D.h"
#include "PrimitiveRenderer.h"

class LineSegment {
public:

    LineSegment(const Point2D& p0, const Point2D& p1);

    const Point2D& getP0() const;
    const Point2D& getP1() const;

    void setP0(const Point2D& p0);
    void setP1(const Point2D& p1);


private:
    Point2D p0, p1;
};

#endif
