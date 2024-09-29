#ifndef COMMUNITYCHESTCARD_HPP
#define COMMUNITYCHESTCARD_HPP

#include <vector>
#include <functional>
#include "../Player/Player.hpp"


// Forward declaration of the Board class
class Board;

class CommunityChestCard {
public:
    Player &owner;  // Reference to the player who owns the card
    Board &board;   // Reference to the game board

    // Default constructor
    CommunityChestCard();

    // Constructor to initialize with a player and the game board
    CommunityChestCard(Player &owner, Board &board);

    // Draws a random Community Chest card and executes the associated action
    void drawCard();

private:
    // Stores the list of actions available in the Community Chest card deck
    std::vector<std::function<void()>> actions;

    // Initializes the actions for the Community Chest cards
    void initActions(Player &owner, Board &board);
};

#endif