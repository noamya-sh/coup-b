#include <utility>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Ambassador: public Player{
    public:
        Ambassador(Game &game, string name): Player(game,move(name)){}
        string role() const override { return "Ambassador";}
        void transfer(Player &player1, Player &player2);
        void block(Player &player);
    };
}
