#include "Game.hpp"
#include "Assassin.hpp"
#include <stdexcept>
namespace coup{

    void Assassin::coup(Player &player) {
        if (this->coins() > 7){
            Player::coup(player);
        }
        else if (this->coins() > 3){

        }
        else{
            throw runtime_error("There is not enough money");
        }

    }

    Assassin::Assassin(Game &game, string name) : Player(game, name){
        this->min_coup = 3;
        this->game->num_players++;
    }
}