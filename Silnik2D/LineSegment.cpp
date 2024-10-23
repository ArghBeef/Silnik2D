#include "LineSegment.h"

LineSegment::LineSegment(const Point2D& p0, const Point2D& p1) : p0(p0), p1(p1) {}


//eee tez jak z Point2D

const Point2D& LineSegment::getP0() const {
    return p0;
}

const Point2D& LineSegment::getP1() const {
    return p1;
}

void LineSegment::setP0(const Point2D& p0) {
    this->p0 = p0;
}

void LineSegment::setP1(const Point2D& p1) {
    this->p1 = p1;
}

