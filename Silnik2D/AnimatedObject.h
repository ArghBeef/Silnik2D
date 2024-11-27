#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

/**
 * @class AnimatedObject
 * @brief Klasa bazowa dla obiektów, ktore są animowane
 *
 * Jest klasa bazowa dla obiektow animowanych
 *
 */
class AnimatedObject{
public:
/**
* @brief Animowanie
*
* Metoda do animowania obiektu
*
* @param deltaTime Czas aktualizowania
*/
    virtual void animate(float deltaTime) { return; }

};

#endif
