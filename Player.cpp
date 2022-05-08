#include <stdexcept>
#include "Player.hpp"
namespace coup{

    void Player::foreign_aid() {
        this->_coin+=2;
        this->last_act = FOREIGN_AID;
    }
    void Player::coup(Player &player) {
        if (this->_coin < 7){
            throw runtime_error("can't possible.");
        }
        this->last_act = COUP7;
        return;
    }

    void Player::income() {
        this->_coin++;
        this->last_act = INCOME;
    }
}
