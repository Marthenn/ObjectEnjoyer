#ifndef _PLAYER_COLLECTION_HPP
#define _PLAYER_COLLECTION_HPP

#include <vector>
#include "../Player/Player.hpp"

template <typename T>
class PlayerCollection
{
protected:
    vector<T> players;

public:
    PlayerCollection();
    PlayerCollection(int numberOfPlayer);

    /**
     * @brief Construct a new Player Collection object
     *
     * @param pC
     */
    PlayerCollection(const PlayerCollection &pC);
    /**
     * @brief Return the number of player in this collection
     *
     */
    int getNumberOfPlayer();

    /**
     * @brief Add addedPlayer into the collection as the last player
     *
     * @param addedPlayer
     */
    virtual void operator<<(T &addedPlayer);

    /**
     * @brief Add addedPlayer into the collection as the last player
     *
     * @param addedPlayer
     */
    virtual void addPlayer(T &addedPlayer);

    /**
     * @brief Create a player and add it to the collection
     *
     */
    virtual void createAndAddPlayer(int id) = 0;

    /**
     * @brief Remove a player from the collection
     *
     * @param index starts at one
     */
    virtual void remove(int index);

    /**
     * @brief Remove a player from the collection
     *
     * @param index starts at one
     */

    void operator-=(int index);
};

#endif