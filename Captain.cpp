//
// Created by נעמיה on 28/04/2022.
//
#include "Game.hpp"
#include "Captain.hpp"

namespace coup {
    void Captain::steal(Player &player) {

    }

    void Captain::block(Player &player) {

    }

    Captain::Captain(Game &game, string name) : Player(game, name) {
        this->game->num_players++;
    }
}