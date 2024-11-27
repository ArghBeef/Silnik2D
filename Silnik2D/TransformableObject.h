#ifndef TRANSFORMABLEOBJECT_H
#define TRANSFORMABLEOBJECT_H

#include <cmath>
#define M_PI 3.14159265358979323846

/**
 * @class TransformableObject
 * @brief Klasa bazowa dla transformacji
 *
 * Jest klasa bazowa do transformacji, metody której można zastosować w hierarchii klas dla obiektów, które mogą zmieniać swój obrót, rozmiar czy położenie
 *
 */

class TransformableObject {
public:

 /**
 * @brief Przesuwanie obiektu
 *
 * Metoda presuwa obiekt o zadanych w parametrach zmiennych współrzędnej
 *
 * @param dx współrzędna X
 * @param dy współrzędna Y
 */
    virtual void translate(float dx, float dy){return;}

/**
* @brief Rotacja obiektu
*
* Metoda obraca obiekt o zadanym w parametrach zmiennej
*
* @param angle Zmienna obrotu
*/
    virtual void rotate(float angle) { return; }

    /**
    * @brief Skalowanie obiektu
    *
    * Metoda zmieni rozmiar obiektu o zadanym w parametrach zmiennej
    *
    * @param angle Zmienna obrotu
    */
    virtual void scale(float factor) { return; }
};

#endif
