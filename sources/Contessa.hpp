#include <utility>
#include "Player.hpp"

using namespace std;
namespace coup{
    class Contessa: public Player{
    public:
        Contessa(Game &game, const string &name);
        ~Contessa()= default;
        string role() const override{ return "Contessa";}
        void block(Player &player);
    };
}