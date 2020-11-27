//#pragma once // ?
#ifndef _gen_HPP
#define _gen_HPP
#include <string>
#include <iostream>

#include <random>
#include <vector>
#include <algorithm>
#include <cstring> // для memset

int random(int min, int max);


class adventurer
{
public:
    void set_current_planet(int N);
    int get_current_planet();

//    void set_current_id(int N);
//    int get_current_id();
    adventurer();
private:

    int N_planet;
    int current_id_of_planet;
//    string Name;
};


class planet
{
public:
    planet();

    int get_number_of_portals();
    void set_number_of_planet(int N_planet);
    int get_number_of_planet();
    std::vector<std::pair<int, int>> const &get_vector_whereTo() const;
    void add_to_vector_pair_whereTo(std::pair<int, int> const &par);
    int how_many_portals_are_fee();
    int choose_free_portail_for_transport() ;
    int is_tp_on_planet(int num);   // если есть то вернет куда, если нет 0
    void print_whereTO_portals();

private:
    int N_planet; // номер планеты
    std::string planet_color;  // цвет планеты
    int N_of_portals; // кол-во порталов
    std::vector<std::pair<int, int>> whereTO;

};


int is_planet_unique(int num, std::vector<planet> &planet_game );  // вернет id планеты, если не существует 0


//void step(adventurer &player, std::vector<planet> &planet_game );

//void step_to_portal(int num_of_portal, adventurer &player, std::vector<planet> &planet_game );

int step_to_new_portal(int num_of_portal, adventurer &player, std::vector<planet> &planet_game );
void step_to_portal(adventurer &player, int planet_N);

int spirit_of_verification(int max_num_planet, std::vector<planet> &planet_game);









#endif
