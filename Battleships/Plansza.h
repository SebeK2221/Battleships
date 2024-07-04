#pragma once
#include "Biblioteki.h"
#include "Pole.h"
/**
 * \brief Klasa reprezentuj¹ca planszê w grze.
 *
 * Ta klasa zawiera metody do manipulacji i wyœwietlania planszy.
 */
class Board
{
public:
	Board(int wiersze, int kolumny);
	void Ustaw(int clickedRow, int clickedCol);
	void Display(sf::RenderWindow& window, Board& enemy,bool game,bool otaczanie);
	bool Checkfield(int clickedRow, int clickedCol);
	bool isMarked(int clickedRow, int clickedCol);
	void Mark_field(int clickedRow, int clickedCol);
	void Unmark_field(int clickedRow, int clickedCol);
	void Unmark_fields(vector<pair<int, int>> coords);
	void Hit_field(int row, int col);
	void Set_field_free(int row, int col);
	void Set_field_sunk(int row, int col);
	bool Set_ship(vector<pair<int, int>> coords,int mode);
	bool Set_player_ship(vector<pair<int, int>>coords, int mode);
	bool Is_field_free(int row, int col);
	bool Is_Occupied_field(int row, int col);
	bool is_field_sunk(int row, int col);
	void Clear_board();
	void Change_free_fields();
private:
	/*
	*\brief Liczba wierszy na planszy.
	*/
	int wiersze;
	/*
	*\brief Liczba kolumn na planszy. 
	*/
	int kolumny;
	/**
	* \brief Plansza.
	* To jest dwuwymiarowy wektor, który reprezentuje planszê gry. Ka¿dy element wektora to obiekt klasy Pole. 
	*/
	vector < vector<Pole>> board;
};

