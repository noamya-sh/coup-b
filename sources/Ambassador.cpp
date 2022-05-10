#include "Game.hpp"
#include "Ambassador.hpp"
#include <stdexcept>
using namespace std;
const int MAX_P = 6;
const int ZERO = 0;
namespace coup {
    void Ambassador::transfer(Player &player1, Player &player2) {
        if(game->ps.size()> MAX_P){
            throw runtime_error("too much players");
        }
        if (player1._coin <= ZERO){
            throw runtime_error("not enough coins");
        }
        player1._coin--;
        player2._coin++;
        this->last_act = TRANSFER;
        game->tur++;
    }

    void Ambassador::block(Player &player) {
        if (player.last_act != STEAL1 && player.last_act != STEAL2){
            throw runtime_error("block only steal act");
        }
        if (player.last_act == STEAL1){
            player._coin-=1;
            player.stolen->_coin+=1;
        }
        else {
            player._coin-=2;
            player.stolen->_coin+=2;
        }
        player.stolen = nullptr;
    }


    Ambassador::Ambassador(Game &game, const string &name) : Player(game, name) {
        this->game->insert(name, *this);
    }
}