#include "Plansza.h"
#include "Pole.h"
/**
 * @brief Konstruktor klasy Board.
 *
 * Konstruktor inicjalizuje plansz� gry o okre�lonym rozmiarze.
 * Rozmiar planszy jest okre�lony przez liczb� wierszy i kolumn.
 *
 * @param wiersze Liczba wierszy na planszy.
 * @param kolumny Liczba kolumn na planszy.
 */
Board::Board(int wiersze, int kolumny) {
	board = vector<vector<Pole>>(wiersze, vector<Pole>(kolumny));
}
/**
 * @brief Wy�wietla plansz� gry.
 *
 * Metoda wy�wietla plansz� gry na okre�lonym oknie.
 * Wykorzystuje okno i plansz� przeciwnika do wy�wietlenia obu plansz na ekranie.
 * Wymiary planszy okre�lane s� na podstawie rozmiaru okna
 * Kolory p�l na planszy s� ustalane na podstawie ich stanu: 
 * Czerwony - Trafiony statek, Prze�roczysty - Pole puste(zidentyfikowane na podstawie odst�pu mi�dzy statkami), Pomara�czowy - Trafiono puste pole , Szary - Statek, Zielony - Pole oznaczone, Niebieski - Pole standardowe (stan nieznany dla gracza)
 *
 * @param window Okno SFML, na kt�rym ma by� wy�wietlona plansza.
 * @param enemy Plansza przeciwnika.
 */
void Board::Display(sf::RenderWindow& window, Board& enemy,bool game,bool otaczanie) {
    sf::Vector2u size = window.getSize();
    float w = size.x/22;
    sf::Vector2f fieldSize(w, w);
    sf::Vector2f padding(0, 0);
    sf::RectangleShape field(fieldSize);

    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[row].size(); col++) {
            field.setPosition(col * (fieldSize.x + padding.x)+1, (row * fieldSize.y)+board.size()*20);
            if (board[row][col].is_sunk()) {
                field.setFillColor(sf::Color::White);
            }
            else if (board[row][col].Field_is_hitted() && board[row][col].Fiel_is_occupied()) {
                field.setFillColor(sf::Color::Red);
            }
            else if (board[row][col].Field_is_free() && otaczanie==true) {
                field.setFillColor(sf::Color::Transparent);
            }
            else if (board[row][col].Field_is_hitted()) {
                field.setFillColor(sf::Color::Color(219, 126, 12));
            }
            else if (board[row][col].Fiel_is_occupied()) {
                field.setFillColor(sf::Color::Color(146, 171, 189));
            }
            else if (board[row][col].Field_is_marked()) {
                field.setFillColor(sf::Color::Green);
            }
            else {
                field.setFillColor(sf::Color::Blue);
            }
            field.setOutlineThickness(1);
            field.setOutlineColor(sf::Color::White);
            window.draw(field);
        }
    }

    // Powtarza to samo dla planszy przeciwnika z danym odst�pem
    for (int row = 0; row < enemy.board.size(); row++) {
        for (int col = 0; col < enemy.board[row].size(); col++) {
            field.setPosition((col * (fieldSize.x + padding.x)) + (fieldSize.x*board.size() + fieldSize.x * 2), (row * fieldSize.y) + board.size() * 20);
            if (enemy.board[row][col].is_sunk()) {
                field.setFillColor(sf::Color::White);
            }
            else if (enemy.board[row][col].Field_is_hitted() && enemy.board[row][col].Fiel_is_occupied()) {
                field.setFillColor(sf::Color::Red);
            }
            else if (enemy.board[row][col].Field_is_free() && game==true && otaczanie==true) {
                field.setFillColor(sf::Color::Transparent);
            }
            else if (enemy.board[row][col].Field_is_hitted()) {
                field.setFillColor(sf::Color::Color(219, 126, 12));
            }
            else if (enemy.board[row][col].Field_is_marked()) {
                field.setFillColor(sf::Color::Green);
            }
            else {
                field.setFillColor(sf::Color::Blue);
            }
            field.setOutlineThickness(1);
            field.setOutlineColor(sf::Color::White);
            window.draw(field);
        }
    }

}

/**
 * \brief Sprawdza, czy pole zosta�o trafione.
 *
 * Ta metoda sprawdza, czy pole na danym indeksie zosta�o trafione.
 *
 * \param clickedRow Indeks wiersza pola.
 * \param clickedCol Indeks kolumny pola.
 * \return Zwraca true, je�li pole zosta�o trafione, false w przeciwnym razie.
 */
