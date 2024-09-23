#ifndef RAILROAD_HPP
#define RAILROAD_HPP

#include <string>
#include "../Player/Player.hpp"

class RailRoad {
public:
    std::string name;             // Name of the railroad (e.g., "Reading Railroad")
    int purchasePrice = 200;      // Purchase price of the railroad
    Player* owner;                // Current owner of the railroad

    // Rent prices
    const int rent_with_1_RailRoad = 25;   // Rent if the player owns 1 railroad
    const int rent_with_2_RailRoads = 50;  // Rent if the player owns 2 railroads
    const int rent_with_3_RailRoads = 100; // Rent if the player owns 3 railroads
    const int rent_with_4_RailRoads = 200; // Rent if the player owns 4 railroads


    // Constructor
    RailRoad(std::string name) : name(name), owner(nullptr) {}

    // Getters
    std::string getName() const { return name; }
    int getPurchasePrice() const { return purchasePrice; }
    Player* getOwner() const { return owner; }

    // Setters
    void setOwner(Player* newOwner) { owner = newOwner; }

    // Rent calculation based on the number of railroads owned by the player
    int getRent() const {
        if (this->owner == nullptr) return 0;  // No owner, no rent
        int railroadsOwned = owner->getRailroadProperties().size();  // Number of railroads owned by the player
        switch (railroadsOwned) {
            case 1: return rent_with_1_RailRoad;
            case 2: return rent_with_2_RailRoads;
            case 3: return rent_with_3_RailRoads;
            case 4: return rent_with_4_RailRoads;
            default: return 0;
        }
    }

    // Reset the railroad (used, for example, when starting a new game)
    void reset() {owner = nullptr;}

};
#endif // RAILROAD_HPP