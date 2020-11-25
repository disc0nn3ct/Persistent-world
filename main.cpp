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
    std::cout<< "число порталов в начале " <<zeroo.get_number_of_portals() << " игрок на планете = "<<  player.get_current_planet() << " планета N " << zeroo.get_number_of_planet()  <<std::endl;

    std::vector<planet> planet_game;
    planet_game.push_back(zeroo);
    uint current_id_planet = is_planet_unique(player.get_current_planet(), planet_game);
    player.set_current_id(current_id_planet);





    int what_tp = 0;

    while(what_tp != -1)
    {
    std::cout <<"<<<<<<<<<<<<<<<<<<<<<<<<<<" <<std::endl;
    std::cout <<"Сейчас на планете "<< player.get_current_planet() << " На ней порталов "<< planet_game[current_id_planet].get_number_of_portals() <<std::endl;

    std::cout <<"Выберете номер портала для перехода:" <<std::endl;
    std::cout <<"Вы помните что порталы ведут:" <<std::endl;
    planet_game[current_id_planet].print_whereTO_portals();
    std::cin >> what_tp;

    step_to_portal(what_tp, player, planet_game);  // нужна проверка на тп

    std::cout <<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>" <<std::endl;
    }



//    std::cin >>


//    std::cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<std::endl;





//    planet_game[player.get_current_planet()]= zeroo;

//    std::cout <<   "Номер планеты "  << planet_game[player.get_current_planet()].get_number_of_planet() << " Кол-во порталов " << planet_game[player.get_current_planet()].get_number_of_portals() << std::endl;

//    step(player, planet_game );  // степ был раньше



//    planet test;

//    std::cout << "\nпортал = " <<test.get_whereTO_portal(1)<< std::endl;



    return 0;
}
