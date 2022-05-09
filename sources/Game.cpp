
#include "Game.hpp"
#include "Player.hpp"
#include <stdexcept>

namespace coup {
    string Game::turn() {
        while(ps.at(tur%ps.size())->couped){
            tur++;
        }
        return ps.at(tur%ps.size())->name;
    }

    string Game::winner() {
        if (num_players != 1){
            throw runtime_error("no exist winner");
        }
        for (size_t i = 0; i < ps.size(); ++i) {
            if (!ps.at(i)->couped){
                return ps.at(i)->name;
            }
        }
        return this->win;
    }

    vector<string> Game::players() const {
        return this->names;
    }
}
