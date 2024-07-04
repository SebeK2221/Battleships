#include "Pole.h"

/**
 * \brief Sprawdza, czy pole zosta³o trafione.
 *
 * Metoda zwraca wartoœæ logiczna reprezentuj¹c¹, czy pole zosta³o trafione.
 * Wartoœæ prawda oznacza, ¿e pole zosta³o trafione, a wartoœæ fa³sz oznacza, ¿e pole nie zosta³o trafione.
 *
 * \return Zwraca wartoœæ logiczna reprezentuj¹c¹, czy pole zosta³o trafione.
 */
bool Pole::Field_is_hitted() {
	return hit;
}
/**
 * \brief Sprawdza, czy pole jest wolne.
 *
 * Metoda zwraca wartoœæ logiczna reprezentuj¹c¹, czy pole jest wolne.
 * Wartoœæ prawda oznacza, ¿e pole jest wolne, a wartoœæ fa³sz oznacza, ¿e pole nie jest wolne.
 *
 * \return Zwraca wartoœæ logiczna reprezentuj¹c¹, czy pole jest wolne.
 */
bool Pole::Field_is_free()
{
	return free_field;
}

/**
 * \brief Sprawdza, czy pole jest zajête.
 *
 * Metoda zwraca wartoœæ logiczna reprezentuj¹c¹, czy pole jest zajête.
 * Wartoœæ prawda oznacza, ¿e pole jest zajête, a wartoœæ fa³sz oznacza, ¿e pole nie jest zajête.
 *
 * \return Zwraca wartoœæ logiczna reprezentuj¹c¹, czy pole jest zajête.
 */
bool Pole::Fiel_is_occupied() {
	return occupied;
}
/**
 * \brief Sprawdza, czy pole jest oznaczone.
 *
 * Metoda zwraca wartoœæ logiczna reprezentuj¹c¹, czy pole jest oznaczone.
 * Wartoœæ prawda oznacza, ¿e pole jest oznaczone, a wartoœæ fa³sz oznacza, ¿e pole nie jest oznaczone.
 * U¿ywana jest do ustawiania statków, oraz do oznaczenia strza³u
 * 
 * \return Zwraca wartoœæ logiczna reprezentuj¹c¹, czy pole jest oznaczone.
 */
bool Pole::Field_is_marked()
{
	return marked;
}
/**
 * \brief Ustawia pole jako zajête.
 *
 * Metoda ustawia wartoœæ zmiennej `occupied` na prawda, co oznacza, ¿e pole jest teraz zajête.
 */
void Pole::SetField() {
	occupied = true;
}
/**
 * \brief Oznacza pole jako trafione.
 *
 * Metoda ustawia wartoœæ zmiennej `hit` na prawda, co oznacza, ¿e pole zosta³o teraz trafione.
 */
void Pole::Shot() {
	hit = true;
}
/**
 * \brief Ustawia pole jako wolne.
 *
 * Metoda ustawia wartoœæ zmiennej `free_field` na prawda, co oznacza, ¿e pole jest teraz wolne.
 */
void Pole::Set_field_free()
{
	free_field = true;
}
/**
 * \brief Ustawia pole jako wolne i usuwa wszystkie oznaczenia.
 *
 * Metoda ustawia wartoœci zmiennych `occupied`, `hit`, `marked` i `free_field` na fa³sz, co oznacza, ¿e pole jest teraz wolne i nie posiada ¿adnych oznaczeñ.
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
 * Metoda ustawia wartoœæ zmiennej `marked` na prawda, co oznacza, ¿e pole zosta³o teraz oznaczone.
 */
void Pole::Mark()
{
	marked = true;
}

/**
 * \brief Odznacza pole.
 *
 * Metoda ustawia wartoœæ zmiennej `marked` na fa³sz, co oznacza, ¿e pole zosta³o teraz odznaczone.
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
