#include "ListaStatkow.h"
/**
 * \brief Zwraca liczbê statków.
 *
 * \return Zwraca liczbê statków.
 */
int ListaStatkow::Num_of_ships()
{
    return number_of_ships;
}

/**
 * \brief Dodaje statek do listy gracza.
 *
 * Ta metoda dodaje statek do listy statków na planszy, jeœli spe³nione s¹ okreœlone warunki (nie przekroczono limitu pól i nie przekroczono liczby statków danego typu.
 *
 * \param coords Wektor par indeksów wierszy i kolumn, które identyfikuj¹ pola statku.
 * \param ship_type Typ statku.
 * \param board Plansza, na której dodawany jest statek.
 */
void ListaStatkow::Add_ship(vector<pair<int, int>> coords, int ship_type,Board& board,int tryb,bool otaczanie, int jedno, int dwu, int trzy, int cztero, int pieco,int fields_acc)
{
    if (ship_type == 5 && five_masted < pieco && fields < fields_acc - 4) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            five_masted++;
            if (otaczanie == true) {
                for (int j = 0; j < coords.size();j++) {
                    for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                        for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                            if (row > -1 && row < 10 && col > -1 && col < 10 && board.Is_Occupied_field(row,col)==false) {
                                board.Set_field_free(row, col);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (ship_type == 4 && four_masted < cztero && fields < fields_acc - 3) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            four_masted++;
            if (otaczanie == true) {
                for (int j = 0; j < coords.size();j++) {
                    for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                        for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                            if (row > -1 && row < 10 && col > -1 && col < 10 && board.Is_Occupied_field(row, col) == false) {
                                board.Set_field_free(row, col);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (ship_type == 3 && three_masted < trzy && fields < fields_acc - 2) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            three_masted++;
            if (otaczanie == true) {
                for (int j = 0; j < coords.size();j++) {
                    for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                        for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                            if (row > -1 && row < 10 && col > -1 && col < 10 && board.Is_Occupied_field(row, col) == false) {
                                board.Set_field_free(row, col);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (ship_type == 2 && two_masted < dwu && fields < fields_acc - 1) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            two_masted++;
            if (otaczanie == true) {
                for (int j = 0; j < coords.size();j++) {
                    for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                        for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                            if (row > -1 && row < 10 && col > -1 && col < 10 && board.Is_Occupied_field(row, col) == false) {
                                board.Set_field_free(row, col);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (ship_type == 1 && one_masted < jedno && fields < fields_acc) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            one_masted++;
            if (otaczanie == true) {
                for (int j = 0; j < coords.size();j++) {
                    for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                        for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                            if (row > -1 && row < 10 && col > -1 && col < 10 && board.Is_Occupied_field(row, col) == false) {
                                board.Set_field_free(row, col);
                            }
                        }
                    }
                }
            }
        }
    }
}
/**
 * \brief Dodaje statek do listy przeciwnika.
 *
 * Ta metoda dodaje statek do listy statków na planszy, jeœli spe³nione s¹ okreœlone warunki (nie przekroczono limitu pól i nie przekroczono liczby statków danego typu.
 *
 * \param coords Wektor par indeksów wierszy i kolumn, które identyfikuj¹ pola statku.
 * \param ship_type Typ statku.
 * \param board Plansza, na której dodawany jest statek.
 */
void ListaStatkow::Add_enemy_ship(vector<pair<int, int>> coords, int ship_type, Board& board,int tryb, int jedno, int dwu, int trzy, int cztero, int pieco, int fields_acc)
{
    if (ship_type == 5 && five_masted < pieco && fields < fields_acc-4) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            five_masted++;
        }
    }
    if (ship_type == 4 && four_masted < cztero && fields < fields_acc - 3) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            four_masted++;
        }
    }
    if (ship_type == 3 && three_masted < trzy && fields < fields_acc - 2) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            three_masted++;
        }
    }
    if (ship_type == 2 && two_masted < dwu && fields < fields_acc - 1) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            two_masted++;
        }
    }
    if (ship_type == 1 && one_masted < jedno && fields < fields_acc) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            one_masted++;
        }
    }
}
void ListaStatkow::Add_enemy_ship_classic(vector<pair<int, int>> coords, int ship_type, Board& board,int tryb)
{

    if (ship_type == 4 && four_masted < 1 && fields < 17) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            four_masted++;
        }
    }
    if (ship_type == 3 && three_masted < 2 && fields < 18) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            three_masted++;
        }
    }
    if (ship_type == 2 && two_masted < 3 && fields < 19) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            two_masted++;
        }
    }
    if (ship_type == 1 && one_masted < 4 && fields < 20) {
        bool is_ship_set = board.Set_ship(coords,tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            one_masted++;
        }
    }
}
void ListaStatkow::Add_ship_classic(vector<pair<int, int>> coords, int ship_type, Board& board, int tryb, bool otaczanie)
{
    if (ship_type == 4 && four_masted < 1 && fields < 17) {
        bool is_ship_set = board.Set_ship(coords, tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            four_masted++;
            if (otaczanie == true) {
                for (int j = 0; j < coords.size();j++) {
                    for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                        for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                            if (row > -1 && row < 10 && col > -1 && col < 10 && board.Is_Occupied_field(row, col) == false) {
                                board.Set_field_free(row, col);
                            }
                        }
                    }
                }
            }
        }
    }
    if (ship_type == 3 && three_masted < 2 && fields < 18) {
        bool is_ship_set = board.Set_ship(coords, tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            three_masted++;
            if (otaczanie == true) {
                for (int j = 0; j < coords.size();j++) {
                    for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                        for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                            if (row > -1 && row < 10 && col > -1 && col < 10 && board.Is_Occupied_field(row, col) == false) {
                                board.Set_field_free(row, col);
                            }
                        }
                    }
                }
            }
        }
    }
    if (ship_type == 2 && two_masted < 3 && fields < 19) {
        bool is_ship_set = board.Set_ship(coords, tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            two_masted++;
            if (otaczanie == true) {
                for (int j = 0; j < coords.size();j++) {
                    for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                        for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                            if (row > -1 && row < 10 && col > -1 && col < 10 && board.Is_Occupied_field(row, col) == false) {
                                board.Set_field_free(row, col);
                            }
                        }
                    }
                }
            }
        }
    }
    if (ship_type == 1 && one_masted < 4 && fields < 20) {
        bool is_ship_set = board.Set_ship(coords, tryb);
        if (is_ship_set == true) {
            ship_list.push_back(Statek(coords, ship_type));
            number_of_ships++;
            fields = fields + ship_type;
            one_masted++;
            if (otaczanie == true) {
                for (int j = 0; j < coords.size();j++) {
                    for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                        for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                            if (row > -1 && row < 10 && col > -1 && col < 10 && board.Is_Occupied_field(row, col) == false) {
                                board.Set_field_free(row, col);
                            }
                        }
                    }
                }
            }
        }
    }
}
/**
 * \brief Czyœci listê statków.
 *
 * Ta metoda usuwa wszystkie statki z listy i czyœci planszê.
 *
 * \param board Plansza, na której znajduj¹ siê statki.
 */
