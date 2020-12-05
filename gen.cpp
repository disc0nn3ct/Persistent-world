#include  "gen.hpp"

int random(int min, int max) {
    static std::mt19937 prng(std::random_device{}());
    return std::uniform_int_distribution<>(min, max)(prng);
}


inline std::vector<std::pair<int, int>> const &planet::get_vector_whereTo() const  // запрет на попытки изменить объект через указатель
{return whereTO; }

inline void planet::add_to_vector_pair_whereTo(std::pair<int, int> const& par)
{
    this->whereTO.push_back(par);
}

inline int planet::how_many_portals_are_free() const
{
    return N_of_portals - whereTO.size();
}

int planet::choose_free_portail_for_transport()
{
    if (N_of_portals - whereTO.size() == 0)
    {
        return -1;
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
        return -1;
    }
}

int planet::is_tp_on_planet(int num) const   // если есть вернет куда, нет -1
{
    for(int i=0; i < whereTO.size(); i++)
    {
        if(whereTO[i].first == num)
        {
            return whereTO[i].second;
        }
    }
    return -1;
}

int is_planet_unique(int num,const std::vector<planet> &planet_game)  // вернет id планеты, если не существует -1
{
    for(int r=0; r < planet_game.size(); r++)
    {
        if(planet_game[r].get_number_of_planet() == num)
            return r;
    }
   return -1;
}

void planet::print_whereTO_portals()
{
    std::cout << "Планета: N " << N_planet << ", Всего порталов "<< N_of_portals <<". Занято " << whereTO.size() << ". О порталах вам известно:" << std::endl;
    if( whereTO.size() == 0 )
        std::cout << "Ничего =С " << std::endl;
    else
    {
        for(int i =0; i < whereTO.size(); i++ )
        {
            std::cout << "Портал N "<< whereTO[i].first << " ведет на планету "  << whereTO[i].second << std::endl;
        }
    std::cout << std::endl;
    }
}

bool spirit_of_verification(int max_num_planet,const std::vector<planet> &planet_game)
{
    int counter = 0;
    for(int i=0; i < max_num_planet; i++)
    {
        if( is_planet_unique(planet_game[i].get_number_of_planet(), planet_game) >=0 )
        {
            if(planet_game[i].how_many_portals_are_free() == 0)
                counter++;
        }
    }

    if(counter < max_num_planet-1)
    {
        return true; // значит еще место есть
    }
    else {
        return false; // места нет
    }
}

int step_to_new_portal(int num_of_portal, adventurer &player, std::vector<planet> &planet_game)
{
    int max_N_of_planet=1500;   // макс число планет в игре
    int to_planet =  random(1, max_N_of_planet);
    int checker = 0;
////////////////////////////////////////////////////////////////////////////////

while(player.get_current_planet() == to_planet || (planet_game[is_planet_unique(to_planet, planet_game)].how_many_portals_are_free() == 0 &&  is_planet_unique(to_planet, planet_game) != -1))
    {
    to_planet =  random(1, max_N_of_planet);

    if( max_N_of_planet <= planet_game.size())
    {
        if(spirit_of_verification(max_N_of_planet, planet_game) == 0) // мб не нужен - тк как не оч хорош
        {
            std::cout << "Все заполнено... Не могу идти дальше..." << std::endl;
            return -1;
        }
    }
  }

////////////////////////////////////////////////////////////////////////////////
    int id_planet = is_planet_unique(to_planet, planet_game);
//    if(id_planet == -1 && to_planet != 1)
    if(id_planet == -1)
    { // такой планеты нет
        std::cout << "Изучение портала" <<std::endl;
        planet_game[is_planet_unique(player.get_current_planet(),planet_game)].add_to_vector_pair_whereTo(std::make_pair(num_of_portal, to_planet));
        planet new_one;
        new_one.add_to_vector_pair_whereTo(std::make_pair(random(1, new_one.get_number_of_portals()), player.get_current_planet()));
        new_one.set_number_of_planet(to_planet);
        planet_game.push_back(new_one);
        player.set_current_planet(to_planet);
    }
    else
    { // такая планета есть
        std::cout << "Старая... " <<std::endl;
        // проверка есть ли там порт была ранее
        int freeTp = planet_game[is_planet_unique(to_planet, planet_game)].choose_free_portail_for_transport();
        std::cout << "Выбрали портал на планете "<< freeTp << std::endl;
        if(freeTp != -1)
        {
            planet_game[is_planet_unique(player.get_current_planet(),planet_game)].add_to_vector_pair_whereTo(std::make_pair(num_of_portal, to_planet));
            planet_game[id_planet].add_to_vector_pair_whereTo(std::make_pair(freeTp, player.get_current_planet()));
            player.set_current_planet(to_planet);
        }
        else
        {
            std::cout << "Error" <<std::endl;
            return -1;
        }
    }
return 0;
}

