#include "Point2D.h"

Point2D::Point2D(float x, float y) : x(x), y(y) {}

//Tutaj sa funkcji ktore, mam nadzieje, nie potrzebuja wyjasnienia

float Point2D::getX() const {
	return x;
}

float Point2D::getY() const {
	return y;
}

void Point2D::setX(float x) {
	this->x = x;
}
void Point2D::setY(float y) {
	this->y = y;
}