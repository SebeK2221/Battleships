#pragma once
#include "Biblioteki.h"
/**
 * \brief Klasa reprezentuj¹ca przycisk w interfejsie u¿ytkownika.
 * U¿yta tak¿e do wyœwietlenia informacji w grze
 * Ta klasa zawiera metody do rysowania przycisku oraz sprawdzania, czy mysz znajduje siê nad nim.
 */
class Button
{
private:
    /**
    * \brief Tekst na przycisku.
    */
	sf::Text text;
    /**
    * \brief T³o przycisku.
    */
    sf::RectangleShape background;
public:
    Button();
    void draw(sf::RenderWindow& window, const string write, sf::Font& font, sf::Color textcolor, sf::Color bgcolor,int x ,int y,int addsize=0);

    bool Mouse_over_button(const sf::Vector2f& mousePos);

};

