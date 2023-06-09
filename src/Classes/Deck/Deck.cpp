#include "Deck.hpp"

#include "../DeckException/DeckException.hpp"
#include "../Card/Card.hpp"
#include "../ColorCard/ColorCard.hpp"
#include "../AbilityCard/AbilityCard.hpp"

#include <vector>
#include <iostream>

template <typename T>
Deck<T>::Deck()
{
    std::vector<T> vec;

    this->vec = vec;
};

template <class T>
Deck<T>::Deck(std::vector<T> vec)
{
    this->vec = vec;
};

template <typename T>
Deck<T>::Deck(const Deck &other)
{
    this->vec = other.vec;
};

template <typename T>
Deck<T>::~Deck()
{
    this->vec.clear();
};

template <typename T>
void Deck<T>::setDeck(std::vector<T> vec)
{
    this->vec = vec;
};

template <typename T>
std::vector<T> Deck<T>::getDeck()
{
    return this->vec;
}

template <typename T>
void Deck<T>::shuffle()
{
    std::default_random_engine rng;
    rng.seed(time(0));

    std::shuffle(this->vec.begin(), this->vec.end(), rng);
};

template <typename T>
int Deck<T>::getNumberOfCards()
{
    return this->vec.size();
};

// template <typename T>
// int Deck<T>::getValueSum() {
//     int sum = 0;
//
//     for (auto card : this->vec) {
//         sum += card.value();
//     }
//
//     return sum;
// }

template <typename T>
void Deck<T>::addCard(const T &card)
{
    this->vec.push_back(card);
};

template <typename T>
void Deck<T>::addCardBack(const T &card)
{
    this->vec.insert(vec.begin(), card);
};

template <typename T>
void Deck<T>::operator+=(const T &card)
{
    this->addCard(card);
};

template <typename T>
Deck<T> &Deck<T>::operator<<(const T &card)
{
    addCard(card);

    return *this;
}

template <typename T>
T Deck<T>::ejectCard()
{
//    try
//    {
        if (this->vec.size() <= 0)
            throw EmptyDeckException();

        T ejectedCard = this->vec.back();
        this->vec.pop_back();

        return ejectedCard;
//    }
//    catch (EmptyDeckException &e)
//    {
//        std::cout << e.what() << std::endl;
//    }
}

template <typename T>
T Deck<T>::ejectCardIndex(int index)
{
//    try
//    {
        if (this->vec.size() <= 0)
            throw EmptyDeckException();

        T ejectedCard = this->vec[index];
        this->vec.erase(this->vec.begin() + index);

        return ejectedCard;
//    }
//    catch (EmptyDeckException &e)
//    {
//        std::cout << e.what() << std::endl;
//    }
}

template <typename T>
void Deck<T>::operator>>(Deck<T> &deck)
{
    deck.addCard(this->ejectCard());
}

// template <typename T>
// void Deck<T>::sort()
// {
//     std::sort(this->vec.begin(), this->vec.end(), [](T a, T b)
//               { return a.value() > b.value(); });
// }

template <typename T>
void Deck<T>::swap(Deck &other)
{
    std::swap(this->vec, other.vec);
};

template <class T>
void Deck<T>::swapDeck(Deck<T> &deck1, Deck<T> &deck2)
{
    std::swap(deck1.vec, deck2.vec);
};

template <typename T>
bool Deck<T>::operator<(const Deck<T> &other)
{
    // to avoid sorting the real deck
    //  we use pointer to retain derived Deck properties
    Deck<T> *a = new Deck(*this);
    Deck<T> *b = new Deck(other);

    a->sort();
    b->sort();

    for (int i = 0; i < a->getNumberOfCards(); i++)
    {
        if (a->getDeck()[i].value() < b->getDeck()[i].value())
        {
            delete a;
            delete b;

            return true;
        }
        else if (a->getDeck()[i].value() > b->getDeck()[i].value())
        {
            delete a;
            delete b;

            return false;
        }
    }

    //delete a;
    //delete b;

    return false;
}

template <typename T>
void Deck<T>::sort()
{
    sort(false);
}

template <typename T>
void Deck<T>::sort(bool descending)
{
    std::sort(this->vec.begin(), this->vec.end(), [descending](T a, T b) {
        bool result = a.value() < b.value();
        return descending ? !result : result;
    });
    // std::cout << "Exiting sort" << endl;
}

template <typename T>
bool Deck<T>::operator==(const Deck<T> &other)
{
    // to avoid sorting the real deck
    //  we use pointer to retain derived Deck properties
    Deck<T> *a = new Deck(*this);
    Deck<T> *b = new Deck(other);

    a->sort();
    b->sort();

    for (int i = 0; i < a->getNumberOfCards(); i++)
    {
        if (a->getDeck()[i].value() != b->getDeck()[i].value())
        {
            delete a;
            delete b;

            return false;
        }
    }

    delete a;
    delete b;

    return true;
}

template <typename T>
bool Deck<T>::operator>(const Deck<T> &other)
{
    // cout << "Entering > of deck" << endl;
    // to avoid sorting the real deck
    //  we use pointer to retain derived Deck properties
    Deck<T> *a = new Deck(*this);
    Deck<T> *b = new Deck(other);

    a->sort();
    b->sort();

    for (int i = 0; i < a->getNumberOfCards(); i++)
    {
        if (a->getDeck()[i].value() < b->getDeck()[i].value())
        {
            delete a;
            delete b;

            return false;
        }
        else if (a->getDeck()[i].value() > b->getDeck()[i].value())
        {
            delete a;
            delete b;

            return true;
        }
    }
    return false;
}

template <typename T>
Deck<T> &Deck<T>::operator+(Deck<T> &other)
{
    for (auto card : other.getDeck())
    {
        *this << card;
    }

    return *this;
}

template<typename T>
Deck<T> &Deck<T>::operator+(const T &card) {
    addCard(card);

    return *this;
}

template <typename T>
Deck<T> &Deck<T>::operator-(T &card) {
    card = ejectCard();

    return *this;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Deck<T> &deck)
{
    // os << "\nsize : " << deck.vec.size() << "\nmembers : \n";

    int i = 1;
    for (auto elmt : deck.vec)
    {
        os << i << ". " << elmt << endl;
        i++;
    }

    return os;
};

template class Deck<Card<int>>;
template class Deck<ColorCard>;
template class Deck<AbilityCard>;
template std::ostream &operator<<(std::ostream &os, const Deck<Card<int>> &deck);
template std::ostream &operator<<(std::ostream &os, const Deck<ColorCard> &deck);
template std::ostream &operator<<(std::ostream &os, const Deck<AbilityCard> &deck);