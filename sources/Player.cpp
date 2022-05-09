#include <stdexcept>
#include "Player.hpp"
#include "Game.hpp"
const int MUST_COUP = 10;
namespace coup{
    void Player::check(){
        if(this->game->ps.size()<2){
            throw runtime_error{"no enough players"};
        }
        if(this->game->ps.size()>6){
            throw runtime_error{"too much players"};
        }
        if(this->game->turn()!= this->name){
            throw runtime_error("not your turn");
        }
        if(this->coins()>=MUST_COUP){
            throw invalid_argument{"you must coup someone!"};
        }
    }
    void Player::foreign_aid() {
        check();
        this->_coin+=2;
        this->last_act = FOREIGN_AID;
        this->game->tur++;
    }
    void Player::coup(Player &player) {
        if(this->game->turn()!= this->name){
            throw runtime_error("not your turn");
        }
        if(player.couped){
            throw invalid_argument{"this player already deposed"};
        }
        if (this->_coin < 7){
            throw runtime_error("can't possible.");
        }
        player.couped = true;
        game->num_players--;
        this->last_act = COUP7;
        this->dead = &player;
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
