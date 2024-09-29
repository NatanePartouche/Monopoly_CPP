#ifndef CHANCECARD_HPP
#define CHANCECARD_HPP

#include <vector>
#include <functional>
#include "../Player/Player.hpp"


// Forward declaration of the Board class
class Board;

class ChanceCard {
public:
    Player &owner;  // Reference to the player who owns the card
    Board &board;   // Reference to the game board

    // Default constructor
    ChanceCard();

    // Constructor to initialize with a player and the game board
    ChanceCard(Player &owner, Board &board);

    // Draws a random chance card and executes the associated action
    void drawCard();

private:
    // Stores the list of actions available in the Chance card deck
    std::vector<std::function<void()>> actions;

    // Initializes the 16 official actions for the Chance cards
    void initActions(Player &owner, Board &board);
};

#endif