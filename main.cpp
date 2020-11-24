#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "gen.hpp"

#include <vector>


int main()
{
    std::cout<< "Let's play!" << std::endl;

    planet zeroo;
    adventurer player;
    zeroo.set_number_of_planet(player.get_current_planet());

    //    zeroo.se
    std::cout<< "число порталов в начале " <<zeroo.get_number_of_portals() << " на какой планете = "<<  player.get_current_planet() << " планета N? " << zeroo.get_number_of_planet()  <<std::endl;



    //рабочий код

    //    zeroo.set_whereTO_portal(0, 155);
    //    std::cout<< "лол "<< zeroo.get_whereTO_portal(0) << std::endl;

//    zeroo.whereTO[15] = 1224;
//    std::cout<<zeroo.whereTO[15] << std::endl;
    //




    std::vector<planet> planet_game;
    planet_game.push_back(zeroo);
//    planet_game[player.get_current_planet()]= zeroo;

    std::cout <<   "Номер планеты "  << planet_game[player.get_current_planet()].get_number_of_planet() << " Кол-во порталов " << planet_game[player.get_current_planet()].get_number_of_portals() << std::endl;

    step(player, planet_game );


    planet test;

//    std::cout << "\nпортал = " <<test.get_whereTO_portal(1)<< std::endl;



    return 0;
}