void step_to_portal(adventurer &player, int planet_N)
{
    player.set_current_planet(planet_N);
}

int save_game(const adventurer &player, const std::vector<planet> &planet_game)
{
    std::ofstream ofs("save");
    boost::archive::text_oarchive oa(ofs);
    oa << player;
    oa << planet_game;

    return 0;
}

int load_game(adventurer &player, std::vector<planet> &planet_game)
{
    std::ifstream ifs("save");
    boost::archive::text_iarchive ia(ifs);
    ia >> player;
    ia >> planet_game;
    return 0;
}


int user_play_or_bot() // вернет 0, если user play, -1 ошибка, либо вернет число ходов для бота
{
    int k=-3;
//    while(std::cout << "Вы хотите включить бота? 1=да; 0=нет ", !(std::cin >> k) || k>1 || k <0)
    if(std::cout << "Вы хотите включить бота? 1=да; 0=нет ", !(std::cin >> k) || k>1 || k <0)
    {
        return -1;
    }
    if(k==0)
        return 0;
    else
    {
        if(std::cout << "Сколько шагов боту? Шагов > 0: ", !(std::cin >> k) || k <=0)
        {
            return -1;
        }
        return k;
    }
    return -1;
}

int play(int k, adventurer &player, std::vector<planet> &planet_game, int f)
{
    if(k == 0) // новая игра
    {
        planet zeroo;
        zeroo.set_number_of_planet(player.get_current_planet());
        planet_game.push_back(zeroo);

    }
    if(k ==1)
    {
        // идет лоад
        std::cout<< "загрузка"<<std::endl;
        k =0; // user play
    }

    int current_id_planet = is_planet_unique(player.get_current_planet(), planet_game);

    int what_tp = 0;

    int c = 0;
    if(f != 0) // перехват управления, для работы без интерфейса
    {
        k = f;
    }
    else
    {
        k = user_play_or_bot();
    }
    if (k>0)
        c++;

    while(what_tp != -1 && c <= k)
    {
        planet_game[is_planet_unique(player.get_current_planet(), planet_game)].print_whereTO_portals();
        if(k == 0)  // user game
        {
        if(std::cout << "Команды: -1 exit. -2 save & exit. Выберите портал из диапазона! 1 до " << planet_game[is_planet_unique(player.get_current_planet(), planet_game)].get_number_of_portals() << ": " , !(std::cin >> what_tp)  || what_tp > planet_game[is_planet_unique(player.get_current_planet(), planet_game)].get_number_of_portals()) // минимальная проверка на ввод
        {
            return -1;
        }
        }
        else
        {
            what_tp = random(1, planet_game[is_planet_unique(player.get_current_planet(), planet_game)].get_number_of_portals());
            std::cout << "Бот выбрал портал N "<< what_tp <<std::endl;
            c++;
        }
        if(what_tp == -2)
        {
            std::cout<< "Save";
            save_game(player, planet_game);
            break;
        }


        if(planet_game[is_planet_unique(player.get_current_planet(), planet_game)].is_tp_on_planet(what_tp) == -1)
        {

            std::cout<< "Нет такого телепорта"<< std::endl;
            int fl = step_to_new_portal(what_tp, player, planet_game);
            if(fl == -1)
            {
                save_game(player, planet_game);
                std::cout<< "Больше я пожалуй ходить не буду" << std::endl;
                return -1;
            }
        }
        else
        {
            std::cout<< "есть такой портал, проверка переходит на планету c"<<  planet_game[is_planet_unique(player.get_current_planet(), planet_game)].is_tp_on_planet(what_tp) << " id планеты "<< is_planet_unique(player.get_current_planet(), planet_game) << " на планету " << planet_game[is_planet_unique(player.get_current_planet(), planet_game)].is_tp_on_planet(what_tp) << " id этой планеты " << is_planet_unique( planet_game[is_planet_unique(player.get_current_planet(), planet_game)].is_tp_on_planet(what_tp) ,planet_game )  << std::endl;
            step_to_portal(player, planet_game[is_planet_unique(player.get_current_planet(), planet_game)].is_tp_on_planet(what_tp) );
        }
    }
    if( k != 0 && f == 0)
    {
        std::cout <<"Бот закончил на планете: " << player.get_current_planet() <<std::endl;
        k=-3;
        if(std::cout << "Хотите сохранить игру бота? 1=Да; 0=Нет: ", !(std::cin >> k) || k>1 || k <0)
        {
            return -1;
        }
        if(k==0)
            return 0;
        else
        {
            save_game(player, planet_game);
            return 0;
        }
    }

    return 0;
}
