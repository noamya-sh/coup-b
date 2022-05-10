
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
        if (num_players != 1 || !this->run){
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

    void Game::run_game() {
        this->run = true;
    }

    void Game::insert(string const &name, Player &p) {
        this->num_players++;
        this->ps.push_back(&p);
        this->names.push_back(name);
    }
}
