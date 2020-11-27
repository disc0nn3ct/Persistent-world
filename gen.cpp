#include  "gen.hpp"

int random(int min, int max) {
    std::mt19937 prng(std::random_device{}());
    return std::uniform_int_distribution<>(min, max)(prng);
}

adventurer::adventurer()
{
    N_planet=1; // начальная планета на 1
}

void adventurer::set_current_planet(int N)
{
    this->N_planet = N;
}

int adventurer::get_current_planet()
{
    return N_planet;
}


void planet::set_number_of_planet(int N_planet)
{
    this->N_planet = N_planet;
}

int planet::get_number_of_portals()
{
    return N_of_portals;
}

planet::planet() : N_of_portals(random(1, 3))
{ }

//    void planet::set_whereTO_portal(unsigned int portal_number, unsigned int where_to)
//    {
//        whereTO[portal_number] = where_to;
//    }

//    unsigned int planet::get_whereTO_portal(unsigned int i)
//    {
//        return whereTO[i];
//    }

int planet::get_number_of_planet()
{
    return N_planet;
}

std::vector<std::pair<int, int>> const &planet::get_vector_whereTo() const  // запрет на попытки изменить объект через указатель
{return whereTO; }

void planet::add_to_vector_pair_whereTo(std::pair<int, int> const& par)
{
    std::cout << "СООООООООООООООЗДаю пару " << par.first << " " << par.second <<std::endl;
    this->whereTO.push_back(par);
}

int planet::how_many_portals_are_fee()
{
    std::cout << "==========================================N_of_portals " << N_of_portals << " whereTO.size " << whereTO.size()   << std::endl;
    return N_of_portals - whereTO.size();
}

int planet::choose_free_portail_for_transport()
{
    if (N_of_portals - whereTO.size() == 0)
    {
        return 0;
    }
    else
    {
    bool i = 1;
    int what_port = random(1, N_of_portals);
    while(i != 0)
    {
        i = 0;
        for(int j=0; j < whereTO.size(); j++)
        {
            if(whereTO[j].first == what_port)
            {
                what_port = random(1, N_of_portals);
                i = 1;
                break;
            }
        }
    }
    if(i == 0)
    {// то найден тот что надо
        return what_port;
    }
    else
        return 0;
    }
}

int planet::is_tp_on_planet(int num)   // если есть вернет куда, нет -1
{
    for(int i=0; i < whereTO.size(); i++)
    {
        if(whereTO[i].first == num)
        {
            return whereTO[i].second;
            break;
        }
    }
    return -1;
}

int is_planet_unique(int num, std::vector<planet> &planet_game)  // вернет id планеты, если не существует -1
{
    //int i = 0;
    for(int r=0; r < planet_game.size(); r++)
    {
        if(planet_game[r].get_number_of_planet() == num)
            return r;
    }
   return -1;
}

void planet::print_whereTO_portals()
{
    std::cout << "                                на планете " << N_planet << " кол-во занято " << whereTO.size() << std::endl;
    if( whereTO.size() == 0 )
        std::cout << "Вам ничего не известно =С " << std::endl;
    else
    {
        for(int i =0; i < whereTO.size(); i++ )
//        for(int i =1; i <= N_of_portals; i++ )
        {

//            planet::is_tp_on_planet(i,  whereTO);
            std::cout << "Портал i="<< i << " whereTO[i].first "<< whereTO[i].first << " whereTO[i].second "  << whereTO[i].second << std::endl;
//            std::cout << "Портал i="<< i << " whereTO[i].first "<< whereTO[planet::is_tp_on_planet(i,  whereTO)].first << " whereTO[i].second "  << whereTO[planet::is_tp_on_planet(i,  whereTO)].second << std::endl;

        }
    std::cout << std::endl;
    }
}


