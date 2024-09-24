#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include "../Player/Player.hpp"
#include "../Dice.hpp"

class Utility {
private:
    std::string name;             // Name of the utility (e.g., "Water Works", "Electric Company")
    int purchasePrice = 150;      // Purchase price of the utility
    int mortgageValue = 75;       // Mortgage value of the utility
    Player* owner;                // Current owner of the utility

public:
    // Constructor
    Utility(std::string name) : name(name){}

    // Getters
    std::string getName() const { return name; }
    int getPurchasePrice() const { return purchasePrice; }
    Player* getOwner() const { return owner; }

    // Setters
    void setOwner(Player* newOwner) { owner = newOwner; }

    // Calculate the rent based on the number of utilities owned
    int getRent() const {
        if (this->owner == nullptr) return 0;
        Dice dice;  // Create a local instance of Dice
        int rollResult = dice.roll();  // Get the result of the dice roll
        if (owner->getUtilityProperties().size() == 1) {
            return rollResult * 4;  // Rent if the owner owns 1 utility
        }
        else if (owner->getUtilityProperties().size() == 2) {
            return rollResult * 10;  // Rent if the owner owns 2 utilities
        }
            return 0;
    }
};

#endif // UTILITY_HPP