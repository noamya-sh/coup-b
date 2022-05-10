#include "Game.hpp"
#include "Contessa.hpp"
#include <stdexcept>
namespace coup {
    void Contessa::block(Player &player) {
        if (player.last_act != COUP3){
            throw runtime_error("block only coup3");
        }
        this->game->names.insert(this->game->names.begin() + player.dead->index, player.dead->name);//push_back( player.dead->name);
        player.dead->couped = false;
        player.dead = nullptr;
        this->game->num_players++;
    }

    Contessa::Contessa(Game &game, string &name) : Player(game, name) {
        this->game->insert(name, *this);
    }
}
