#include "Game.hpp"
#include "Assassin.hpp"
#include <stdexcept>
namespace coup{

    void Assassin::coup(Player &player) {

        Player::coup(player);
    }

    Assassin::Assassin(Game &game, string name) : Player(game, name){
        this->min_coup = 3;
        this->game->num_players++;
    }
}