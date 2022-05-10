#include "Game.hpp"
#include "Contessa.hpp"
#include <stdexcept>
namespace coup {
    void Contessa::block(Player &player) {
        if (player.last_act != COUP3){
            throw runtime_error("block only coup3");
        }
        this->game->names.push_back( player.dead->name);
        player.dead->couped = false;
        player.dead = nullptr;
        this->game->num_players++;
    }

    Contessa::Contessa(Game &game, string name) : Player(game, name) {
        this->game->num_players++;
        this->game->ps.push_back(this);
        this->game->names.push_back(name);
    }
}
