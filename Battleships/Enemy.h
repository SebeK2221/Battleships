#pragma once
#include "Biblioteki.h"
#include "Plansza.h"
#include "ListaStatkow.h"
/**
 * \brief Klasa reprezentuj¹ca przeciwnika w grze.
 *
 * Ta klasa odpowiada za zachowamie przeciwnika, zawiera metody do wykonania strza³u i restartowania przeciwnika
 */
class Enemy
{
public:
	void Shot(Board& board, ListaStatkow& ship_list,int mode);
	Enemy();
	void Restart_enemy();
private:
	vector<pair<int, int>> fields_left;
	vector<pair<int, int>> fields_to_hit;
	pair<int, int> field_shot;
};

