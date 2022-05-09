#include "Game.hpp"
#include "Assassin.hpp"
#include <stdexcept>
namespace coup{

    void Assassin::coup(Player &player) {
        if (this->coins() > 7){
            Player::coup(player);
        }
        else if (this->coins() > 3){
            this->last_act = COUP3;

        }
        else{
            throw runtime_error("There is not enough money");
        }
        game->tur++;
    }

    Assassin::Assassin(Game &game, string name) : Player(game, name){
        this->min_coup = 3;
        this->game->num_players++;
        this->game->ps.push_back(this);
        this->game->names.push_back(name);
    }
}