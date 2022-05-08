#pragma once
#ifndef MYHEADEFILE_H
#define MYHEADEFILE_H
#include <string>
#include <vector>


using namespace std;
namespace coup{
    class Player;
    class Game{
    private:
        string win;
        string tur;


    public:
        int num_players = 0;
        vector<Player*> ps;
        string turn();
        vector<Player*> players() const;
        string winner();

    };
}
#endif