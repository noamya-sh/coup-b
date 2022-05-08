#include <utility>
#include "Player.hpp"

using namespace std;
namespace coup{
    class Captain: public Player{
    public:
        Captain(Game &game, string name): Player(game,move(name)){}
        string role() const override { return "Captain";}
        void steal(Player &player);
        void block(Player &player);
    };
}