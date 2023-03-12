#ifndef _COMBINATION_HPP_
#define _COMBINATION_HPP_

#include "../Deck/Deck.hpp"
#include "../ColorCard/ColorCard.hpp"
#include <vector>
using namespace std;

class Combination{
    private:
        typedef enum{
            HIGH_CARD,
            PAIR,
            TWO_PAIRS,
            THREE_OF_A_KIND,
            STRAIGHT,
            FLUSH,
            FULL_HOUSE,
            FOUR_OF_A_KIND,
            STRAIGHT_FLUSH,
        } CombinationType;
        int score;
        CombinationType combinationType;
        vector <ColorCard> allCards;
        vector <ColorCard> playerCards;
        vector <ColorCard> usedCards;
    public:
        Combination(vector<ColorCard> player, vector<ColorCard> table);

        void calculate(vector<ColorCard> player, vector<ColorCard> table);

        void isStraightFlush();

        void isFourOfAKind();

        void isFullHouse();

        void isFlush();

        void isStraight();

        void isThreeOfAKind();

        void isTwoPair();

        void isOnePair();

        void getHighestCard();

        bool inPlayer();

        void print();

        bool operator<(Combination& other);

        bool operator>(Combination& other);
};

#endif