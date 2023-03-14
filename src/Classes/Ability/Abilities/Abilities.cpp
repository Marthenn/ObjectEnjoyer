#include "Abilities.hpp"
#include "../../GameCandy/GameCandy.hpp"

Quadruple::Quadruple() : Ability("QUADRUPLE", "Quadruple the reward of the current round", 1){};

void Quadruple::activateAbility(GameCandy &gC)
{
    gC.quadruplePoint();
}