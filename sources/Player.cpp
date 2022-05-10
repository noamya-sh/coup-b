#include <stdexcept>
#include "Player.hpp"
#include "Game.hpp"
const int MUST_COUP = 10;
const int MAX_P = 6;
const int MIN_P= 2;
const int CAN_C = 7;
namespace coup{
    void Player::check(){
        if(this->game->ps.size()<MIN_P){
            throw runtime_error{"no enough players"};
        }
        if(this->game->ps.size()>MAX_P){
            throw runtime_error{"too much players"};
        }
        game->run_game();
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
        if (this->_coin < CAN_C){
            throw runtime_error("can't possible.");
        }
        player.couped = true;
        game->num_players--;
        this->game->names.erase(
                std::remove(this->game->names.begin(), this->game->names.end(),
                            player.name),this->game->names.end());
        this->last_act = COUP7;
        this->_coin-=CAN_C;
        this->dead = &player;
        this->game->tur++;
    }

    void Player::income() {
        check();
        this->_coin++;
        this->last_act = INCOME;
        this->game->tur++;
    }

    Player::Player(Game &game, const string &name) {
        if (game.run){
            throw runtime_error("the game run");
        }
        if (game.num_players >= MAX_P){
            throw runtime_error("too much players.");
        }
        this->index = game.ind++;
        this->game = &game;
        this->name = name;
        this->_coin = 0;

    }
}
