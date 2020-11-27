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
//    std::cout<< "число порталов в начале " << zeroo.get_number_of_portals() << " игрок на планете = "<<  player.get_current_planet() << " планета N " << zeroo.get_number_of_planet()  <<std::endl << std::endl;

    std::vector<planet> planet_game;
    planet_game.push_back(zeroo);
    int current_id_planet = is_planet_unique(player.get_current_planet(), planet_game);

    int what_tp = 0;

    while(what_tp != -1)
    {
//        std::cout <<"Игрок на планете на планете "<< player.get_current_planet() << ". На ней порталов "<< planet_game[is_planet_unique(player.get_current_planet(), planet_game)].get_number_of_portals()   <<". id планеты "<< is_planet_unique(player.get_current_planet(), planet_game) <<std::endl;
        planet_game[is_planet_unique(player.get_current_planet(), planet_game)].print_whereTO_portals();


        std::cout<<"Выберите портал 1 до " << planet_game[is_planet_unique(player.get_current_planet(), planet_game)].get_number_of_portals() << ": ";

        std::cin >> what_tp; // проверку на ввод
        while(what_tp > planet_game[is_planet_unique(player.get_current_planet(), planet_game)].get_number_of_portals()) // минимальная проверка на ввод
        {
            std::cout << "Выберите портал из диапазона! 1 до " << planet_game[is_planet_unique(player.get_current_planet(), planet_game)].get_number_of_portals() << ": ";
            std::cin >> what_tp;
            std::cout << std::endl;
        }

        if(planet_game[is_planet_unique(player.get_current_planet(), planet_game)].is_tp_on_planet(what_tp) == -1)
        {
            std::cout<< "Нет такого телепорта"<< std::endl;
            int fl = step_to_new_portal(what_tp, player, planet_game);  // нужна проверка на тп
            std::cout<< fl << std::endl;
            if(fl == -1)
            {
                std::cout<< "Больше я пожалуй ходить не буду" << std::endl;
                return -1;
            }
        }
        else
        {
            std::cout<< "есть такой портал, проверка переходит на планету c"<<  planet_game[is_planet_unique(player.get_current_planet(), planet_game)].is_tp_on_planet(what_tp) << " id планеты "<< is_planet_unique(player.get_current_planet(), planet_game) << " на планету " << planet_game[is_planet_unique(player.get_current_planet(), planet_game)].is_tp_on_planet(what_tp) << " id этой планеты " << is_planet_unique( planet_game[is_planet_unique(player.get_current_planet(), planet_game)].is_tp_on_planet(what_tp) ,planet_game )  << std::endl;
            step_to_portal(player, planet_game[is_planet_unique(player.get_current_planet(), planet_game)].is_tp_on_planet(what_tp) );
//            planet_game[is_planet_unique(player.get_current_planet(), planet_game)].print_whereTO_portals();
        }

    }
    return 0;
}
