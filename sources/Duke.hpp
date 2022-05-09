#include <utility>
#include "Player.hpp"
using namespace std;

namespace coup{
class Duke: public Player{
    public:
        Duke(Game &game, string name);
        ~Duke()= default;
        string role() const override { return "Duke";}
        void tax();
        void block(coup::Player &player);
    };
}