bool Board::Checkfield(int clickedRow, int clickedCol)
{
   return board[clickedRow][clickedCol].Field_is_hitted();
}
/**
 * \brief Sprawdza, czy pole jest oznaczone.
 *
 * Ta metoda sprawdza, czy pole na danym indeksie jest oznaczone.
 *
 * \param clickedRow Indeks wiersza pola.
 * \param clickedCol Indeks kolumny pola.
 * \return Zwraca true, je�li pole jest oznaczone, false w przeciwnym razie.
 */
bool Board::isMarked(int clickedRow, int clickedCol)
{
    return board[clickedRow][clickedCol].Field_is_marked();
}
/**
 * \brief Oznacza pole.
 *
 * Ta metoda oznacza pole na danym indeksie.
 *
 * \param clickedRow Indeks wiersza pola.
 * \param clickedCol Indeks kolumny pola.
 */
void Board::Mark_field(int clickedRow, int clickedCol)
{
    board[clickedRow][clickedCol].Mark();
}
/**
 * \brief Odznacza pole.
 *
 * Ta metoda odznacza pole na danym indeksie.
 *
 * \param clickedRow Indeks wiersza pola.
 * \param clickedCol Indeks kolumny pola.
 */
void Board::Unmark_field(int clickedRow, int clickedCol)
{
    board[clickedRow][clickedCol].Unmark();
}
/**
 * \brief Odznacza wiele p�l.
 *
 * Ta metoda odznacza wiele p�l na podstawie podanych wsp�rz�dnych.
 *
 * \param coords Wektor par indeks�w wierszy i kolumn, kt�re identyfikuj� pola do odznaczenia.
 */
void Board::Unmark_fields(vector<pair<int, int>> coords)
{
    for (int i = 0;i < coords.size();i++) {
        board[coords[i].first][coords[i].second].Unmark();
    }
}
/**
 * \brief Trafia pole.
 *
 * Ta metoda oznacza pole jako trafione na podstawie podanych wsp�rz�dnych.
 *
 * \param row Indeks wiersza pola.
 * \param col Indeks kolumny pola.
 */
void Board::Hit_field(int row, int col)
{
    board[row][col].Shot();
}
/**
 * \brief Ustawia pole jako wolne.
 *
 * Ta metoda ustawia pole jako wolne na podstawie podanych wsp�rz�dnych.
 * U�ywana gdy zatopiono statek
 * \param row Indeks wiersza pola.
 * \param col Indeks kolumny pola.
 */
void Board::Set_field_free(int row, int col)
{
    board[row][col].Set_field_free();
}

void Board::Set_field_sunk(int row, int col)
{
    board[row][col].set_sunk();
}

/**
 * \brief Ustawia statki na planszy.
 *
 * Ta metoda ustawia statki na planszy na podstawie podanych wsp�rz�dnych.
 * Sprawdza czy zaznaczone pola s�siaduj� ze sob� na podstawie zaznaczenia oraz sprawdza czy dane pola zaznaczone oraz pola s�siednie nie s� ju� zaj�te
 * Je�eli spe�niono warunki wywo�ana zostaje p�tla oznaczaj�ca pola jako zaj�te i statek zostaje ustawiony
 * \param coords Wektor par indeks�w wierszy i kolumn, kt�re identyfikuj� pola dla statk�w.
 * \return Zwraca true, je�li uda�o si� prawid�owo ustawi� statki, false w przeciwnym razie.
 */
