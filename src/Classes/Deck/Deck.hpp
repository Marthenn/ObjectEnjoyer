#ifndef _DECK_HPP_
#define _DECK_HPP_

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
#include "Classes/Card/Card.hpp"
#include "Classes/InventoryHolder/InventoryHolder.hpp"

template <class T>
class Deck : InventoryHolder<T>
{
protected:
    /**
     * Deck holds a vector of cards
     *  How we interact with deck should follow these rules :
     *      - index with higher values should hold Card that is being on topmost of the Deck stack
     *      - Game should only be able to add Card to and/or draw from the topmost of the Deck stack
     */
    std::vector<T> vec;

public:
    /**
     * @brief construct new Deck with empty vector as its attribute
     */
    Deck();

    /**
     * @brief construct new Deck with a given value as its attribute
     *
     * @param vec vector that will be set as the attribute of this Deck
     */
    Deck(std::vector<T> vec);

    /**
     * @brief construct new Deck based on an already constructed Deck
     *
     * @param other the other Deck
     */
    Deck(const Deck &other);

    /**
     * @brief destruct a constructed Deck
     */
    ~Deck();

    /**
     * @brief set a vector of cards as the content of Deck
     */
    void setDeck(std::vector<T> vec);

    /**
     * @brief get the cards contained by the Deck as a vector
     */
    std::vector<T> getDeck();

    /**
     * @brief Get the number of cards in this deck
     *
     * @return int
     */
    int getNumberOfCards();

    /**
     * @brief add a card into the deck
     */
    void addCard(const T &);

    /**
     * @brief shorthand for addCard()
     */
    void operator+=(const T &);

    /**
     * @brief sort deck by value
     */
    void sort();

    /**
     * @brief swap contents with another deck
     */
    void swap(Deck &other);

    /**
     * @brief swap the content of two separate Decks
     */
    static void swapDeck(Deck &deck1, Deck &deck2);

    /**
     * @brief shuffle deck
     */
    void shuffle();

    /**
     * @brief print
     */
    template <typename Y>
    friend std::ostream &operator<<(std::ostream &os, const Deck<Y> &deck);
};

#endif