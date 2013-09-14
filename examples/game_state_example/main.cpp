#include <iostream>
#include <game.hpp>
#include "sample_game_state.h"
#include <memory>
#include <future>


int main(int argc, char **argv)
{
    try {
        pacman::game game(std::unique_ptr<pacman::game_state>(new sample_game_state));
        game();
    } catch (const std::exception& ex) {
        std::cout << "pacman exception: " << ex.what() << std::endl;
    }
    return 0;
}
