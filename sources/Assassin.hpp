#include <utility>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Assassin: public Player{
    public:
        Assassin(Game &game, string name);
        ~Assassin()= default;
        string role() const override { return "Assassin";}
        virtual void coup(Player &player) override;
    };
}
