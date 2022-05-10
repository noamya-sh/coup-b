#include "Game.hpp"
#include "Assassin.hpp"
#include <stdexcept>
const int MUST_C = 6;
const int CAN_C = 3;
namespace coup{

    void Assassin::coup(Player &player) {
        if (this->coins() > MUST_C){
            Player::coup(player);
        }
        else if (this->coins() >= CAN_C){
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
            game->tur++;
        }
        else{
            throw runtime_error("There is not enough coins");
        }
    }

    Assassin::Assassin(Game &game, string &name) : Player(game, name){
        this->min_coup = 3;
        this->game->insert(name, *this);
    }
}