int spirit_of_verification(int max_num_planet, std::vector<planet> &planet_game)
{
    int counter = 0;
    for(int i=0; i < max_num_planet; i++)
    {
        if( is_planet_unique(planet_game[i].get_number_of_planet(), planet_game) >=0 )
        {
            if(planet_game[i].how_many_portals_are_fee() == 0)
                counter++;
        }
    }

    if(counter < max_num_planet)
    {
        return 1; // значит еще место есть
    }
    else {
        return 0; // места нет
    }
}



int step_to_new_portal(int num_of_portal, adventurer &player, std::vector<planet> &planet_game)
{
    int max_N_of_planet=3;
    int to_planet =  random(1, max_N_of_planet);
    int checker = 0;
////////////////////////////////////////////////////////////////////////////////
    std::cout<< "------------------------------- уникальная? " << is_planet_unique(to_planet, planet_game) << "------------ свободно " << planet_game[is_planet_unique(to_planet, planet_game)].how_many_portals_are_fee() << "тут "<< player.get_current_planet() << " в планету "<< to_planet << std::endl;

//    while(planet_game[is_planet_unique(to_planet, planet_game)].how_many_portals_are_fee() == 0 || player.get_current_planet() == to_planet)
while(player.get_current_planet() == to_planet || (planet_game[is_planet_unique(to_planet, planet_game)].how_many_portals_are_fee() == 0) &&  is_planet_unique(to_planet, planet_game) != -1)
    {
        std::cout << " поиск  было на " << to_planet;
        to_planet =  random(1, max_N_of_planet);
        std::cout << " теперь на " << to_planet << std::endl;

    }
    if( max_N_of_planet <= planet_game.size())
    {
        std::cout << "max_N_of_planet "<<max_N_of_planet << " planet_game.size()" << planet_game.size() << std::endl;

        if(spirit_of_verification(max_N_of_planet, planet_game)) // мб не нужен - тк как не оч хорош
        {
            std::cout << "Все заполнено... Не могу идти дальше..." << std::endl;
            return -1;
        }
    }


////////////////////////////////////////////////////////////////////////////////
    int id_planet = is_planet_unique(to_planet, planet_game);
    if(id_planet == -1 && to_planet != 1)
    {
        std::cout << "Изучение портала" <<std::endl;
        planet_game[is_planet_unique(player.get_current_planet(),planet_game)].add_to_vector_pair_whereTo(std::make_pair(num_of_portal, to_planet));
        planet new_one;
        new_one.add_to_vector_pair_whereTo(std::make_pair(random(1, new_one.get_number_of_portals()), player.get_current_planet()));
        new_one.set_number_of_planet(to_planet);
        planet_game.push_back(new_one);

        player.set_current_planet(to_planet);
    }
    else
    {

        std::cout << "Старый... " <<std::endl;
    }








return 0;
}


void step_to_portal(adventurer &player, int planet_N)
{
    player.set_current_planet(planet_N);
//    player.set_current_id(planet_id);
}




//void step_to_portal(uint num_of_portal, adventurer &player, std::vector<planet> &planet_game )
//{
//    int tp_cur=planet::is_tp_on_planet(num_of_portal, planet_game[player.get_current_id()].get_vector_whereTo());

//    if(tp_cur == 0)
//    {
//        std::cout << "Изучение портала" <<std::endl;
//        uint to_planet = random(1, 10);    // тут задается макс число планет.
//        uint id_planet = is_planet_unique(to_planet, planet_game);   // нужна подмена планеты если на той что выбрали не осталось парталов ... мб сделать проверку на освобожденность планет
//        if(id_planet == 0 && to_planet != 1)
//        {
//            std::cout <<"Обнаружена НОВАЯ планета! под номером " << to_planet <<std::endl;

//            planet new_one;
//            new_one.add_to_vector_pair_whereTo(std::make_pair(random(1, new_one.get_number_of_portals()), player.get_current_planet()));
//            new_one.set_number_of_planet(to_planet);
//            planet_game.push_back(new_one);

//            player.set_current_planet(to_planet);  // объеденить#1
//            uint current_id_planet = is_planet_unique(player.get_current_planet(), planet_game); // объеденить#1
//            player.set_current_id(current_id_planet);// объеденить#1
//        }
//        else
//        {
//            std::cout <<"Обнаружена СТАРАЯ планета!" <<std::endl;
            // нужна проверка на кол-во тп  num_of_portal
