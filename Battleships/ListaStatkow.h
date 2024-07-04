#pragma once
#include "Biblioteki.h"
#include "Plansza.h"
#include "Statek.h"
#include <cstdlib>
#include <ctime>
#include <random>
class ListaStatkow
{
public:
	int Num_of_ships();
	void Add_ship(vector<pair<int, int>> coords, int ship_type,Board& board,int tryb,bool otaczanie, int jedno, int dwu, int trzy, int cztero, int pieco, int fields_acc);
	void Wypisz();
	int Num_of_fields();
	void Generate_Enemy_Ships(Board& enemy,int tryb,int jedno,int dwu,int trzy,int cztero,int pieco,int fields_acc);
	void Generate_Player_Ships(Board& enemy,int tryb,bool otaczanie, int jedno, int dwu, int trzy, int cztero, int pieco,int fields_acc);
	void Add_enemy_ship(vector<pair<int, int>> coords, int ship_type, Board& board,int tryb, int jedno, int dwu, int trzy, int cztero, int pieco, int fields_acc);
	void Add_enemy_ship_classic(vector<pair<int, int>> coords, int ship_type, Board& board,int tryb);
	void Add_ship_classic(vector<pair<int, int>> coords, int ship_type, Board& board, int tryb, bool otaczanie);
	void Clear_ship_list(Board& board);
	void Check_ships(Board& board);
private:
	/**
	* \brief vector zawieraj�cy obiekty statek
	*/
	vector<Statek> ship_list;
	/**
	* \brief Skumulowana liczba p�l na statkach.
	*/
	int fields=0;
	/**
	* \brief Liczba statk�w.
	*/
	int number_of_ships=0;
	/**
	* \brief Liczba pi�ciomasztowc�w.
	*/
	int five_masted=0;
	/**
	* \brief Liczba czteromasztowc�w.
	*/
	int four_masted=0;
	/**
	* \brief Liczba trzymasztowc�w.
	*/
	int three_masted=0;
	/**
	* \brief Liczba dwumasztowc�w.
	*/
	int two_masted=0;
	/**
	* \brief Liczba jednomasztowc�w.
	*/
	int one_masted = 0;

};

