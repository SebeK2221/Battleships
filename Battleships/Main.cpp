#include "Biblioteki.h"
#include "Plansza.h"
#include "Button.h"
#include "Statek.h"
#include "ListaStatkow.h"
#include "Enemy.h"
#include "font.h"
/**
 * \brief Główna funkcja programu.
 *
 * Ta funkcja jest punktem startowym programu. Inicjuje planszę gry, tworzy listy statków dla gracza i przeciwnika, a także przeciwnika. Następnie wchodzi w główne pętle gry, obsługując zdarzenia takie jak kliknięcia myszką, naciskanie klawiszy i zmiany rozmiaru okna.
 */
int main()
{
    /// Ładowanie czczonki bezpośrednio z bajtów danych
    sf::Font font;
    font.loadFromMemory(&Roboto_Black_ttf, Roboto_Black_ttf_len);


    if (!font.loadFromMemory(&Roboto_Black_ttf, Roboto_Black_ttf_len)) {
        throw std::runtime_error("Czcionka nie zostala znaleziona!");
    }
    vector<pair<int, int>> coords;
    string ship_type_display = "Single-masted",tryb_w="Clasic",otaczanie_d="True";
    bool isMarking = false, Game = false, shot_to_set = false, players_turn = true, otaczanie_b = true, battle = false, settings = false;
    int fields = 20, count = 0, ship_set_type = 1, markedCol = -1, markedRow = -1, lastMarkCol = -100, lastmarkRow = -100, tryb=1,jedno=20,dwu=20,trzy=20,cztero=20,piecio=20,sum_fields=0;
    sf::Vector2i lastMousePos;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Statki");
    ListaStatkow player_ship_list,enemy_ship_list;
    Enemy enemy;
    Board Player_board(10,10);
    Board Enemy_board(10,10);
    Button start,set,new_game,end,display,sfields,accept,j,d,t,c,p,jb,db,tb,cb,pb,unmark,ship_type,generate_enemy,generate_player,otaczanie,otaczanie_display,liczba_statkow, display1,win,zmien_tryb,wyswietl_tryb, restart,text_fields,blue_field,red_field,orange_field,black_field,gray_field,green_field,text_field2;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                ship_set_type = 1;
                ship_type_display = "Single-masted";
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                ship_set_type = 2;
                ship_type_display = "Two-masted";
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                ship_set_type = 3;
                ship_type_display = "Three-masted";
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                ship_set_type = 4;
                ship_type_display = "Four-masted";
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
                ship_set_type = 5;
                ship_type_display = "Five-masted";
            }
            //czy otwarte okno
            if (event.type == sf::Event::Closed)
                window.close();
            //skalowanie
            else if (event.type == sf::Event::Resized) {
                if (window.getSize().x != window.getSize().y) {
                    window.setSize(sf::Vector2u(window.getSize().x, window.getSize().x));
               }
                sf::View view(sf::FloatRect(0, 0, event.size.width, event.size.height));
                window.setView(view);
            }
            // strzał
            if (event.type == sf::Event::MouseButtonPressed && (event.mouseButton.button == sf::Mouse::Left)) {
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    sf::Vector2u size = window.getSize();
                    float w = size.x / 22;
                    sf::Vector2f fieldSize(w, w);
                    sf::Vector2f padding(1, 0);
                    int clickedRow = (worldPos.y - 200) / fieldSize.y;
                    int clickedCol = worldPos.x / fieldSize.x - 12;
                    if (clickedCol > -1 && clickedCol< 10 && clickedRow > -1 && clickedRow < 10 && Enemy_board.Checkfield(clickedRow,clickedCol)==false && Game==true) {
                        Enemy_board.Mark_field(clickedRow, clickedCol);
                        //shot_to_set = true;
                        markedRow = clickedRow, markedCol = clickedCol;
                        Enemy_board.Ustaw(markedRow, markedCol);
                        enemy_ship_list.Check_ships(Enemy_board);
                       // shot_to_set = false;
                        players_turn = false;

                    }
                    // przyciski
                    if (start.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window)))&& fields - player_ship_list.Num_of_fields()==0 && fields - enemy_ship_list.Num_of_fields()==0 && settings == false) {
                        Game = true;
                        if (battle == false) {
                            Player_board.Change_free_fields();
                        }
                        battle = true;
                    }
                    if (liczba_statkow.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game==false&& settings==false) {
                            settings = true;
                            jedno = dwu = trzy = cztero = piecio = sum_fields = 0;
                    }
                    if (accept.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game == false && settings== true && sum_fields<20 && sum_fields>0) {
                        settings = false;
                        fields = sum_fields;
                    }
                    if (jb.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game == false && settings == true && sum_fields<20) {
                        jedno++;
                        sum_fields = sum_fields + 1;
                    }
                    if (db.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game == false && settings == true && sum_fields < 19) {
                        dwu++;
                        sum_fields = sum_fields + 2;
                    }
                    if (tb.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game == false && settings == true && sum_fields < 18) {
                        trzy++;
                        sum_fields = sum_fields + 3;
                    }
                    if (cb.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game == false && settings == true && sum_fields < 17) {
                        cztero++;
                        sum_fields = sum_fields + 4;
                    }
                    if (pb.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game == false && settings == true && sum_fields < 16) {
                        piecio++;
                        sum_fields = sum_fields + 5;
                    }
                    if (generate_player.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && settings == false) {
                        player_ship_list.Generate_Player_Ships(Player_board,tryb,otaczanie_b,jedno,dwu,trzy,cztero,piecio,fields);
                    }
                    if (generate_enemy.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && settings == false) {
                        enemy_ship_list.Generate_Enemy_Ships(Enemy_board,tryb,jedno, dwu, trzy, cztero, piecio,fields);
                    }
                    if (set.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window)))&& Game==false && settings == false) {
                        cout << "Ustaw";
                        for (int i = 0;i < coords.size();i++) {
                            cout << coords[i].first << "  " << coords[i].second << endl;
                        }
                        player_ship_list.Add_ship(coords, coords.size(),Player_board,tryb,otaczanie_b,jedno, dwu, trzy, cztero, piecio,fields);
                        cout << "Liczba statków :" << player_ship_list.Num_of_ships() << "Zajęte miejsca: " << player_ship_list.Num_of_fields() << endl;;
                        Player_board.Unmark_fields(coords);
                        player_ship_list.Wypisz();
                        coords.clear();
                        count = 0;
                    }
                    //if (set.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game == true && shot_to_set==true && players_turn==true) {
                    //    Enemy_board.Ustaw(markedRow, markedCol);
                    //    enemy_ship_list.Check_ships(Enemy_board);
                    //    shot_to_set = false;
                    //    players_turn = false;
                    //}
                    if (new_game.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window)))&& Game==true && settings == false) {
                        player_ship_list.Clear_ship_list(Player_board);
                        enemy_ship_list.Clear_ship_list(Enemy_board);
                        enemy.Restart_enemy();
                        players_turn = true;
                        shot_to_set = false;
                        count = 0;
                        Game = false;
                        battle = false;
                    }
                    if (restart.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game == false && settings == false) {
                        player_ship_list.Clear_ship_list(Player_board);
                        enemy_ship_list.Clear_ship_list(Enemy_board);
                        enemy.Restart_enemy();
                        players_turn = true;
                        shot_to_set = false;
                        battle = false;
                        count = 0;
                    }
                    if (end.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && settings == false) {
                        Game = false;
                    }
                    //if (unmark.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window)))&& Game==true) {
                    //   Enemy_board.Unmark_field(markedRow, markedCol);
                    //    shot_to_set = false;
                    //}
                    if (zmien_tryb.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game == false && settings == false) {
                        player_ship_list.Clear_ship_list(Player_board);
                        enemy_ship_list.Clear_ship_list(Enemy_board);
                        enemy.Restart_enemy();
                        players_turn = true;
                        shot_to_set = false;
                        count = 0;
                        if (tryb == 1) {
                            tryb_w = "Enhanced";
                            tryb = 2;
                        }
                        else if (tryb == 2) {
                            tryb = 1;
                            tryb_w = "Clasic";
                        }
                    }
                    if (otaczanie.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game == false && settings == false) {
                        if (otaczanie_b == true) {
                            otaczanie_d = "False";
                            otaczanie_b = false;
                        }
                        else if (otaczanie_b == false) {
                            otaczanie_d = "True";
                            otaczanie_b = true;
                        }
                    }
                    if (unmark.Mouse_over_button(sf::Vector2f(sf::Mouse::getPosition(window))) && Game == false && settings == false) {
                        Player_board.Unmark_fields(coords);
                        coords.clear();
                        count = 0;
                    }
                    //AI
                    if (players_turn == false) {
                         enemy.Shot(Player_board,player_ship_list,tryb);
                         player_ship_list.Check_ships(Player_board);
                         players_turn = true;
                    }
                    
                }
            }
            //Ustawianie statków
            if (event.type == sf::Event::MouseButtonPressed && (event.mouseButton.button == sf::Mouse::Right) && Game == false && settings == false) {
                isMarking = true;
                lastMousePos = sf::Mouse::getPosition(window);
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

                sf::Vector2u size = window.getSize();
                float w = size.x / 22;
                sf::Vector2f fieldSize(w, w);
                sf::Vector2f padding(1, 0);
                markedRow = (worldPos.y - 200) / fieldSize.y;
                markedCol = worldPos.x / fieldSize.x;
            }
            if ((event.type == sf::Event::MouseButtonReleased) && (event.mouseButton.button == sf::Mouse::Right)&& Game==false && settings == false) {
                isMarking = false;
                if (count != ship_set_type) {
                    Player_board.Unmark_fields(coords);
                    coords.clear();
                    count = 0;
                    
                }
            }
            if (event.type == sf::Event::MouseMoved && isMarking && Game == false && settings == false) {
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
                sf::Vector2u size = window.getSize();
                float w = size.x / 22;
                sf::Vector2f fieldSize(w, w);
                sf::Vector2f padding(1, 0);
                markedRow = (worldPos.y - 200) / fieldSize.y;
                markedCol = worldPos.x / fieldSize.x;
                if (markedRow != lastmarkRow || markedCol != lastMarkCol) {
                    if (markedCol > -1 && markedCol< 10 && markedRow > -1 && markedRow < 10 && count<ship_set_type && Player_board.isMarked(markedRow, markedCol)==false) {
                        Player_board.Mark_field(markedRow, markedCol);
                        coords.push_back(make_pair(markedRow, markedCol));
                        cout << "kolumna:" << markedCol << "wiersz:" << markedRow;
                        count++;
                    }
                    lastMarkCol = markedCol;
                    lastmarkRow = markedRow;
                }
            }
        }
        
        window.clear();
        Player_board.Display(window, Enemy_board,Game,otaczanie_b);
        text_fields.draw(window, "Fields state:", font, sf::Color::Red, sf::Color::Black, 0, 15);
        blue_field.draw(window, "Unknown", font, sf::Color::Yellow, sf::Color::Blue, 4, 15,1);
        black_field.draw(window, "Free", font, sf::Color::Yellow, sf::Color::Black, 7, 15);
        red_field.draw(window, "Hit Ship", font, sf::Color::Yellow, sf::Color::Red, 9, 15,1);
        orange_field.draw(window, "Hit Free", font, sf::Color::Yellow, sf::Color::Color(219, 126, 12), 13, 15,1);
        gray_field.draw(window, "Ship", font, sf::Color::Yellow, sf::Color::Color(146, 171, 189), 17, 15);
        green_field.draw(window, "Mark", font, sf::Color::Yellow, sf::Color::Green, 20, 15);
        //ustawianie przed grą
        if (Game == false && settings == false) {
            start.draw(window, "Start", font, sf::Color::Red, sf::Color::Green, 1, 12);
            unmark.draw(window, "Unmark", font, sf::Color::Red, sf::Color::Green, 7, 12, 1);
            display.draw(window, to_string(fields-player_ship_list.Num_of_fields()) + " left pf", font, sf::Color::Red, sf::Color::Green, 11, -4,1);
            display1.draw(window, to_string(fields - enemy_ship_list.Num_of_fields()) + " left ef", font, sf::Color::Red, sf::Color::Green, 15, -4,1);
            liczba_statkow.draw(window,"Num_ships", font, sf::Color::Red, sf::Color::Green, 19, -4, 1);
            text_field2.draw(window, "Press 1-5 to select:", font, sf::Color::Red, sf::Color::Black, 0, -4, 3);
            ship_type.draw(window, ship_type_display, font, sf::Color::Red, sf::Color::Green, 5, -4, 3);
            generate_enemy.draw(window, "Generate Enemy", font, sf::Color::Red, sf::Color::Green, 11, 12, 3);
            restart.draw(window, "Reset Boards", font, sf::Color::Red, sf::Color::Green, 10, -2, 2);
            zmien_tryb.draw(window, "Change mode", font, sf::Color::Red, sf::Color::Green, 1, -2, 2);
            wyswietl_tryb.draw(window, tryb_w, font, sf::Color::Red, sf::Color::Black, 5, -2, 2);
            otaczanie.draw(window, "Surrounding", font, sf::Color::Red, sf::Color::Green, 16, -2, 2);
            wyswietl_tryb.draw(window,otaczanie_d , font, sf::Color::Red, sf::Color::Black, 20, -2, 2);
            generate_player.draw(window, "Generate Player", font, sf::Color::Red, sf::Color::Green, 17, 12,3);
            set.draw(window, "Set", font, sf::Color::Red, sf::Color::Green, 4, 12);
        }
        //gra
        else if (settings == false) {
            display.draw(window,"enemy_ships: "+ to_string(enemy_ship_list.Num_of_ships()), font, sf::Color::Red, sf::Color::Green, 12, -4,3);
            ship_type.draw(window, "player_ships: "+to_string(player_ship_list.Num_of_ships()), font, sf::Color::Red, sf::Color::Green, 5, -4, 3);
            new_game.draw(window, "New game", font, sf::Color::Red, sf::Color::Green, 15, 12, 1);
            end.draw(window, "End", font, sf::Color::Red, sf::Color::Green, 19, 12);
           // set.draw(window, "Shot", font, sf::Color::Red, sf::Color::Green, 4, 12);
            if (player_ship_list.Num_of_ships() == 0 && enemy_ship_list.Num_of_ships() > 0) {
                win.draw(window, "Enemy Win", font, sf::Color::Red, sf::Color::Green, 9, -1, 2);
            }
            if (player_ship_list.Num_of_ships() > 0 && enemy_ship_list.Num_of_ships() == 0) {
                win.draw(window, "Player Win", font, sf::Color::Red, sf::Color::Green, 9, -1, 2);
            }
        }
        else if (settings == true) {
            accept.draw(window, "Accept", font, sf::Color::Red, sf::Color::Green, 16, -4, 1);
            text_fields.draw(window, "Num_of_ships:", font, sf::Color::Red, sf::Color::Black, 0, 13);
            jb.draw(window, to_string(jedno), font, sf::Color::Yellow, sf::Color::Green, 4, 13);
            db.draw(window, to_string(dwu), font, sf::Color::Yellow, sf::Color::Green, 7, 13);
            tb.draw(window, to_string(trzy), font, sf::Color::Yellow, sf::Color::Green, 10, 13);
            cb.draw(window, to_string(cztero), font, sf::Color::Yellow, sf::Color::Green, 13, 13);
            pb.draw(window, to_string(piecio), font, sf::Color::Yellow, sf::Color::Green, 16, 13);
            j.draw(window, "1", font, sf::Color::Yellow, sf::Color::Black, 4, 11);
            d.draw(window, "2", font, sf::Color::Yellow, sf::Color::Black, 7, 11);
            t.draw(window, "3", font, sf::Color::Yellow, sf::Color::Black, 10, 11);
            c.draw(window, "4", font, sf::Color::Yellow, sf::Color::Black, 13, 11);
            p.draw(window, "5", font, sf::Color::Yellow, sf::Color::Black, 16, 11);
            text_field2.draw(window, "Fields for ships:", font, sf::Color::Red, sf::Color::Black, 0, -4, 3);
            sfields.draw(window, to_string(20-sum_fields), font, sf::Color::Red, sf::Color::Green, 5, -4);
        }
        window.display();
    }
    return 0;
}