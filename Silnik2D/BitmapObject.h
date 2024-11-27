#ifndef BITMAPOBJECT_H
#define BITMAPOBJECT_H

#include "SpriteObject.h"
#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @class BitmapObject
 * @brief Klasa bazowa dla obiektow, ktore sa bitmapami
 *
 * Jest klasa dla obiektow bitmapy, ich rysowanie, animowanie, dodawanie, zmianna: translacja, rotacja, skalowanie
 *
 */
class BitmapObject : public SpriteObject {
public:
    /**
    * @brief Constructor klasy BitmapHandler
    */
    BitmapObject();

    /**
    * @brief Rysowanie obiektu bitmapy
    *
    * Metoda rysuje bitmape
    * @param window Okno gdzie jest rysowane
    */
    void draw(sf::RenderWindow& window);
    /**
    * @brief Animowanie obiektu bitmapy
    *
    * Metoda animuje bitmape
    * @param deltaTime czas zmiany
    */
    void animate(float deltaTime) override;

    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factor) override;

    /**
    * @brief Dodanie bitmapy do kolekcji bitmap obiektu
    *
    * Metoda dodaje nowe zdjecie bitmapy (z BitmapHandler) do kolekcji obiektu bitmapy (BitmapObject)
    * @param bitmap bitmape
    */
    void addBitmap(const BitmapHandler& bitmap);
    /**
    * @brief Usuwanie bitmapy z kolekcji bitmap obiektu
    *
    * Metoda dodaje usuwa bitmape
    * @param index index usuwanej bitmapy z kolekcji
    */
    void removeBitmap(int index);
    /**
    * @brief Ustawia aktywnego bitmapu
    *
    * Metoda ustawia index na aktywny bitmap z kolekcji bitmapow
    * @param index index bitmapy
    */
    void setActiveBitmap(int index);

    float frame = 0.2f;///<Czas, w którym następuje zmiana mapy bitowej

private:
    sf::Texture texture; ///<Tekstura
    std::vector<BitmapHandler> bitmaps; ///<Kolekcja bitmapow
    sf::Transform transform; ///<Obiekt do zmiany bitmapow (wykorzystujemy klase z SFML)
    int activeBitmapIndex = 0; ///<Indeks aktywnego bitmapu

    float frameTimer = 0.0f; ///<Timer przed zmianą mapy bitowej
};

#endif
