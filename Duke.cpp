#include "Game.hpp"
#include "Duke.hpp"
#include <stdexcept>
namespace coup {
    void Duke::block(Player &player) {
        if (player.last_act != FOREIGN_AID){
            throw runtime_error("can't block.");
        }
        player._coin-=2;
        player.blocked = true;
    }

    void Duke::tax() {
        this->_coin += 3;
        this->last_act = TAX;
    }

    Duke::Duke(Game &game, string name) : Player(game, name) {
        this->game->num_players++;
    }
}