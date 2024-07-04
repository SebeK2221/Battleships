#pragma once
#include "Biblioteki.h"
#include "Pole.h"
#include "Plansza.h"
/**
 * \brief Klasa reprezentuj¹ca statek w grze.
 *
 * Ta klasa zawiera metody do tworzenia statku, sprawdzania jego stanu i ustawiania go jako zatopionego.
 */
class Statek
{
private:
	/**
	* \brief Wskazuje, czy statek zosta³ zatopiony.
	*/
	bool sunk = false;
	/**
	* \brief Koordynaty statku.
	*/
	vector<pair<int, int>> coords;

	/**
	* \brief Liczba pól statku.
	*/
	int fields = 0;
	/**
	* \brief Typ statku.
	*/
	int ship_type = 0;
public:
	Statek();
	Statek(vector<pair<int, int>> coords, int ship_type);
	bool Check_ship(Board& board);
	bool isSunk();
	void Sunk();
	int Ship_type();
	int Remain_fields();
	void Wypisz();
};