#include "Pole.h"

/**
 * \brief Sprawdza, czy pole zosta�o trafione.
 *
 * Metoda zwraca warto�� logiczna reprezentuj�c�, czy pole zosta�o trafione.
 * Warto�� prawda oznacza, �e pole zosta�o trafione, a warto�� fa�sz oznacza, �e pole nie zosta�o trafione.
 *
 * \return Zwraca warto�� logiczna reprezentuj�c�, czy pole zosta�o trafione.
 */
bool Pole::Field_is_hitted() {
	return hit;
}
/**
 * \brief Sprawdza, czy pole jest wolne.
 *
 * Metoda zwraca warto�� logiczna reprezentuj�c�, czy pole jest wolne.
 * Warto�� prawda oznacza, �e pole jest wolne, a warto�� fa�sz oznacza, �e pole nie jest wolne.
 *
 * \return Zwraca warto�� logiczna reprezentuj�c�, czy pole jest wolne.
 */
bool Pole::Field_is_free()
{
	return free_field;
}

/**
 * \brief Sprawdza, czy pole jest zaj�te.
 *
 * Metoda zwraca warto�� logiczna reprezentuj�c�, czy pole jest zaj�te.
 * Warto�� prawda oznacza, �e pole jest zaj�te, a warto�� fa�sz oznacza, �e pole nie jest zaj�te.
 *
 * \return Zwraca warto�� logiczna reprezentuj�c�, czy pole jest zaj�te.
 */
bool Pole::Fiel_is_occupied() {
	return occupied;
}
/**
 * \brief Sprawdza, czy pole jest oznaczone.
 *
 * Metoda zwraca warto�� logiczna reprezentuj�c�, czy pole jest oznaczone.
 * Warto�� prawda oznacza, �e pole jest oznaczone, a warto�� fa�sz oznacza, �e pole nie jest oznaczone.
 * U�ywana jest do ustawiania statk�w, oraz do oznaczenia strza�u
 * 
 * \return Zwraca warto�� logiczna reprezentuj�c�, czy pole jest oznaczone.
 */
bool Pole::Field_is_marked()
{
	return marked;
}
/**
 * \brief Ustawia pole jako zaj�te.
 *
 * Metoda ustawia warto�� zmiennej `occupied` na prawda, co oznacza, �e pole jest teraz zaj�te.
 */
void Pole::SetField() {
	occupied = true;
}
/**
 * \brief Oznacza pole jako trafione.
 *
 * Metoda ustawia warto�� zmiennej `hit` na prawda, co oznacza, �e pole zosta�o teraz trafione.
 */
void Pole::Shot() {
	hit = true;
}
/**
 * \brief Ustawia pole jako wolne.
 *
 * Metoda ustawia warto�� zmiennej `free_field` na prawda, co oznacza, �e pole jest teraz wolne.
 */
void Pole::Set_field_free()
{
	free_field = true;
}
/**
 * \brief Ustawia pole jako wolne i usuwa wszystkie oznaczenia.
 *
 * Metoda ustawia warto�ci zmiennych `occupied`, `hit`, `marked` i `free_field` na fa�sz, co oznacza, �e pole jest teraz wolne i nie posiada �adnych oznacze�.
 */
void Pole::Free()
{
	occupied = false;
	hit = false;
	marked = false;
	free_field = false;
	sunk = false;
}
/**
 * \brief Oznacza pole.
 *
 * Metoda ustawia warto�� zmiennej `marked` na prawda, co oznacza, �e pole zosta�o teraz oznaczone.
 */
void Pole::Mark()
{
	marked = true;
}

/**
 * \brief Odznacza pole.
 *
 * Metoda ustawia warto�� zmiennej `marked` na fa�sz, co oznacza, �e pole zosta�o teraz odznaczone.
 */
void Pole::Unmark()
{
	marked = false;
}

bool Pole::is_sunk()
{
	return sunk;
}

void Pole::set_sunk()
{
	sunk = true;
}

void Pole::Free_Field_To_False()
{
	free_field = false;
}
