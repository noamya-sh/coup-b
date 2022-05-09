#include <stdexcept>
#include "Player.hpp"
#include "Game.hpp"
namespace coup{
    void Player::check(){
        if(this->game->num_players<2){
            throw invalid_argument{"no enough players"};
        }
        if(this->game->num_players>6){
            throw invalid_argument{"too much players"};
        }
    }
    void Player::foreign_aid() {
        check();
        this->_coin+=2;
        this->last_act = FOREIGN_AID;
        this->game->tur++;
    }
    void Player::coup(Player &player) {
        check();
        if (this->_coin < 7){
            throw runtime_error("can't possible.");
        }
        this->last_act = COUP7;
        this->game->tur++;
        return;
    }

    void Player::income() {
        check();
        this->_coin++;
        this->last_act = INCOME;
        this->game->tur++;
    }
}
