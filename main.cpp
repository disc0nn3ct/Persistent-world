#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "gen.hpp"

#include <vector>


int main()
{
    std::cout<< "Let's play!" << std::endl;
//    {
//       int k=-1;
//       while(k != 0 || k != 1)
//       {
//           std::cout << "Нажмите 0 своей игры; 1 для игры ботом" << std::endl;
//           std::cin >> k;
//       }
//       if(k == 0)
//       {
//            if(play() == 0)
//                std::cout << "Успешно"<< std::endl;
//       }
//       else
//       {
//           k=-1;
//           while(k < 0)
//           {
//               std::cout << "Введите кол-во шагов для бота" << std::endl;
//               std::cin >> k;
//           }
//            if(play(k) == 0)
//                std::cout << "Успешно"<< std::endl;
//           // TODO LOAD
//       }


//    }


    play(0);




    std::vector<planet> planet_game;
    adventurer player;
    load_game(player, planet_game);

    std::cout<< "ux" << player.get_current_planet() <<std::endl;






    return 0;
}