void ListaStatkow::Clear_ship_list(Board& board)
{
    board.Clear_board();
    ship_list.clear();
    ship_list.resize(0);
    fields = 0;
    number_of_ships = 0;
    five_masted = 0;
    four_masted = 0;
    three_masted = 0;
    two_masted = 0;
    one_masted = 0;
}
/**
 * \brief Sprawdza, czy jakikolwiek statek zosta³ zatopiony.
 *
 * Ta metoda sprawdza, czy jakikolwiek statek zosta³ zatopiony. Jeœli tak, statek jest usuwany z listy.
 *
 * \param board Plansza, na której znajduj¹ siê statki.
 */
void ListaStatkow::Check_ships(Board& board)
{
    for (int i = 0;i < ship_list.size();i++) {
        bool is_sunk=ship_list[i].Check_ship(board);
        if (is_sunk == true) {
            number_of_ships--;
            ship_list.erase(ship_list.begin() + i);
            break;
        }
    }
}
/**
 * \brief Wyœwietla informacje o wszystkich statkach.
 *
 * Ta metoda wyœwietla informacje o wszystkich statkach w liœcie, w tym ich numer i koordynaty.
 */
void ListaStatkow::Wypisz()
{
    for (int i = 0;i < ship_list.size();i++) {
        cout << endl;
        cout << "Statek nr" << i << " :";
        ship_list[i].Wypisz();
    }
}
/**
 * \brief Zwraca liczbê skumulowanych pól wszystkich statków.
 *
 * \return Zwraca liczbê skumulowanych pól wszystkich statków.
 */
int ListaStatkow::Num_of_fields()
{
    return fields;
}

/**
 * \brief Generuje statki przeciwnika na planszy.
 *
 * Ta metoda generuje statki przeciwnika na planszy. Statki s¹ umieszczane losowo na planszy.
 * Gdy nie przekroczono iloœæ pól i rodzaju statku to losuje siê pierwsze pole i je¿eli jest puste to zaznacza je a nastêpnie losuj¹ siê strona w któr¹ bêdzie siê generowaæ kolejne pole.
 * Gdy wszystkie pola uda siê zaznaczyæ wywo³ana zostaje metoda dodania statku
 *
 * \param enemy Plansza przeciwnika, na której maj¹ byæ umieszczone statki.
 */
