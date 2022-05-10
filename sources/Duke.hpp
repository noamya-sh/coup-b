#include <utility>
#include "Player.hpp"
using namespace std;

namespace coup{
class Duke: public Player{
    public:
        Duke(Game &game, string const &name);
        ~Duke()= default;
        string role() const override { return "Duke";}
        void tax();
        static void block(coup::Player &player);
    };
}