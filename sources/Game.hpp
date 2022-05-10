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
        string win = "nothing";
//        string tur;


    public:
        size_t tur;
        int num_players = 0;
        vector<Player*> ps;
        vector<string> names;
        string turn();
        vector<string> players() const;
        string winner();
        bool run = false;
        ~Game()= default;
        void run_game();
    };
}
#endif