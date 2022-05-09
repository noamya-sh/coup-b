#include "Game.hpp"
#include "Captain.hpp"

namespace coup {
    void Captain::steal(Player &player) {
        if (player._coin>=2){
            player._coin-=2;
            this->_coin+=2;
            this->stolen = &player;
            this->last_act = STEAL2;
        }
        if (player._coin == 1) {
            player._coin-=1;
            this->_coin+=1;
            this->stolen = &player;
            this->last_act = STEAL1;
        }
        game->tur++;
    }

    void Captain::block(Player &player) {

    }

    Captain::Captain(Game &game, string name) : Player(game, name) {
        this->game->num_players++;
        this->game->ps.push_back(this);
    }
}