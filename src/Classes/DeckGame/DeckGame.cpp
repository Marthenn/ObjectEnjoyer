#include "DeckGame.hpp"
#include "../ColorCard/ColorCard.hpp"
#include "../AbilityCard/AbilityCard.hpp"

#include <vector>

template <typename T>
DeckGame<T>::DeckGame() : Deck<T>::Deck(){};

template <class T>
DeckGame<T>::DeckGame(std::vector<T> vec) : Deck<T>::Deck(vec){};

template <typename T>
DeckGame<T>::DeckGame(const Deck<T> &other) : Deck<T>::Deck(other) {}

template <typename T>
int DeckGame<T>::getCombinationValueWith(const Deck<T> &deckPlayer) const
{
    return 0;
}

template class DeckGame<ColorCard>;
template class DeckGame<AbilityCard>;
