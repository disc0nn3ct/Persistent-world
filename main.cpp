#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "gen.hpp"

#include <vector>


int main()
{
    std::cout<< "Let's play!" << std::endl;
    {
       std::vector<planet> planet_game;
       adventurer player;

       int k=-2;
       while(k >1 || k < -1 )
       {
           std::cout << "Нажмите 0 новой игры; 1 загрузки; -1 выход ";
           std::cin >> k;
           std::cout << std::endl;
       }
       if(k == 0)
       {
           // new game
            play(k, player, planet_game);

       }
       else
       {
            if(k == 1)
            {
            load_game(player, planet_game);

            std::cout<< "ux" << player.get_current_planet() <<std::endl;
            std::cout<< "tp on planet: " << std::endl;
            planet_game[is_planet_unique(player.get_current_planet(), planet_game)].print_whereTO_portals();
            play(k, player, planet_game);

            // продолжить игру

            }
            else
                return 0; // выход


       }




    }


//    play(0);









    return 0;
}
