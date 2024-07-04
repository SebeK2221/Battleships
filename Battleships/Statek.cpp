#include "Statek.h"
/**
 * \brief Konstruktor domyślny klasy Statek.
 */
Statek::Statek()
{

}

/**
* \brief Konstruktor klasy Statek.
*
* Inicjalizuje statek z danymi współrzędnymi, typem statku i liczbą pól statku.
*
* \param cords Wektor par indeksów wierszy i kolumn, które identyfikują pola statku.
* \param ship_t Typ statku.
*/
Statek::Statek(vector<pair<int, int>> cords, int ship_t)
{
	coords = cords;
	ship_type = ship_t;
	fields = coords.size();
}
/**
* \brief Sprawdza, czy statek został zatopiony.
*
* Ta metoda sprawdza, czy wszystkie pola statku zostały trafione. Jeśli tak, statek jest ustawiany jako zatopiony.
* Gdy statek jest zatopiony ustawia pola sąsiednie jako puste
* \param board Plansza, na której znajduje się statek.
* \return Zwraca true, jeśli statek został zatopiony, false w przeciwnym razie.
*/
bool Statek::Check_ship(Board& board)
{
	int count = 0;
	for (int i = 0;i < coords.size();i++) {
		if (board.Checkfield(coords[i].first, coords[i].second) == true) {
			count++;
			if (count == fields) {
				sunk = true;
				for (int j = 0; j < coords.size();j++) {
					for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
						for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
							if (row > -1 && row < 10 && col > -1 && col < 10) {
								board.Set_field_free(row, col);
							}
						}
					}
				}
				for (int k = 0;k < coords.size();k++) {
					board.Set_field_sunk(coords[k].first, coords[k].second);
				}
			}
		}
	}
	return sunk;
}
/**
 * \brief Sprawdza, czy statek został zatopiony.
 *
 * \return Zwraca true, jeśli statek został zatopiony, false w przeciwnym razie.
 */
bool Statek::isSunk()
{
	return sunk;
}
/**
 * \brief Ustawia statek jako zatopiony.
 */
void Statek::Sunk()
{
	sunk = true;
}


/**
 * \brief Zwraca typ statku.
 *
 * \return Zwraca typ statku.
 */
int Statek::Ship_type()
{
	return ship_type;
}


/**
 * \brief Zwraca liczbę pól statku.
 *
 * \return Zwraca liczbę  pól statku.
 */
int Statek::Remain_fields()
{
	return fields;
}
/**
 * \brief Wyświetla koordynaty statku.
 *
 * Ta metoda wyświetla koordynaty każdego pola statku.
 */
void Statek::Wypisz()
{
	for (int i = 0;i < coords.size();i++) {
		cout << coords[i].first << " " << coords[i].second << endl;
	}
}
