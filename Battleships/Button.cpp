#include "Button.h"
 /**
 * \brief Tworzy nowy przycisk.
 */
Button::Button() {

}
/**
 * \brief Rysuje przycisk na oknie.
 *
 * Ta metoda rysuje przycisk na oknie SFML z danym tekstem, czcionką, kolorem tekstu, kolorem tła i pozycją.
 *
 * \param window Okno SFML, na którym rysowany jest przycisk.
 * \param write Tekst na przycisku.
 * \param font Czcionka używana do wyświetlania tekstu.
 * \param textcolor Kolor tekstu na przycisku.
 * \param bgcolor Kolor tła przycisku.
 * \param x Pozycja X przycisku.
 * \param y Pozycja Y przycisku.
 * \param addsize Dodatkowy rozmiar przycisku.
 */
void Button::draw(sf::RenderWindow& window, const string write, sf::Font& font, sf::Color textcolor, sf::Color bgcolor,int x, int y,int addsize)
{
	text.setFont(font);
	text.setString(write);
	text.setFillColor(textcolor);
	sf::Vector2u size = window.getSize();
	float w = size.x / 22;
	sf::Vector2f fieldSize(w, w);
	sf::Vector2f buttonSize(w * (2+addsize), w);
	background.setPosition(x* (fieldSize.x) + 1, (y * fieldSize.y) + 200);
	background.setSize(buttonSize);
	background.setFillColor(bgcolor);
	text.setPosition((x+0.5) * (fieldSize.x) + 1, (y * fieldSize.y) + 200);
	text.setCharacterSize(w/2);
	window.draw(background);
	window.draw(text);
}
/**
 * \brief Sprawdza, czy mysz znajduje się nad przyciskiem.
 *
 * Ta metoda sprawdza, czy mysz znajduje się nad przyciskiem.
 *
 * \param mousePos Pozycja myszy.
 * \return Zwraca true, jeśli mysz znajduje się nad przyciskiem, false w przeciwnym razie.
 */
bool Button::Mouse_over_button(const sf::Vector2f& mousePos) {
	sf::FloatRect rect = background.getGlobalBounds();
	return rect.contains(mousePos);
}

