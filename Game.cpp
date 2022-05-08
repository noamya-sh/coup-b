
#include "Game.hpp"
#include "Player.hpp"


namespace coup {
    string Game::turn() {
        return this->tur;
    }

    string Game::winner() {
        return this->win;
    }

    vector<Player *> Game::players() const {
        return this->ps;
    }
}
