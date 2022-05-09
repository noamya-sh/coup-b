#ifndef _PlAYER_h__
#define _PlAYER_h__
#pragma once
#include <string>
#include <utility>


using namespace std;

namespace coup{
    enum act{
        START,INCOME,FOREIGN_AID,TAX,BLOCK,COUP3,COUP7,TRANSFER,STEAL1,STEAL2
    };
    class Game;
    class Player{
    protected:
        Game* game;

        int min_coup = 7;
        string name;

    public:
        act last_act =START;
        int _coin;
        Player(Game &game, string name): game(&game),name(move(name)),_coin(0){}
        virtual string role() const=0;
        int coins() const { return this->_coin;};
        void income();
        void foreign_aid();
        virtual void coup(Player &player);
        bool blocked = false;

    };
}
#endif
