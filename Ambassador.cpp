#include "Game.hpp"
#include "Ambassador.hpp"
#include <stdexcept>
using namespace std;
namespace coup {
    void Ambassador::transfer(Player &player1, Player &player2) {
        player1._coin--;
        player2._coin++;
        this->last_act = TRANSFER;
    }

    void Ambassador::block(Player &player) {
        if (player.last_act != STEAL1 && player.last_act != STEAL2){
            throw runtime_error("block only steal act");
        }
        if (player.last_act == STEAL1){
            player._coin-=1;
        }
        else {
            player._coin-=2;
        }
        player.blocked = true;
    }


    Ambassador::Ambassador(Game &game, string name) : Player(game, name) {
        this->game->num_players++;
    }
}