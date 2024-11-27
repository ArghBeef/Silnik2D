#ifndef BITMAPHANDLER_H
#define BITMAPHANDLER_H

#include <SFML/Graphics.hpp>
#include <string>

/**
 * @class BitmapHandler
 * @brief Klasa bazowa dla zarzadzania bitmapami
 *
 * Jest klasa dla zarzadzania bitmapami, ich tworzenie, zapisywanie, ładowanie z pliku, kopiowanie
 *
 */
class BitmapHandler {
public:
    /**
    * @brief Constructor klasy BitmapHandler
    */
    BitmapHandler();
    /**
    * @brief Stworzy nowy bitmap
    * @param width szyrokosc
    * @param heigh wysokosc
    * @param color kolor
    * @return bool - czy operacja przebiegła prawidłowo
    */
    bool create(unsigned int width, unsigned int height, sf::Color color = sf::Color::White);
    /**
    * @brief Ladowanie bitmapy z pliku
    * @param filePath nazwe pliku, gdzie znajduje sie
    * @return bool - czy operacja przebiegła prawidłowo
    */
    bool loadFromFile(const std::string& filePath);
    /**
    * @brief Zapisywanie bitmapy do pliku
    * @param filePath nazwe do pliku, gdzie go zapisac
    * @return bool - czy operacja przebiegła prawidłowo
    */
    bool saveToFile(const std::string& filePath);
    /**
    * @brief Wyczyść bitmap
    * @param color kolor do wykorzystania operacji
    */
    void clear(sf::Color color = sf::Color::White);
    /**
    * @brief Skopiowac bitmape do bitmapy
    * @param source z jakiej bitmapy
    * @return bool - czy operacja przebiegła prawidłowo
    */
    bool copyFrom(const BitmapHandler& source);

    /**
    * @brief Dostac bitmape
    * @return bitmape
    */
    const sf::Image& getImage() const;
    /**
    * @brief Dostac rozmiar
    * @return rozmiar
    */
    sf::Vector2u getSize() const;

private:
    sf::Image bitmap; ///<Bitmapa
    bool isInitialized; ///<Czy inicjowana
};

#endif
