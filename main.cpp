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
    std::cout<< "число порталов в начале " << zeroo.get_number_of_portals() << " игрок на планете = "<<  player.get_current_planet() << " планета N " << zeroo.get_number_of_planet()  <<std::endl << std::endl;

    std::vector<planet> planet_game;
    planet_game.push_back(zeroo);
    int current_id_planet = is_planet_unique(player.get_current_planet(), planet_game);



    int what_tp = 0;

    while(what_tp != -1)
    {

        std::cout <<"Игрок на планете на планете "<< player.get_current_planet() << " На ней порталов "<< planet_game[is_planet_unique(player.get_current_planet(), planet_game)].get_number_of_portals()   <<" а по поиску id мб должна быть"<< is_planet_unique(player.get_current_planet(), planet_game) <<std::endl;

        std::cout<<"Выберете портал 1 до " << planet_game[is_planet_unique(player.get_current_planet(), planet_game)].get_number_of_portals() << ": ";
        std::cin >> what_tp; // проверку на ввод
        while(what_tp > planet_game[is_planet_unique(player.get_current_planet(), planet_game)].get_number_of_portals()) // минимальная проверка на ввод
        {
            std::cout << "Выберете портал из диапазона!" << std::endl;
            std::cin >> what_tp;
        }




        if(planet_game[is_planet_unique(player.get_current_planet(), planet_game)].is_tp_on_planet(what_tp) == -1)
        {
            std::cout<< "нет такого телепорта"<< std::endl;
            int fl = step_to_new_portal(what_tp, player, planet_game);  // нужна проверка на тп
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
            planet_game[is_planet_unique(player.get_current_planet(), planet_game)].print_whereTO_portals();
        }



    }


//    while(what_tp != -1)
//    {
//    std::cout <<"<<<<<<<<<<<<<<<<<<<<<<<<<<" <<std::endl;
//    std::cout <<"Сейчас на планете "<< player.get_current_planet() << " На ней порталов "<< planet_game[player.get_current_id()].get_number_of_portals() <<std::endl;
//    std::cout <<"Выберете номер портала для перехода:" <<std::endl;
//    std::cout <<"Вы помните что порталы ведут:" <<std::endl;
//    std::cin >> what_tp;

//    step_to_portal(what_tp, player, planet_game);  // нужна проверка на тп

//    planet_game[player.get_current_id()].print_whereTO_portals();

//    std::cout <<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n" <<std::endl;
//    }



//    std::cin >>


//    std::cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<std::endl;





//    planet_game[player.get_current_planet()]= zeroo;

//    std::cout <<   "Номер планеты "  << planet_game[player.get_current_planet()].get_number_of_planet() << " Кол-во порталов " << planet_game[player.get_current_planet()].get_number_of_portals() << std::endl;

//    step(player, planet_game );  // степ был раньше



//    planet test;

//    std::cout << "\nпортал = " <<test.get_whereTO_portal(1)<< std::endl;



    return 0;
}
