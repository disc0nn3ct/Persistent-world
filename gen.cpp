#include  "gen.hpp"

uint planet::random(uint min, uint max) {
    std::mt19937 prng(std::random_device{}());
    return std::uniform_int_distribution<>(min, max)(prng);
}

void adventurer::set_current_planet(unsigned int N)
{
    this->N_planet = N;
}

adventurer::adventurer()
{
    N_planet=0;
}

unsigned int adventurer::get_current_planet()
{
    return N_planet;
}

void planet::set_number_of_planet(unsigned int N_planet)
{
    this->N_planet = N_planet;
}

unsigned int planet::get_number_of_portals()
{
    return N_of_portals;
}
planet::planet() : N_of_portals(random(0, 65555))
{ }

//    void planet::set_whereTO_portal(unsigned int portal_number, unsigned int where_to)
//    {
//        whereTO[portal_number] = where_to;
//    }

//    unsigned int planet::get_whereTO_portal(unsigned int i)
//    {
//        return whereTO[i];
//    }

unsigned int planet::get_number_of_planet()
{
    return N_planet;
}

std::vector<std::pair<uint, uint>> const &planet::get_vector_whereTo() const  // запрет на попытки изменить объект через указатель
{return whereTO; }



void step(adventurer &player, std::vector<planet> &planet_game )
{
std::cout <<"<<<<<<<<<<<<<<<<<<<<<<<<<<" <<std::endl;

std::cout<< "Колво порталов на планете " << planet_game[player.get_current_planet()].get_number_of_planet() <<" число: " <<planet_game[player.get_current_planet()].get_number_of_portals() << std::endl;
//    std::cout << "LOL" ;

//        unsigned int what_teleport = planet.random(0, planet_game[player.get_current_planet()].get_number_of_portals());

std::vector<std::pair<uint, uint>>::iterator it;        // Iterator


//std::cout << planet_game[player.get_current_planet()].get_vector_whereTo().size();

if(planet_game[player.get_current_planet()].get_vector_whereTo().size() > 0 )
{
    // проверь
}
else
{
    // добавить элемент без проверки
}


//for(it = planet_game[player.get_current_planet()].get_vector_whereTo().begin(), it < planet_game[player.get_current_planet()].get_vector_whereTo().end(), it++ )
//{

//;
//}


//       for(vector<pair<uint,uint>>::iterator iter=planet_game[player.get_current_planet()].whereTO.begin();iter!=planet_game[player.get_current_planet()].whereTO.end();iter++){
//               cout<<*iter<<" ";
//           if(*iter.first == what_teleport )
//           {
//               std::cout << "LOl ";
//               // перейди
//           }
//           else {
//               // создай и добавь
//           }

//           }


//       planet_game[player.get_current_planet()].whereTO.reserve(planet_game[player.get_current_planet()].get_number_of_portals());

//       std::cout <<"выбрал портал "<< what_teleport <<std::endl;

//       std::cout<<planet_game[player.get_current_planet()] ;

//       if(planet_game[player.get_current_planet()].get_whereTO_portal(what_teleport) == 0 && what_teleport != 0 )
//       {
//               std::cout << "LOL" ;
//       }
//       else
//       {
//       }


//        std::vector<unsigned int> whereTO;
//        if(planet_game[player.get_current_planet()].get_whereTO_portal(what_teleport) == 0 && what_teleport != 0 )
//        {

//        }
//        else
//        {

//        }



//        std::vector<unsigned int>::iterator it;        // Iterator
//        planet_game[player.get_current_planet()].whereTO.reserve(planet_game[player.get_current_planet()].get_number_of_portals());   // требуется вынос в класс
//        std::cout <<"I'm!!!!  " <<sizeof(planet_game[player.get_current_planet()].whereTO) << std::endl;

//         it = std::find(planet_game[player.get_current_planet()].whereTO.begin(), planet_game[player.get_current_planet()].whereTO.end(), what_teleport);
//         if(it == planet_game[player.get_current_planet()].whereTO.end())
//         {
//             unsigned int mb_new_planet = rand();

//             planet_game[player.get_current_planet()].whereTO[what_teleport] = mb_new_planet;
//             std::cout << "YEEEEEEESS" << std::endl;
//         }
//         else
//         {
//             // прыжок в старый тп
//         }

//         std::cout<< "Let's play!" << std::endl;

//                std::vector<unsigned int> whereTO;
//                std::vector<unsigned int>::iterator it;        // Iterator
//                it = std::find(whereTO.begin(), whereTO.end(), what_teleport);
//                if(it == whereTO.end())
//                {
//                    std::cout << "YEEEEEEESS" << std::endl;
//                }

   std::cout <<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>" <<std::endl;

}
