#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Token.hpp"
#include "Color.hpp"
#include <limits>
#include <algorithm>

// Forward declaration of classes to avoid circular dependencies
class Street;
class RailRoad;
class Utility;

class Player {
private:
    std::string name;                    // The player's name
    Token token;                         // The player's token (representing their game piece)
    int position{0};                     // The player's current position on the board (0-39 positions in Monopoly)
    int moneyWallet{1500};               // The player's initial balance (Monopoly standard start amount)
    bool inJail{false};                  // Flag indicating if the player is in jail
    int boardTurns{0};                   // Number of turns the player has taken
    bool card_get_out_of_jail{false};    // Flag for having a 'Get Out of Jail Free' card
    int JailTurns{0};                    // Number of turns the player has been in jail

    // Use of pointers to avoid circular dependencies for properties
    std::vector<Street*> streetProperties;       // List of owned street properties
    std::vector<RailRoad*> railroadProperties;   // List of owned railroads
    std::vector<Utility*> utilityProperties;     // List of owned utilities

public:
    // Constructor: Initialize the player with a name and token
    Player(const std::string& playerName);

    // Destructor (defaulted as no special cleanup needed)
    ~Player() = default;

    // Getters: Provide access to private member variables
    std::string getName() const;                 // Get player's name
    std::string getToken() const;                // Get player's token
    int getBalance() const;                      // Get player's current balance
    int getPosition() const;                     // Get player's position on the board
    bool isInJail() const;                       // Check if player is in jail
    int getJailTurns() const;                    // Get how many turns the player has been in jail
    bool getCard_out_of_jail() const;            // Check if player has a 'Get Out of Jail Free' card
    int getBoardTurns() const;                   // Get the number of turns the player has taken
    std::vector<Street*> getStreetProperties() const;     // Get list of owned street properties
    std::vector<RailRoad*> getRailroadProperties() const; // Get list of owned railroads
    std::vector<Utility*> getUtilityProperties() const;   // Get list of owned utilities

    // Setters: Modify private member variables
    void setName(const std::string& newName);                  // Set player's name
    void setToken(const Token& newToken);                      // Set player's token
    void setBalance(int newBalance);                           // Set player's balance
    void setPosition(int newPosition);                         // Set player's board position
    void setInJail(bool jailStatus);                           // Set player's jail status
    void setJailTurns(int turns);                              // Set how many turns the player has been in jail
    void setBoardTurns(int turns);                             // Set the number of board turns
    void setStreetProperties(const std::vector<Street*>& streets);      // Set the player's street properties
    void setRailroadProperties(const std::vector<RailRoad*>& railroads);// Set the player's railroads
    void setUtilityProperties(const std::vector<Utility*>& utilities);  // Set the player's utilities
    void setCard_out_of_jail(bool jailStatus);                 // Set the 'Get Out of Jail Free' card status

    // Functions related to money management
    void addMoney(int amount);            // Add money to player's balance
    bool removeMoney(int amount);         // Deduct money from player's balance

    // Check if the player owns all properties of a specific color group
    bool ownsFullColorGroup(Color color); // Check if the player owns an entire color group

    // Display the player's current status (name, balance, properties, etc.)
    void display() const;

    // Static function to retrieve available tokens as a string
    static std::string getAvailableTokensAsString(const std::vector<Player>& players);

    // Function to select a token for the player
    static void choosePlayerToken(Player& currentPlayer, const std::vector<Player>& players_vector);

    // Add a street property to the player's portfolio
    void addStreetProperty(Street* street);

    // Add a railroad property to the player's portfolio
    void addRailroadProperty(RailRoad* railroad);

    // Add a utility property to the player's portfolio
    void addUtilityProperty(Utility* utility);

    // Static function to check player balances and remove players with negative balance
    static bool checkPlayerBalances(std::vector<Player>& players);

    // Function to manage player properties (e.g., build houses or hotels)
    void manageProperties();

    // Handle the logic of attempting to release the player from jail
    void attemptToReleaseFromJail();
};

#endif // PLAYER_HPP