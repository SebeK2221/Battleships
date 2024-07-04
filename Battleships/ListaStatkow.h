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
	* \brief vector zawieraj¹cy obiekty statek
	*/
	vector<Statek> ship_list;
	/**
	* \brief Skumulowana liczba pól na statkach.
	*/
	int fields=0;
	/**
	* \brief Liczba statków.
	*/
	int number_of_ships=0;
	/**
	* \brief Liczba piêciomasztowców.
	*/
	int five_masted=0;
	/**
	* \brief Liczba czteromasztowców.
	*/
	int four_masted=0;
	/**
	* \brief Liczba trzymasztowców.
	*/
	int three_masted=0;
	/**
	* \brief Liczba dwumasztowców.
	*/
	int two_masted=0;
	/**
	* \brief Liczba jednomasztowców.
	*/
	int one_masted = 0;

};

