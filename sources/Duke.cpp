#include "Game.hpp"
#include "Duke.hpp"
#include <stdexcept>
namespace coup {
    void Duke::block(Player &player) {
        if (player.last_act != FOREIGN_AID){
            throw runtime_error("duke block only forign_aid.");
        }
        player._coin-=2;
    }

    void Duke::tax() {
        this->_coin += 3;
        this->last_act = TAX;
        game->tur++;
    }

    Duke::Duke(Game &game, string name) : Player(game, name) {
        this->game->num_players++;
        this->game->ps.push_back(this);
        this->game->names.push_back(name);
    }
}