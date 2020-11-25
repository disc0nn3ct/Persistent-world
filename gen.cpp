#include  "gen.hpp"

uint random(uint min, uint max) {
    std::mt19937 prng(std::random_device{}());
    return std::uniform_int_distribution<>(min, max)(prng);
}



adventurer::adventurer()
{
    N_planet=1; // начальная планета на 1
}

void adventurer::set_current_planet(unsigned int N)
{
    this->N_planet = N;
}

unsigned int adventurer::get_current_planet()
{
    return N_planet;
}

void adventurer::set_current_id(unsigned int N)
{
     this->current_id_of_planet=N;
}

unsigned int adventurer::get_current_id()
{
    return current_id_of_planet;
}



void planet::set_number_of_planet(unsigned int N_planet)
{
    this->N_planet = N_planet;
}

unsigned int planet::get_number_of_portals()
{
    return N_of_portals;
}

planet::planet() : N_of_portals(random(1, 10))
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

void planet::add_to_vector_pair_whereTo(std::pair<uint, uint> const& par)
{
    std::cout << "СООООООООООООООЗДаю пару " << par.first << " " << par.second <<std::endl;
    this->whereTO.push_back(par);
}

uint planet::how_many_portals_are_fee()
{
    return N_of_portals - whereTO.size();
}

uint planet::choose_free_portail_for_transport()
{
    bool i = 1;
    uint what_port;
    while(i != 0)
    {
        i = 0;
        what_port = random(1, N_of_portals);
        for(int j=0; j < whereTO.size(); j++)
        {
            if(whereTO[j].first == what_port)
            {
                i = 1;
                break;
            }
        }
    }
    if(i != 0)
    {// то найден тот что надо
        return what_port;
    }
    else
        return 0;
}

uint planet::is_tp_on_planet(uint num , std::vector<std::pair<uint, uint>>const &whereTO)   // если есть то вернет куда, если нет 0
{
    uint to=0;
    for(uint i=0; i < whereTO.size(); i++)
    {
        if(whereTO[i].first == num)
            return i;
    }
    return to;
}

uint is_planet_unique(uint num, std::vector<planet> &planet_game)  // вернет id планеты, если не существует 0
{
    uint i = 0;
    for(uint r=0; r < planet_game.size(); r++)
    {
        if(planet_game[r].get_number_of_planet() == num)
            return r;
    }
   return 0;
}

void planet::print_whereTO_portals()
{
    if(this->whereTO.size() == 0)
        std::cout << "Вам ничего не известно =С " << whereTO.size()<< std::endl;
    else
    {
        for(int i =0; i < whereTO.size(); i++ )
        {
            std::cout << "Портал i ->"<< i << std::endl;
        }
    std::cout << std::endl;
    }
}



void step_to_portal(uint num_of_portal, adventurer &player, std::vector<planet> &planet_game )
{
    int tp_cur=planet::is_tp_on_planet(num_of_portal, planet_game[player.get_current_id()].get_vector_whereTo());
    if(tp_cur == 0)
    {
        std::cout <<"Изучение портала" <<std::endl;
        uint to_planet = random(1, 10);    // тут задается макс число планет.
        uint id_planet = is_planet_unique(to_planet, planet_game);   // нужна подмена планеты если на той что выбрали не осталось парталов ... мб сделать проверку на освобожденность планет
        if(id_planet == 0 && to_planet != 1)
        {
            std::cout <<"Обнаружена НОВАЯ планета! под номером " << to_planet <<std::endl;

            planet new_one;
            new_one.add_to_vector_pair_whereTo(std::make_pair(random(1, new_one.get_number_of_portals()), player.get_current_planet()));
            new_one.set_number_of_planet(to_planet);
            planet_game.push_back(new_one);

            player.set_current_planet(to_planet);  // объеденить#1
            uint current_id_planet = is_planet_unique(player.get_current_planet(), planet_game); // объеденить#1
            player.set_current_id(current_id_planet);// объеденить#1
        }
        else
        {
            std::cout <<"Обнаружена СТАРАЯ планета!" <<std::endl;
            // нужна проверка на кол-во тп
            if( planet_game[id_planet].how_many_portals_are_fee() == 0) // тупая проверка
            {
              std::cout << "Места нет =ССССССССССССССССССССССССССС" << std::endl;
            }
             planet_game[id_planet].choose_free_portail_for_transport();

             player.set_current_planet(to_planet);  // объеденить  тож самое что чуть выше #1
             player.set_current_id(is_planet_unique(player.get_current_planet(), planet_game));// объеденить#1
        }



    }





}


































void step(adventurer &player, std::vector<planet> &planet_game ) // добавить правильный поиск портала (проверка на свободность) + поиск текущей планеты в векторе оформить +  проверка планеты с учетом поратлов
{
std::cout <<"<<<<<<<<<<<<<<<<<<<<<<<<<<" <<std::endl;

uint current_id_planet = is_planet_unique(player.get_current_planet(), planet_game);

std::cout <<"id планеты в векторе "<< current_id_planet  <<std::endl;

std::cout<< "Колво порталов на планете " << planet_game[current_id_planet].get_number_of_planet() <<" число: " <<planet_game[current_id_planet].get_number_of_portals() << std::endl;
//    std::cout << "LOL" ;

//        unsigned int what_teleport = planet.random(0, planet_game[player.get_current_planet()].get_number_of_portals());



//std::cout << planet_game[current_id_planet].get_vector_whereTo().size();

if(planet_game[current_id_planet].get_vector_whereTo().size() > 0 )   // не верна логика
{
    // проверь

}
else
{
    uint what_teleport = random(1, planet_game[current_id_planet].get_number_of_portals());
    std::cout << "what_teleport " << what_teleport;
    uint to_planet = random(1, 10);    // тут задается макс число планет.

    std::cout<< "is_tp_on_planet " << planet::is_tp_on_planet(what_teleport, planet_game[current_id_planet].get_vector_whereTo())  << std::endl;

    if(planet::is_tp_on_planet(what_teleport, planet_game[current_id_planet].get_vector_whereTo()) == 0)
    {
    std::cout << "нет телепорта" << std::endl;
    planet_game[current_id_planet].add_to_vector_pair_whereTo(std::make_pair(what_teleport, to_planet));
    }
    else
        to_planet = planet::is_tp_on_planet(what_teleport, planet_game[current_id_planet].get_vector_whereTo());
    // добавить элемент без проверки

    std::cout << " на планету " << planet_game[current_id_planet].get_vector_whereTo()[current_id_planet].second << " Свободно "<< planet_game[current_id_planet].how_many_portals_are_fee() <<std::endl;
    std::vector<planet>::iterator it;        // Iterator
    bool flag = 0;
    for(it = planet_game.begin(); it < planet_game.end(); it++)
    {
        if(it->get_number_of_planet() == to_planet)
        {
            flag = 1;
            planet new_one;
            new_one.add_to_vector_pair_whereTo(std::make_pair(random(1, new_one.get_number_of_portals()) , current_id_planet));
            planet_game.push_back(new_one);

            player.set_current_planet(to_planet);

            break;
            // переместись
        }
    }

    if(flag == 0)
    {
        // создай и переместись
    }

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