bool Board::Set_ship(vector<pair<int, int>> coords,int mode)
{   
    if (mode == 2) {
        int marked_fields = 0;
        bool set = true;
        if (coords.size() == 1) {
            for (int row = coords[0].first - 1;row <= coords[0].first + 1;row++) {
                for (int col = coords[0].second - 1;col <= coords[0].second + 1;col++) {
                    if (row > -1 && row < 10 && col > -1 && col < 10) {
                        if (board[row][col].Fiel_is_occupied()) {
                            set = false;
                        }

                    }
                }
            }
            if (set == true) {
                for (int i = 0;i < coords.size();i++) {
                    board[coords[i].first][coords[i].second].SetField();
                }
                return true;
            }
            else {
                return false;
            }
        }
        for (int i = 0;i < coords.size(); i++) {
            for (int row = coords[i].first - 1;row <= coords[i].first + 1;row++) {
                for (int col = coords[i].second - 1;col <= coords[i].second + 1;col++) {
                    if (row > -1 && row < 10 && col > -1 && col < 10) {
                        if (board[row][col].Fiel_is_occupied()) {
                            set = false;
                        }
                        if (board[row][col].Field_is_marked()) {
                            marked_fields++;
                        }

                    }
                    else {
                        marked_fields = 2;
                    }
                }
            }
            if (marked_fields < 2) {
                set = false;
            }
            marked_fields = 0;
        }
        if (set == true) {
            for (int i = 0;i < coords.size();i++) {
                board[coords[i].first][coords[i].second].SetField();
            }
            return true;
        }
        else {
            return false;
        }
    }
    else if(mode==1) {
        int marked_fields = 0;
        bool set = true;
        if (coords.size() == 3) {
            if (coords[0].first == coords[1].first && coords[0].first == coords[2].first || coords[0].second == coords[1].second && coords[0].second == coords[2].second) {
                for (int i = 0;i < coords.size();i++) {
                    board[coords[i].first][coords[i].second].SetField();
                }
                return true;
            }
            else {
                return false;
            }
        }
        if (coords.size() == 1) {
            for (int row = coords[0].first - 1;row <= coords[0].first + 1;row++) {
                for (int col = coords[0].second - 1;col <= coords[0].second + 1;col++) {
                    if (row > -1 && row < 10 && col > -1 && col < 10) {
                        if (board[row][col].Fiel_is_occupied()) {
                            set = false;
                        }

                    }
                }
            }
            if (set == true) {
                for (int i = 0;i < coords.size();i++) {
                    board[coords[i].first][coords[i].second].SetField();
                }
                return true;
            }
            else {
                return false;
            }
        }
        else {
            for (int i = 0;i < coords.size(); i++) {
                for (int row = coords[i].first - 1;row <= coords[i].first + 1;row++) {
                    for (int col = coords[i].second - 1;col <= coords[i].second + 1;col++) {
                        if (row > -1 && row < 10 && col > -1 && col < 10) {
                            if (board[row][col].Fiel_is_occupied()) {
                                set = false;
                            }
                            if (board[row][col].Field_is_marked()) {
                                marked_fields++;
                            }

                        }
                    }
                }
                if (marked_fields < 2 || marked_fields >3) {
                    set = false;
                }
                marked_fields = 0;
            }
        }
        if (set == true) {
            int skos = 0;
            for (int g = 0;g < coords.size();g++) {
                if (coords[g].first > 0) {
                    if (board[coords[g].first - 1][coords[g].second].Field_is_marked()) {
                        skos++;
                    }
                }
                if (coords[g].first < 9) {
                    if (board[coords[g].first + 1][coords[g].second].Field_is_marked()) {
                        skos++;
                    }
                }
                if (coords[g].second > 0) {
                    if (board[coords[g].first][coords[g].second - 1].Field_is_marked()) {
                        skos++;
                    }
                }
                if (coords[g].second < 9) {
                    if (board[coords[g].first][coords[g].second + 1].Field_is_marked()) {
                        skos++;
                    }
                }
                if (skos == 0) {
                    set = false;
                }
                skos = 0;
            }
            if (set == true) {
                for (int i = 0;i < coords.size();i++) {
                    board[coords[i].first][coords[i].second].SetField();
                }
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }

    }
}

bool Board::Set_player_ship(vector<pair<int, int>> coords, int mode)
{
        if (mode == 2) {
            int marked_fields = 0;
            bool set = true;
            if (coords.size() == 1) {
                for (int row = coords[0].first - 1;row <= coords[0].first + 1;row++) {
                    for (int col = coords[0].second - 1;col <= coords[0].second + 1;col++) {
                        if (row > -1 && row < 10 && col > -1 && col < 10) {
                            if (board[row][col].Fiel_is_occupied()) {
                                set = false;
                            }

                        }
                    }
                }
                if (set == true) {
                    for (int i = 0;i < coords.size();i++) {
                        board[coords[i].first][coords[i].second].SetField();
                    }
                    for (int j = 0; j < coords.size();j++) {
                        for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                            for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                                if (row > -1 && row < 10 && col > -1 && col < 10) {
                                    Set_field_free(row, col);
                                }
                            }
                        }
                    }
                    return true;
                }
                else {
                    return false;
                }
            }
            for (int i = 0;i < coords.size(); i++) {
                for (int row = coords[i].first - 1;row <= coords[i].first + 1;row++) {
                    for (int col = coords[i].second - 1;col <= coords[i].second + 1;col++) {
                        if (row > -1 && row < 10 && col > -1 && col < 10) {
                            if (board[row][col].Fiel_is_occupied()) {
                                set = false;
                            }
                            if (board[row][col].Field_is_marked()) {
                                marked_fields++;
                            }

                        }
                        else {
                            marked_fields = 2;
                        }
                    }
                }
                if (marked_fields < 2) {
                    set = false;
                }
                marked_fields = 0;
            }
            if (set == true) {
                for (int i = 0;i < coords.size();i++) {
                    board[coords[i].first][coords[i].second].SetField();
                }
                for (int j = 0; j < coords.size();j++) {
                    for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                        for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                            if (row > -1 && row < 10 && col > -1 && col < 10) {
                                Set_field_free(row, col);
                            }
                        }
                    }
                }
                return true;
            }
            else {
                return false;
            }
        }
        else if (mode == 1) {
            int marked_fields = 0;
            bool set = true;
            if (coords.size() == 1) {
                for (int row = coords[0].first - 1;row <= coords[0].first + 1;row++) {
                    for (int col = coords[0].second - 1;col <= coords[0].second + 1;col++) {
                        if (row > -1 && row < 10 && col > -1 && col < 10) {
                            if (board[row][col].Fiel_is_occupied()) {
                                set = false;
                            }

                        }
                    }
                }
                if (set == true) {
                    for (int i = 0;i < coords.size();i++) {
                        board[coords[i].first][coords[i].second].SetField();
                    }

                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                for (int i = 0;i < coords.size(); i++) {
                    for (int row = coords[i].first - 1;row <= coords[i].first + 1;row++) {
                        for (int col = coords[i].second - 1;col <= coords[i].second + 1;col++) {
                            if (row > -1 && row < 10 && col > -1 && col < 10) {
                                if (board[row][col].Fiel_is_occupied()) {
                                    set = false;
                                }
                                if (board[row][col].Field_is_marked()) {
                                    marked_fields++;
                                }

                            }
                        }
                    }
                    if (marked_fields < 2 || marked_fields >3) {
                        set = false;
                    }
                    marked_fields = 0;
                }
            }
            if (set == true) {
                int skos=0;
                for (int g = 0;g < coords.size();g++) {
                    if (coords[g].first > -1) {
                        if (board[coords[g].first - 1][coords[g].second].Field_is_marked()) {
                            skos++;
                        }
                    }
                    if (coords[g].first < 10) {
                        if (board[coords[g].first + 1][coords[g].second].Field_is_marked()) {
                            skos++;
                        }
                    }
                    if ( coords[g].second > -1) {
                        if (board[coords[g].first][coords[g].second - 1].Field_is_marked()) {
                            skos++;
                        }
                    }
                    if (coords[g].second < 10) {
                        if (board[coords[g].first][coords[g].second + 1].Field_is_marked()) {
                            skos++;
                        }
                    }
                    if (skos == 0) {
                        set = false;
                    }
                }
                if (set == true) {
                    for (int i = 0;i < coords.size();i++) {
                        board[coords[i].first][coords[i].second].SetField();
                    }
                    for (int j = 0; j < coords.size();j++) {
                        for (int row = coords[j].first - 1;row <= coords[j].first + 1;row++) {
                            for (int col = coords[j].second - 1;col <= coords[j].second + 1;col++) {
                                if (row > -1 && row < 10 && col > -1 && col < 10) {
                                    Set_field_free(row, col);
                                }
                            }
                        }
                    }
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }

        }
}

/**
 * \brief Sprawdza, czy pole jest wolne.
 *
 * Ta metoda sprawdza, czy pole na danym indeksie jest wolne.
 *
 * \param row Indeks wiersza pola.
 * \param col Indeks kolumny pola.
 * \return Zwraca true, je�li pole jest wolne, false w przeciwnym razie.
 */
bool Board::Is_field_free(int row, int col)
{
    return board[row][col].Field_is_free();
}

/**
 * \brief Sprawdza, czy pole jest zaj�te.
 *
 * Ta metoda sprawdza, czy pole na danym indeksie jest zaj�te.
 *
 * \param row Indeks wiersza pola.
 * \param col Indeks kolumny pola.
 * \return Zwraca true, je�li pole jest zaj�te, false w przeciwnym razie.
 */
bool Board::Is_Occupied_field(int row, int col)
{
    return board[row][col].Fiel_is_occupied();
}
bool Board::is_field_sunk(int row, int col)
{
    return board[row][col].is_sunk();
}
/**
 * \brief Czy�ci plansz�.
 *
 * Ta metoda czy�ci wszystkie pola na planszy.
 */
void Board::Clear_board()
{
    for (int i = 0;i < board.size();i++) {
        for (int j = 0;j < board[i].size();j++) {
            board[i][j].Free();
        }
    }
}

void Board::Change_free_fields()
{
    for (int i = 0;i < board.size();i++) {
        for (int j = 0;j < board[i].size();j++) {
            board[i][j].Free_Field_To_False();
        }
    }
}

/**
 * \brief Trafia pole.
 *
 * Ta metoda oznacza pole jako trafione na podstawie podanych wsp�rz�dnych.
 *
 * \param clickedRow Indeks wiersza pola.
 * \param clickedCol Indeks kolumny pola.
 */
void Board::Ustaw(int clickedRow, int clickedCol) {

    if (clickedRow >= 0 && clickedRow < 10 && clickedCol >= 0 && clickedCol < 10)
    {
        board[clickedRow][clickedCol].Shot();
    }
}