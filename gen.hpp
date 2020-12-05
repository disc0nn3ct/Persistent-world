#ifndef _gen_HPP
#define _gen_HPP
#include <string>
#include <iostream>

#include <random>
#include <vector>
#include <algorithm>
#include <cstring> // для memset


#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/serialization/complex.hpp>
#include <boost/serialization/utility.hpp> // для pair
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>

int random(int min, int max);

class adventurer
{
public:
    adventurer() : N_planet(1) { };
    adventurer(int N) : N_planet(N) { };
    void set_current_planet(int N) {
        N_planet = N;
    };
    int get_current_planet() const{
        return N_planet;
    };

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & N_planet;
    }
    int N_planet;
};

class planet
{
public:
    planet() : N_of_portals(random(1, 65000)), color("red")  // тут задается макс число порталов
    { };

    int get_number_of_portals() const {
        return N_of_portals;
    };

    void set_number_of_planet(int N_plan) {
        N_planet = N_plan;
    };

    int get_number_of_planet() const {
        return N_planet;
    };

    std::vector<std::pair<int, int>> const &get_vector_whereTo() const {return whereTO; };
    void add_to_vector_pair_whereTo(std::pair<int, int> const &par){
        this->whereTO.push_back(par);
    };
    int how_many_portals_are_free() const {
        return N_of_portals - whereTO.size();
    };
    int choose_free_portail_for_transport() ;
    int is_tp_on_planet(int num) const;   // если есть то вернет куда, если нет 0
    void print_whereTO_portals();

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & N_planet;
        ar & planet_color;
        ar & N_of_portals;
        ar & whereTO;
        ar & color;
    }
    int N_planet; // номер планеты
    std::string planet_color;  // цвет планеты
    int N_of_portals; // кол-во порталов
    std::vector<std::pair<int, int>> whereTO;
    std::string color;
};


int is_planet_unique(int num, const std::vector<planet> &planet_game );  // вернет id планеты, если не существует 0
int step_to_new_portal(int num_of_portal, adventurer &player, std::vector<planet> &planet_game );
void step_to_portal(adventurer &player, int planet_N);
bool spirit_of_verification(int max_num_planet, const std::vector<planet> &planet_game);

int save_game(const adventurer &player, const std::vector<planet> &planet_game);
int load_game(adventurer &player, std::vector<planet> &planet_game);

int user_play_or_bot();

int play(int k, adventurer &player, std::vector<planet> &planet_game, int f=0);


#endif