void ListaStatkow::Generate_Enemy_Ships(Board& enemy,int tryb, int jedno, int dwu, int trzy, int cztero, int pieco,int fields_acc)
{
    bool set = true;
    int count = 0;
    int type;
    if (tryb == 2) {
        while (fields != fields_acc) {
            vector<pair<int, int>> coords;
            random_device rd;
            mt19937 generator(rd());
            uniform_int_distribution<int> distribution(1, 5);
            uniform_int_distribution<int> distribution_2(0, 9);
            type = distribution(generator);
            if (fields == fields_acc) {
                type = 1;
            }
            //if (type == 1 && fields != 19) {
            //    continue;
            //}
            //if (fields == 18 && two_masted < 4) {
            //    type = 2;
            //}
            //if (type == 2 && two_masted == 4) {
            //    continue;
            //}
            //if (type == 3 && three_masted == 3) {
            //    continue;
            //}
            //if (type == 4 && three_masted == 3) {
            //    continue;
            //}
            //if (type == 5 && three_masted == 2) {
            //    continue;
            //}
            int x = distribution_2(generator);
            int y = distribution_2(generator);
            coords.push_back(make_pair(x, y));
            if (enemy.Is_Occupied_field(x, y) == false) {
                enemy.Mark_field(x, y);
            }
            else {
                continue;
            }
            for (int i = 1;i < type;i++) {
                set = true;
                int strona = rand() % 2 + 1;
                if (strona == 1) {
                    do {
                        strona = rand() % 2 + 1;
                        if (strona == 1 && x < 9) {
                            x = x + 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                        else if (strona == 2 && x > 1) {
                            x = x - 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                    } while (set == true);
                }
                else if (strona == 2) {
                    do {
                        strona = rand() % 2 + 1;
                        if (strona == 1 && y < 9) {
                            y = y + 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                        else if (strona == 2 && y > 1) {
                            y = y - 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                    } while (set == true);
                }
            }
            Add_enemy_ship(coords, coords.size(), enemy,tryb,jedno,dwu,trzy,cztero,pieco, fields_acc);
            cout << fields;
            enemy.Unmark_fields(coords);
            count++;
            if (count == 300) {
                Clear_ship_list(enemy);
            }

        }
    }
    else {
        while (fields != 20) {
            vector<pair<int, int>> coords;
            count = 0;
            set = true;
            random_device rd;
            mt19937 generator(rd());
            uniform_int_distribution<int> distribution(1, 4);
            uniform_int_distribution<int> distribution_2(0, 9);
            type = distribution(generator);
            if (fields == 19) {
                type = 1;
            }
            //if (type == 1 && fields != 19) {
            //    continue;
            //}
            //if (fields == 18 && two_masted < 4) {
            //    type = 2;
            //}
            //if (type == 2 && two_masted == 4) {
            //    continue;
            //}
            //if (type == 3 && three_masted == 3) {
            //    continue;
            //}
            //if (type == 4 && three_masted == 3) {
            //    continue;
            //}
            //if (type == 5 && three_masted == 2) {
            //    continue;
            //}
            int strona = rand() % 2 + 1;
            int licz = 0;
            int x = distribution_2(generator);
            cout << x;
            int y = distribution_2(generator);
            coords.push_back(make_pair(x, y));
            if (enemy.Is_Occupied_field(x, y) == false) {
                enemy.Mark_field(x, y);
            }
            else {
                continue;
            }
            for (int i = 1;i < type;i++) {
                set = true;
                
                if (strona == 1) {
                    do {
                       int stronax = rand() % 2 + 1;
                        if (stronax == 1 && x < 9) {
                            licz++;
                            x = x + 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                        else if (stronax == 2 && x > 1) {
                            licz++;
                            x = x - 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                    } while (set == true);
                }
                else if (strona == 2) {
                    do {
                        int stronay = rand() % 2 + 1;
                        if (stronay == 1 && y < 9) {
                            licz++;
                            y = y + 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                        else if (stronay == 2 && y > 1) {
                            licz++;
                            y = y - 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                        if (licz == 20) {
                            break;
                        }
                    } while (set == true);
                }
            }
            Add_enemy_ship_classic(coords, coords.size(), enemy,tryb);
            cout << fields;
            enemy.Unmark_fields(coords);
            count++;
            if (count == 300) {
                Clear_ship_list(enemy);
            }

        }
    }
}

void ListaStatkow::Generate_Player_Ships(Board& enemy, int tryb,bool otaczanie, int jedno, int dwu, int trzy, int cztero, int pieco,int fields_acc)
{
    bool set = true;
    int count = 0;
    int type;
    if (tryb == 2) {
        while (fields != fields_acc) {
            vector<pair<int, int>> coords;
            random_device rd;
            mt19937 generator(rd());
            uniform_int_distribution<int> distribution(1, 5);
            uniform_int_distribution<int> distribution_2(0, 9);
            type = distribution(generator);
            if (fields == fields_acc-1) {
                type = 1;
            }
            //if (type == 1 && fields != 19) {
            //    continue;
            //}
            //if (fields == 18 && two_masted < 4) {
            //    type = 2;
            //}
            //if (type == 2 && two_masted == 4) {
            //    continue;
            //}
            //if (type == 3 && three_masted == 3) {
            //    continue;
            //}
            //if (type == 4 && three_masted == 3) {
            //    continue;
            //}
            //if (type == 5 && three_masted == 2) {
            //    continue;
            //}
            int x = distribution_2(generator);
            int y = distribution_2(generator);
            coords.push_back(make_pair(x, y));
            if (enemy.Is_Occupied_field(x, y) == false) {
                enemy.Mark_field(x, y);
            }
            else {
                continue;
            }
            for (int i = 1;i < type;i++) {
                set = true;
                int strona = rand() % 2 + 1;
                if (strona == 1) {
                    do {
                        strona = rand() % 2 + 1;
                        if (strona == 1 && x < 9) {
                            x = x + 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                        else if (strona == 2 && x > 1) {
                            x = x - 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                    } while (set == true);
                }
                else if (strona == 2) {
                    do {
                        strona = rand() % 2 + 1;
                        if (strona == 1 && y < 9) {
                            y = y + 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                        else if (strona == 2 && y > 1) {
                            y = y - 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                    } while (set == true);
                }
            }
            Add_ship(coords, coords.size(), enemy, tryb,otaczanie,jedno,dwu,trzy,cztero,pieco, fields_acc);
            cout << fields;
            enemy.Unmark_fields(coords);
            count++;
            if (count == 300) {
                Clear_ship_list(enemy);
            }

        }
    }
    else {
        while (fields != 20) {
            vector<pair<int, int>> coords;
            count = 0;
            set = true;
            random_device rd;
            mt19937 generator(rd());
            uniform_int_distribution<int> distribution(1, 4);
            uniform_int_distribution<int> distribution_2(0, 9);
            type = distribution(generator);
            if (fields == 19) {
                type = 1;
            }
            //if (type == 1 && fields != 19) {
            //    continue;
            //}
            //if (fields == 18 && two_masted < 4) {
            //    type = 2;
            //}
            //if (type == 2 && two_masted == 4) {
            //    continue;
            //}
            //if (type == 3 && three_masted == 3) {
            //    continue;
            //}
            //if (type == 4 && three_masted == 3) {
            //    continue;
            //}
            //if (type == 5 && three_masted == 2) {
            //    continue;
            //}
            int strona = rand() % 2 + 1;
            int licz = 0;
            int x = distribution_2(generator);
            cout << x;
            int y = distribution_2(generator);
            coords.push_back(make_pair(x, y));
            if (enemy.Is_Occupied_field(x, y) == false) {
                enemy.Mark_field(x, y);
            }
            else {
                continue;
            }
            for (int i = 1;i < type;i++) {
                set = true;

                if (strona == 1) {
                    do {
                        int stronax = rand() % 2 + 1;
                        if (stronax == 1 && x < 9) {
                            licz++;
                            x = x + 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                        else if (stronax == 2 && x > 1) {
                            licz++;
                            x = x - 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                    } while (set == true);
                }
                else if (strona == 2) {
                    do {
                        int stronay = rand() % 2 + 1;
                        if (stronay == 1 && y < 9) {
                            licz++;
                            y = y + 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                        else if (stronay == 2 && y > 1) {
                            licz++;
                            y = y - 1;
                            set = enemy.isMarked(x, y);
                            if (set == false && enemy.Is_Occupied_field(x, y) == false) {
                                enemy.Mark_field(x, y);
                                coords.push_back(make_pair(x, y));
                            }
                            else {
                                continue;
                            }
                        }
                        if (licz == 20) {
                            break;
                        }
                    } while (set == true);
                }
            }
            Add_ship_classic(coords, coords.size(), enemy, tryb,otaczanie);
            cout << fields;
            enemy.Unmark_fields(coords);
            count++;
            if (count == 300) {
                Clear_ship_list(enemy);
            }

        }
    }
}

