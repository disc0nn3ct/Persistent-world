#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "gen.hpp"
#include <vector>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch_all.hpp>


TEST_CASE("Persistent world")
{
// подготовка к замерам
std::vector<planet> for_save_planet_game;
adventurer for_save_player;
play(0, for_save_player, for_save_planet_game, 250);


std::vector<planet> for_save_planet_game1;
adventurer for_save_player1;
play(0, for_save_player1, for_save_planet_game1, 500);


std::vector<planet> for_save_planet_game2;
adventurer for_save_player2;
play(0, for_save_player2, for_save_planet_game2, 1000);

std::vector<planet> for_save_planet_game3;
adventurer for_save_player3;
play(0, for_save_player3, for_save_planet_game3, 1500);


BENCHMARK("Save 250") {
    return save_game(for_save_player, for_save_planet_game);
};

BENCHMARK("Load 250") {
    std::vector<planet> for_load_planet_game;
    adventurer for_load_player;
    return load_game(for_load_player, for_load_planet_game);
};
BENCHMARK("Save 500") {
    return save_game(for_save_player1, for_save_planet_game1);
};

BENCHMARK("Load 500") {
    std::vector<planet> for_load_planet_game1;
    adventurer for_load_player1;
    return load_game(for_load_player1, for_load_planet_game1);
};

BENCHMARK("Save 1000") {
    return save_game(for_save_player2, for_save_planet_game2);
};

BENCHMARK("Load 1000") {
    std::vector<planet> for_load_planet_game2;
    adventurer for_load_player2;
    return load_game(for_load_player2, for_load_planet_game2);
};

BENCHMARK("Save 1500") {
    return save_game(for_save_player3, for_save_planet_game3);
};

BENCHMARK("Load 1500") {
    std::vector<planet> for_load_planet_game3;
    adventurer for_load_player3;
    return load_game(for_load_player3, for_load_planet_game3);
};
}

int main()
{

std::cout<< "Let's play!" << std::endl;


Catch::Session session;
int numFailed = session.run();

std::vector<planet> planet_game;
adventurer player;

int k=-2;
if(std::cout << "Нажмите 0 новой игры; 1 загрузки; -1 выход: ", !(std::cin >> k) || k >1 || k <-1 )
{
    return -1;
}
if(k == 0)
{
    play(k, player, planet_game); // new game
}
else
{
if(k == 1)
{
load_game(player, planet_game);

std::cout<< "UX get_current_planet " << player.get_current_planet() <<std::endl;
std::cout<< "tp on planet: "<< planet_game[is_planet_unique(player.get_current_planet(), planet_game)].get_number_of_portals() << std::endl;
planet_game[is_planet_unique(player.get_current_planet(), planet_game)].print_whereTO_portals();
play(k, player, planet_game);

// продолжить игру
}
else
    return 0; // выход
}

return 0;
}
