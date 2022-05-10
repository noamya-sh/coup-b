#include "Game.hpp"
#include "Assassin.hpp"
#include <stdexcept>
namespace coup{

    void Assassin::coup(Player &player) {
        if (this->coins() > 7){
            Player::coup(player);
        }
        else if (this->coins() >= 3){
            if(player.couped){
                throw invalid_argument{"this player already deposed"};
            }
            this->dead = &player;
            player.couped = true;
            this->game->names.erase(
                    std::remove(this->game->names.begin(), this->game->names.end(),
                                player.name),this->game->names.end());
            this->last_act = COUP3;
            this->_coin-=3;
            this->game->num_players--;
        }
        else{
            throw runtime_error("There is not enough coins");
        }
        game->tur++;
    }

    Assassin::Assassin(Game &game, string name) : Player(game, name){
        this->min_coup = 3;
        this->game->num_players++;
        this->game->ps.push_back(this);
        this->game->names.push_back(name);
    }
}