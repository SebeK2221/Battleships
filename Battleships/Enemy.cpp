#include "Enemy.h"
#include <random>
/**
 * \brief Wykonuje strzał przeciwnika.
 *
 * Ta metoda wykonuje strzał przeciwnika na planszy. 
 * Posiada 2 vectory: fields_left która zawiera wszystkie pola na planszy do których można jeszcze strzelić oraz fields_to_hit zawierająca pola otaczające trafiony statek na których może znajdować się reszta jego pól
 * Gdy nie odnaleziono statku przeciwnik strzela w losowe pola planszy
 * Gdy znaleziono statek przeciwnik będzie strzelał w pola na których może znajdować się reszta statku aż do zatopienia go
 * Z każdy strzałem pole do którego strzelano usuwane jest z listy skąd zostało pobrane i nigdy już na żadnej się nie pojawi
 * Gdy zatopiono statek oba vectory są czyszczone i do fields_left przypisują się nowe pola (do fields_left przypisywane są pola od nowa aby uwzględnić pola odstępu które oznaczają się przy zatopieniu)
 * \param board Plansza, na której wykonany jest strzał.
 * \param ship_list Lista statków, które mogą być trafione.
 */
void Enemy::Shot(Board& board,ListaStatkow& ship_list,int mode)
{
	if (mode == 2) {
		random_device rd;
		mt19937 generator(rd());
		uniform_int_distribution<int> distribution(0, fields_left.size() - 1);
		int i = distribution(generator);
		int row, col;
		if (fields_to_hit.size() == 0) {
			row = fields_left[i].first;
			col = fields_left[i].second;
			if (board.Checkfield(row, col) == false && board.Is_field_free(row, col) == false) {
				int last_num_of_ships = ship_list.Num_of_ships();
				board.Hit_field(row, col);
				if (board.Is_Occupied_field(row, col)) {
					if (row - 1 > -1) {
						if (board.Checkfield(row - 1, col) == false && board.Is_field_free(row - 1, col) == false) {
							fields_to_hit.push_back(make_pair(row - 1, col));
						}
					}
					if (row + 1 < 10) {
						if (board.Checkfield(row + 1, col) == false && board.Is_field_free(row + 1, col) == false) {
							fields_to_hit.push_back(make_pair(row + 1, col));
						}
					}
					if (col - 1 > -1) {
						if (board.Checkfield(row, col - 1) == false && board.Is_field_free(row, col - 1) == false) {
							fields_to_hit.push_back(make_pair(row, col - 1));
						}
					}
					if (col + 1 < 10) {
						if (board.Checkfield(row, col + 1) == false && board.Is_field_free(row, col + 1) == false) {
							fields_to_hit.push_back(make_pair(row, col + 1));
						}
					}

				}
				ship_list.Check_ships(board);
				int curr_num_of_ships = ship_list.Num_of_ships();
				if (last_num_of_ships != curr_num_of_ships) {
					fields_to_hit.clear();
					fields_to_hit.resize(0);
					fields_left.clear();
					fields_left.resize(0);
					for (int b_row = 0;b_row < 10;b_row++) {
						for (int b_col = 0;b_col < 10;b_col++) {
							if (board.Checkfield(b_row, b_col) == false && board.Is_field_free(b_row, b_col) == false) {
								fields_left.push_back(make_pair(b_row, b_col));
							}
						}
					}
				}
			}
			fields_left.erase(fields_left.begin() + i);
		}
		else {
			uniform_int_distribution<int> distribution2(0, fields_to_hit.size() - 1);
			int j = distribution2(generator);
			row = fields_to_hit[j].first;
			col = fields_to_hit[j].second;
			int last_num_of_ships = ship_list.Num_of_ships();
			board.Hit_field(row, col);
			if (board.Is_Occupied_field(row, col)) {
				if (row - 1 > -1) {
					if (board.Checkfield(row - 1, col) == false && board.Is_field_free(row - 1, col) == false) {
						fields_to_hit.push_back(make_pair(row - 1, col));
					}
				}
				if (row + 1 < 10) {
					if (board.Checkfield(row + 1, col) == false && board.Is_field_free(row + 1, col) == false) {
						fields_to_hit.push_back(make_pair(row + 1, col));
					}
				}
				if (col - 1 > -1) {
					if (board.Checkfield(row, col - 1) == false && board.Is_field_free(row, col - 1) == false) {
						fields_to_hit.push_back(make_pair(row, col - 1));
					}
				}
				if (col + 1 < 10) {
					if (board.Checkfield(row, col + 1) == false && board.Is_field_free(row, col + 1) == false) {
						fields_to_hit.push_back(make_pair(row, col + 1));
					}
				}

			}
			ship_list.Check_ships(board);
			int curr_num_of_ships = ship_list.Num_of_ships();
			if (last_num_of_ships != curr_num_of_ships) {
				fields_to_hit.clear();
				fields_to_hit.resize(0);
				fields_left.clear();
				fields_left.resize(0);
				for (int b_row = 0;b_row < 10;b_row++) {
					for (int b_col = 0;b_col < 10;b_col++) {
						if (board.Checkfield(b_row, b_col) == false && board.Is_field_free(b_row, b_col) == false) {
							fields_left.push_back(make_pair(b_row, b_col));
						}
					}
				}
			}
			else {
				fields_to_hit.erase(fields_to_hit.begin() + j);
			}
		}
	}
	else if (mode == 1) {
		random_device rd;
		mt19937 generator(rd());
		uniform_int_distribution<int> distribution(0, fields_left.size() - 1);
		int i = distribution(generator);
		int row, col;
		if (fields_to_hit.size() == 0) {
			row = fields_left[i].first;
			col = fields_left[i].second;
			if (board.Checkfield(row, col) == false && board.Is_field_free(row, col) == false) {
				int last_num_of_ships = ship_list.Num_of_ships();
				board.Hit_field(row, col);
				if (board.Is_Occupied_field(row, col)) {
					field_shot = make_pair(row, col);
					if (row - 1 > -1) {
						if (board.Checkfield(row - 1, col) == false && board.Is_field_free(row - 1, col) == false) {
							fields_to_hit.push_back(make_pair(row - 1, col));
						}
					}
					if (row + 1 < 10) {
						if (board.Checkfield(row + 1, col) == false && board.Is_field_free(row + 1, col) == false) {
							fields_to_hit.push_back(make_pair(row + 1, col));
						}
					}
					if (col - 1 > -1) {
						if (board.Checkfield(row, col - 1) == false && board.Is_field_free(row, col - 1) == false) {
							fields_to_hit.push_back(make_pair(row, col - 1));
						}
					}
					if (col + 1 < 10) {
						if (board.Checkfield(row, col + 1) == false && board.Is_field_free(row, col + 1) == false) {
							fields_to_hit.push_back(make_pair(row, col + 1));
						}
					}

				}
				ship_list.Check_ships(board);
				int curr_num_of_ships = ship_list.Num_of_ships();
				if (last_num_of_ships != curr_num_of_ships) {
					fields_to_hit.clear();
					fields_to_hit.resize(0);
					fields_left.clear();
					fields_left.resize(0);
					for (int b_row = 0;b_row < 10;b_row++) {
						for (int b_col = 0;b_col < 10;b_col++) {
							if (board.Checkfield(b_row, b_col) == false && board.Is_field_free(b_row, b_col) == false) {
								fields_left.push_back(make_pair(b_row, b_col));
							}
						}
					}
				}
			}
			fields_left.erase(fields_left.begin() + i);
		}
		else {
			uniform_int_distribution<int> distribution2(0, fields_to_hit.size() - 1);
			int j = distribution2(generator);
			row = fields_to_hit[j].first;
			col = fields_to_hit[j].second;
			int last_num_of_ships = ship_list.Num_of_ships();
			if (board.Is_field_free(row, col)) {
				j = distribution2(generator);
				row = fields_to_hit[j].first;
				col = fields_to_hit[j].second;
			}
			board.Hit_field(row, col);
			if (board.Is_Occupied_field(row, col)) {
				if (field_shot.second == col) {
					if (row - 1 > -1) {
						if (board.Checkfield(row - 1, col) == false && board.Is_field_free(row - 1, col) == false) {
							fields_to_hit.push_back(make_pair(row - 1, col));
						}
					}
					if (row + 1 < 10) {
						if (board.Checkfield(row + 1, col) == false && board.Is_field_free(row + 1, col) == false) {
							fields_to_hit.push_back(make_pair(row + 1, col));
						}
					}
					if (col - 1 > -1) {
						if (board.Checkfield(row, col - 1) == false && board.Is_field_free(row, col - 1) == false) {
							board.Set_field_free(row, col - 1);
						}
					}
					if (col + 1 < 10) {
						if (board.Checkfield(row, col + 1) == false && board.Is_field_free(row, col + 1) == false) {
							board.Set_field_free(row, col + 1);
						}
					}
					for (int h = 0;h < fields_to_hit.size();h++) {
						if (fields_to_hit[h].second != col) {
							board.Set_field_free(fields_to_hit[h].first, fields_to_hit[h].second);
						}
					}
					//if (fields_to_hit.size() > 0) {
					//	for (auto it = fields_to_hit.begin(); it != fields_to_hit.end();) {
					//		if (board.Is_field_free(it->first, it->second)) {
					//			it = fields_to_hit.erase(it);
					//		}
					//		else {
					//			++it;
					//		}
					//	}
					//}
				}
				if (field_shot.first == row) {
					if (col - 1 > -1) {
						if (board.Checkfield(row, col - 1) == false && board.Is_field_free(row, col - 1) == false) {
							fields_to_hit.push_back(make_pair(row, col - 1));
						}
					}
					if (col + 1 < 10) {
						if (board.Checkfield(row, col + 1) == false && board.Is_field_free(row, col + 1) == false) {
							fields_to_hit.push_back(make_pair(row, col + 1));
						}
					}
					if (row - 1 > -1) {
						if (board.Checkfield(row - 1, col) == false && board.Is_field_free(row - 1, col) == false) {
							board.Set_field_free(row-1, col);
						}
					}
					if (row + 1 < 10) {
						if (board.Checkfield(row + 1, col) == false && board.Is_field_free(row + 1, col) == false) {
							board.Set_field_free(row + 1, col);
						}
					}
					for (int h = 0;h < fields_to_hit.size();h++) {
						if (fields_to_hit[h].first != row) {
							board.Set_field_free(fields_to_hit[h].first, fields_to_hit[h].second);
						}
					}
					//if (fields_to_hit.size() > 0) {
					//	for (auto it = fields_to_hit.begin(); it != fields_to_hit.end();) {
					//		if (board.Is_field_free(it->first, it->second)) {
					//			it = fields_to_hit.erase(it);
					//		}
					//		else {
					//			++it;
					//		}
					//	}
					//}
				}

			}
			ship_list.Check_ships(board);
			int curr_num_of_ships = ship_list.Num_of_ships();
			if (last_num_of_ships != curr_num_of_ships) {
				fields_to_hit.clear();
				fields_to_hit.resize(0);
				fields_left.clear();
				fields_left.resize(0);
				for (int b_row = 0;b_row < 10;b_row++) {
					for (int b_col = 0;b_col < 10;b_col++) {
						if (board.Checkfield(b_row, b_col) == false && board.Is_field_free(b_row, b_col) == false) {
							fields_left.push_back(make_pair(b_row, b_col));
						}
					}
				}
			}
			else {
				fields_to_hit.erase(fields_to_hit.begin() + j);
			}
		}
	}
}
/**
* \brief Konstruktor klasy Enemy.
*
* Tworzy koordynaty wszystkich pól na planszy do których przeciwnik ma strzelać
*/
Enemy::Enemy()
{
	for (int row = 0;row < 10;row++) {
		for (int col = 0;col < 10;col++) {
			fields_left.push_back(make_pair(row, col));
		}
	}
}
/**
* \brief Restartuje przeciwnika.
*
* Ta metoda resetuje pola, które mają być trafione przez przeciwnika a pola otoczenia statku są zerowane.
*/
void Enemy::Restart_enemy()
{
	fields_left.clear();
	fields_left.resize(0);
	fields_to_hit.clear();
	fields_to_hit.resize(0);
	field_shot = { 50,50 };
	for (int row = 0;row < 10;row++) {
		for (int col = 0;col < 10;col++) {
			fields_left.push_back(make_pair(row, col));
		}
	}

}