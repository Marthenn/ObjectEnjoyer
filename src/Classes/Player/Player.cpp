#include "Player.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"
#include "../ColorCard/ColorCard.hpp"
#include "../PlayerException/PlayerException.hpp"
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

using namespace std;
template <typename T>
Player<T>::Player()
{
    this->gameID = 0;
    username = "";
    score = 0;
}

template <typename T>
Player<T>::Player(int gameID)
{
    this->gameID = gameID;
    score = 0;
    setValidUsername();
};

template <typename T>
Player<T>::~Player(){};

template <typename T>
Player<T>::Player(const Player<T> &other)
{
    this->gameID = other.gameID;
    this->username = other.getUsername();
    this->score = other.getScore();
    this->handCards = other.handCards;
};

template <typename T>
void Player<T>::setValidUsername()
{
    bool validUsername = false;
    string usernameCandidate;
    while (!validUsername)
    {
        try
        {
            usernameCandidate = askForUsername();
            validUsername = true;
        }
        catch (UsernameEmpty e)
        {
            cout << e.getMessage() << endl;
        }
    }
    this->username = usernameCandidate;
};

template <typename T>
string Player<T>::askForUsername()
{
    cout << "Input username player " << this->gameID << " : ";
    string askedUsername;
    cin >> askedUsername;
    if (askedUsername == "")
    {
        throw UsernameEmpty();
    }
    return askedUsername;
};

template <typename T>
void Player<T>::setGameID(int gameID)
{
    this->gameID = gameID;
}

template <typename T>
string Player<T>::getUsername() const
{
    return username;
}

template <typename T>
DeckPlayer<T> Player<T>::getHand()
{
    DeckPlayer<T> handCardsCopy = this->handCards;
    return handCardsCopy;
}

template <typename T>
Player<T> &Player<T>::operator=(const Player<T> &givenPlayer)
{
    this->username = givenPlayer.getUsername();
    this->gameID = givenPlayer.gameID;
    this->handCards = givenPlayer.handCards;
    return *this;
};

template <typename T>
long long Player<T>::getScore() const
{
    return this->score;
};

template <typename T>
void Player<T>::addScore(long long addedScore)
{
    this->score += addedScore;
};

template <typename T>
void Player<T>::subtractScore(long long subtractedScore)
{
    this->score -= subtractedScore;
};

template <typename T>
void Player<T>::operator+=(long long addedScore)
{
    this->addScore(addedScore);
};

template <typename T>
void Player<T>::operator-=(long long subtractedScore)
{
    subtractScore(subtractedScore);
};

template <typename T>
void Player<T>::resetScore()
{
    this->score = 0;
};

template <typename T>
void Player<T>::printScore()
{
    cout << username << ": " << getScore() << endl;
};

template <typename T>
int Player<T>::getGameID()
{
    return gameID;
};

template <typename T>
void Player<T>::addCard(const T &card)
{
    handCards += card;
};

template <typename T>
void Player<T>::swapDeck(Player<T> &givenPlayer)
{
    handCards.swap(givenPlayer.handCards);
};

template <typename T>
void Player<T>::printCard()
{
    vector<ColorCard> handCardVec = handCards.getDeck();
    cout << "|  ";
    for (auto i = handCardVec.begin(); i != handCardVec.end(); ++i)
    {
        cout << *i;
    }
    cout << endl;
};

template <typename T>
void Player<T>::printCard(bool sorted) {
    if(sorted){
        DeckPlayer<T> tempDeck = handCards;
//        tempDeck.sort();

        vector<ColorCard> handCardVec = tempDeck.getDeck();

        cout << "|  ";
        for (auto i = handCardVec.begin(); i != handCardVec.end(); ++i)
        {
            cout << *i;
        }
        cout << endl;
    } else {
        Player<T>::printCard();
    }
}

template <typename T>
void Player<T>::printCard(Color colorFilter)
{
    bool printed = false;

    vector<ColorCard> handCardVec = handCards.getDeck();
    cout << "|  ";
    for (auto i = handCardVec.begin(); i != handCardVec.end(); ++i)
    {
        if((*i).getColor() == colorFilter){
            cout << *i;
            printed = true;
        }
    }

    if(!printed){
        cout << "No card matched the color Filter!";
    }

    cout << endl;
};

template <typename T>
void Player<T>::drawCard(DeckGame<T> &deckGame, int numberOfCards)
{
    handCards.drawCard(deckGame, numberOfCards);
};

template <typename T>
void Player<T>::operator+=(const T &addedCard)
{
    handCards += addedCard;
};

template <typename T>
bool Player<T>::operator!=(const Player<T> &otherPlayer)
{
    return score != otherPlayer.score;
};

template <typename T>
bool Player<T>::operator<(const Player<T> &otherPlayer)
{
    return score < otherPlayer.score;
};

template <typename T>
bool Player<T>::operator>(const Player<T> &otherPlayer)
{
    return score > otherPlayer.score;
};

template <typename T>
bool Player<T>::operator<=(const Player<T> &otherPlayer)
{
    return score <= otherPlayer.score;
};

template <typename T>
bool Player<T>::operator>=(const Player<T> &otherPlayer)
{
    return score >= otherPlayer.score;
};

template <typename T>
bool Player<T>::operator==(const Player<T> &otherPlayer)
{
    return score == otherPlayer.score;
};

template <typename T>
void Player<T>::redrawCard(DeckGame<T> &deckGame, int newNumberOfCards)
{
    int currentNumberOfCards = handCards.getNumberOfCards();
    for (int i = 0; i < currentNumberOfCards; i++)
    {
        T returnedCard = handCards.ejectCard();
        deckGame += returnedCard;
    };
    drawCard(deckGame, newNumberOfCards);
};

template <typename T>
void Player<T>::redrawCard(DeckGame<T> &deckGame)
{
    int numberOfCards = handCards.getNumberOfCards();
    for (int i = 0; i < numberOfCards; i++)
    {
        deckGame.addCardBack(handCards.ejectCard());
    }
    drawCard(deckGame, numberOfCards);
};

template <typename T>
T Player<T>::ejectCard()
{
    return handCards.ejectCard();
};

template <typename Y>
std::ostream &operator<<(std::ostream &os, const Player<Y> &player)
{
    os << player.getUsername();
    return os;
};

template class Player<ColorCard>;
template std::ostream &operator<<(std::ostream &os, const Player<ColorCard> &deck);