#include "PlayerInGameCandy.hpp"

PlayerInGameCandy::PlayerInGameCandy(int numberOfPlayer, int currentTurn) : PlayerInGame(numberOfPlayer, currentTurn){

                                                                            };

void PlayerInGameCandy::showLeaderboard()
{
    int numberOfPlayer = getNumberOfPlayer();
    for (int i = 0; i < numberOfPlayer; i++)
    {
        cout << i + 1 << ".";
        players.at(i).getScore();
    }
}

void PlayerInGameCandy::reverseTurn()
{
    // Need implementation
}