//            if( planet_game[id_planet].how_many_portals_are_fee() == 0) // тупая проверка
//            {
//                std::cout << "Места нет =ССССССССССССССССССССССССССС" << std::endl;

//                planet_game[id_planet].print_whereTO_portals();

//              std::cout << "Места нет =ССССССССССССССССССССССССССС" << std::endl;
//            }
//            else
//            {
//                uint freetp = planet_game[id_planet].choose_free_portail_for_transport();
//                planet_game[id_planet].add_to_vector_pair_whereTo(std::make_pair(freetp, player.get_current_planet()));



//                player.set_current_planet(to_planet);  // объеденить  тож самое что чуть выше #1
//                player.set_current_id(is_planet_unique(player.get_current_planet(), planet_game));// объеденить#1
//            }
////        }

//    }
//    else
//    {
//        std::cout << "!!!!!!!!!!! старый телепорт !!!!" << std::endl;

//    }





//}


































//void step(adventurer &player, std::vector<planet> &planet_game ) // добавить правильный поиск портала (проверка на свободность) + поиск текущей планеты в векторе оформить +  проверка планеты с учетом поратлов
//{
//std::cout <<"<<<<<<<<<<<<<<<<<<<<<<<<<<" <<std::endl;

//uint current_id_planet = is_planet_unique(player.get_current_planet(), planet_game);

//std::cout <<"id планеты в векторе "<< current_id_planet  <<std::endl;

//std::cout<< "Колво порталов на планете " << planet_game[current_id_planet].get_number_of_planet() <<" число: " <<planet_game[current_id_planet].get_number_of_portals() << std::endl;
////    std::cout << "LOL" ;

////        unsigned int what_teleport = planet.random(0, planet_game[player.get_current_planet()].get_number_of_portals());



////std::cout << planet_game[current_id_planet].get_vector_whereTo().size();

//if(planet_game[current_id_planet].get_vector_whereTo().size() > 0 )   // не верна логика
//{
//    // проверь

//}
//else
//{
//    uint what_teleport = random(1, planet_game[current_id_planet].get_number_of_portals());
//    std::cout << "what_teleport " << what_teleport;
//    uint to_planet = random(1, 10);    // тут задается макс число планет.

//    std::cout<< "is_tp_on_planet " << planet::is_tp_on_planet(what_teleport, planet_game[current_id_planet].get_vector_whereTo())  << std::endl;

//    if(planet::is_tp_on_planet(what_teleport, planet_game[current_id_planet].get_vector_whereTo()) == 0)
//    {
//    std::cout << "нет телепорта" << std::endl;
//    planet_game[current_id_planet].add_to_vector_pair_whereTo(std::make_pair(what_teleport, to_planet));
//    }
//    else
//        to_planet = planet::is_tp_on_planet(what_teleport, planet_game[current_id_planet].get_vector_whereTo());
//    // добавить элемент без проверки

//    std::cout << " на планету " << planet_game[current_id_planet].get_vector_whereTo()[current_id_planet].second << " Свободно "<< planet_game[current_id_planet].how_many_portals_are_fee() <<std::endl;
//    std::vector<planet>::iterator it;        // Iterator
//    bool flag = 0;
//    for(it = planet_game.begin(); it < planet_game.end(); it++)
//    {
//        if(it->get_number_of_planet() == to_planet)
//        {
//            flag = 1;
//            planet new_one;
//            new_one.add_to_vector_pair_whereTo(std::make_pair(random(1, new_one.get_number_of_portals()) , current_id_planet));
//            planet_game.push_back(new_one);

//            player.set_current_planet(to_planet);

//            break;
//            // переместись
//        }
//    }

//    if(flag == 0)
//    {
//        // создай и переместись
//    }

//}


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

//   std::cout <<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>" <<std::endl;

//}
