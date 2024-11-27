#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
/**
 * @class GameObject
 * @brief Klasa bazowa dla obiektow gry
 *
 * Jest klasa bazowa dla obiektow gry
 *
 */
class GameObject {
public:
/**
* @brief Aktualizowanie obiektu
*
* Metoda aktualizuje obiekt
*/
    virtual void update() { return; }
    /**
    * @brief Rysowanie obiektu
    *
    * Metoda rysuje obiekt
    */
    virtual void draw() { return; }
};

#endif
