// Point2D.h (replace #include with a forward declaration)
#ifndef POINT2D_H
#define POINT2D_H


class Point2D {
public:

    //Opisy sa w Source Files .cpp
    Point2D(float x = 0, float y = 0);

    float getX() const;
    float getY() const;

    void setX(float x);
    void setY(float y);


private:
    float x, y;
};

#endif
