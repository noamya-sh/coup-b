#include "Game.hpp"
#include "Contessa.hpp"

namespace coup {
    void Contessa::block(Player &player) {

    }

    Contessa::Contessa(Game &game, string name) : Player(game, name) {
        this->game->num_players++;
        this->game->ps.push_back(this);
    }
}
