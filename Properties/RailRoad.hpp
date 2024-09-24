#ifndef RAILROAD_HPP
#define RAILROAD_HPP

#include <string>
#include "../Player/Player.hpp"

// The RailRoad class represents a railroad property in the Monopoly game
class RailRoad {
public:
    std::string name;             // Name of the railroad (e.g., "Reading Railroad")
    int purchasePrice = 200;      // Purchase price of the railroad
    Player* owner;                // Current owner of the railroad, nullptr if unowned

    // Rent prices based on the number of railroads owned by the player
    const int rent_with_1_RailRoad = 25;   // Rent if the player owns 1 railroad
    const int rent_with_2_RailRoads = 50;  // Rent if the player owns 2 railroads
    const int rent_with_3_RailRoads = 100; // Rent if the player owns 3 railroads
    const int rent_with_4_RailRoads = 200; // Rent if the player owns 4 railroads

    // Constructor to initialize the railroad with its name and no owner
    RailRoad(std::string name) : name(name), owner(nullptr) {}

    // Getters for railroad attributes

    // Returns the name of the railroad
    std::string getName() const { return name; }

    // Returns the purchase price of the railroad (always $200)
    int getPurchasePrice() const { return purchasePrice; }

    // Returns the current owner of the railroad (a Player pointer)
    Player* getOwner() const { return owner; }

    // Setter for the owner of the railroad

    // Sets the new owner of the railroad to the player passed as argument
    void setOwner(Player* newOwner) { owner = newOwner; }

    // Calculates the rent based on the number of railroads owned by the current owner
    int getRent() const {
        // If the railroad has no owner, rent is 0 (cannot charge rent)
        if (this->owner == nullptr) return 0;

        // Get the number of railroads owned by the player (using Player's method)
        int railroadsOwned = owner->getRailroadProperties().size();

        // Return rent based on the number of railroads owned
        switch (railroadsOwned) {
            case 1: return rent_with_1_RailRoad;      // If player owns 1 railroad, rent is $25
            case 2: return rent_with_2_RailRoads;     // If player owns 2 railroads, rent is $50
            case 3: return rent_with_3_RailRoads;     // If player owns 3 railroads, rent is $100
            case 4: return rent_with_4_RailRoads;     // If player owns 4 railroads, rent is $200
            default: return 0;                        // Should not happen, but return 0 by default
        }
    }
};

#endif // RAILROAD_HPP