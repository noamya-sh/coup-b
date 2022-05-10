#include <utility>
#include "Player.hpp"

using namespace std;
namespace coup{
    class Captain: public Player{
    public:
        Captain(Game &game, const string &name);
        ~Captain()= default;
        string role() const override { return "Captain";}
        void steal(Player &player);
        static void block(Player &player);
    };
}