#ifndef GAMECANDY_HPP
#define GAMECANDY_HPP

#include "../Game/Game.hpp"
#include "../PlayerInGameCandy/PlayerInGameCandy.hpp"
#include "../DeckGame/DeckGame.hpp"
#include "GameCandyException/GameCandyException.hpp"
#include <map>
using namespace std;

typedef enum
{
    NEXT = 0,
    DOUBLE = 1,     // Double the reward of the current round
    HALF = 2,       // Half the reward of the current round
    REROLL = 3,     // Reroll all hand cards
    QUADRUPLE = 4,  // Quadruple the reward of the current round
    QUARTER = 5,    // Quarter the reward of the current round
    REVERSE = 6,    // Reverse the order of the players
    SWAP = 7,       // Swap a card from the hand with a card from another player's hand
    SWITCH = 8,     // Switch the hand cards with another player's hand cards
    ABILITYLESS = 9 // Disable the ability of a specific player
} Command;

map<string, Command> cmd{{"next", NEXT}, {"doubble", DOUBLE}, {"half", HALF}, {"re-roll", REROLL}, {"quadruple", QUADRUPLE}, {"quarter", QUARTER}, {"reverse", REVERSE}, {"swap", SWAP}, {"switch", SWITCH}, {"abilityless", ABILITYLESS}};

class GameCandy : public Game
{
private:
    PlayerInGameCandy players;   // pemain
    DeckGame<ColorCard> deck;            // deck game
    DeckGame<ColorCard> tableCard;       // table card
    // DeckGame<AbilityCard> abilityCard;
    int round;        // ronde
    double giftPoint; // point hadiah tiap akhir game
private:
    void multiplyGiftPoint(double multiplier);
    void operator*=(double multiplier);

public:
    /**
     * @brief Construct a new Game Candy object
     *
     */
    GameCandy();
    // jumlah player 7, ronde = 1, giftpoin 64

    /**
     * @brief Start game
     *
     */
    void start();

    /**
     * @brief Spash Screen
     * 
     */
    void splashScreen();

    /**
     * @brief Start game
     * 
     */
    void start();
    /**
     * @brief winning condition : one of the players has 2^32>= points
     *
     * @return true
     * @return false
     */
    bool isWinning();

    /**
     * @brief is round over
     *
     */
    bool isRoundOver();

    /**
     * @brief begin new game with same players, different deck card
     *
     */
    void newGame();
    // new deck card

    /**
     * @brief akhir dari maks ronde (belum tentu mendapat pemenang)
     *
     */
    void endOfGame();

    /**
     * @brief menjalankan game 1 ronde
     *
     */
    void startRound();

    /**
     * @brief mekanisme giliran pemain, currentPlayer akan input command dan command akan dijalankan
     *
     */
    void playerAction(string action);

    /**
     * @brief
     *
     */
    string inputCommand();

    /**
     * @brief if command valid return enum value of the user input command,
     * else throw exception
     *
     * @param command
     * @return int
     */
    string isCommandValid(string command);

    /**
     * @brief display splash screen
     * 
     */
    void splashScreen();

    /**
     * @brief if command valid return enum value of the user input command,
     * else throw exception
     * 
     * @param command 
     * @return int 
     */
    string isCommandValid(string command);

    /**
     * @brief 
     * 
     */
    DeckGame<ColorCard> randomizeColorCard();

    // DeckGame<AbilityCard> randomizeAbilityCard();
};

#endif