#include <cstring>
#include <string>
#include <exception>
#include <vector>
// #include "../Deck/Deck.hpp"
// #include "../Card/Card.hpp"

using namespace std;

class Player
{
private:
    int gameID;
    string username;
    int score;
    // DeckPlayer deck;

    /**
     * @brief Ask for username from the user
     *
     */
    string askForUsername();

public:
    /**
     * @brief Construct a new Player object. Menanyakan username pemain melalui CLI.
     *
     */
    Player(int gameID);

    /**
     * @brief Destroy the Player object
     *
     */
    ~Player();

    /**
     * @brief Construct a new player object from another player
     *
     */
    Player(const Player &);

    /**
     * @brief Assign a player to another player with the assignment operator
     *
     */
    Player &operator=(const Player &);

    /**
     * @brief Get the username of the player
     *
     * @return string
     */
    string getUsername() const;

    /**
     * @brief Return the gameID of the object
     *
     * @return int
     */
    int getGameID();

    /**
     * @brief Get the player's score
     *
     * @return int
     */
    int getScore();

    /**
     * @brief Add score to the player
     *
     * @param addedScore
     */
    void operator+=(int addedScore);

    /**
     * @brief Subtract the player's score
     *
     * @param subtractedScore
     */
    void operator-=(int subtractedScore);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is lower than the right
     * @return false Left player's score is not lower than the right player
     */
    bool operator<(const Player &);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is higher than the right
     * @return false Left player's score is not higher than the right player
     */
    bool operator>(const Player &);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is higher or equal to the right player
     * @return false Left player's score is not higher and not equal than the right player
     */
    bool operator>=(const Player &);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is lower or equal to the right player
     * @return false Left player's score is not lower and not equal than the right player
     */
    bool operator<=(const Player &);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is equal to the right player
     * @return false Left player's score is not equal to the right player
     */
    bool operator==(const Player &);

    /**
     * @brief Compare the player's score
     *
     * @return true Left player's score is not equal to the right player
     * @return false Left player's score is equal to the right player
     */
    bool operator!=(const Player &);

    /**
     * @brief Subtract the player's score
     *
     * @param subtractedScore
     */
    void subtractScore(int subtractedScore);

    /**
     * @brief Add score to the player
     *
     * @param addedScore
     */
    void addScore(int addedScore);

    /**
     * @brief Reset the player's score to 0
     *
     */
    void resetScore();

    /**
     * @brief Swap the deck of this player and the given player
     *
     * @param givenPlayer
     */
    void swapDeck(Player &givenPlayer);

    /**
     * @brief Ask for username again
     *
     */
    void resetUsername();

    /**
     * @brief Ask username from the user and validate its result until it's correct
     *
     */
    void setValidUsername();

    /**
     * @brief Print out the score
     *
     */
    void printScore();

    /**
     * @brief Print out the player's card
     *
     */
    void printColorCard();

    // Overloading untuk ngurusin deck nggak diimplementasikan dulu karena urusannya sama deck
    /*
    void operator+(Card<CardValueType> addedCard);
    */
};