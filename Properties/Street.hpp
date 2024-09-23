#ifndef STREET_HPP
#define STREET_HPP

#include <string>
#include <memory>
#include "../Player/Player.hpp"
#include "Color.hpp"
class Player;

class Street {
public:
    std::string name;            // Property name
    Color color;                 // Color group (e.g., Brown, Light Blue, etc.)
    int purchasePrice;           // Property's purchase price
    int mortgageValue;           // Mortgage value
    int rentWithoutFullGroup;    // Rent if the player doesn't own the full color group
    int rentWithFullGroup;       // Rent if the player owns the full color group
    int rentWith1House;          // Rent with 1 house
    int rentWith2House;          // Rent with 2 houses
    int rentWith3House;          // Rent with 3 houses
    int rentWith4House;          // Rent with 4 houses
    int rentWithHotels;          // Rent with a hotel
    int houseCost;               // Cost of building a house
    int hotelCost;               // Cost of building a hotel

    int numberOfHouses;          // Number of houses on the property
    bool hasHotel;               // True if the property has a hotel
    Player* owner;               // Current owner of the street

public:
    // Default constructor
    Street() : name(""), color(Color::Brown), purchasePrice(0), mortgageValue(0),
        rentWithoutFullGroup(0), rentWithFullGroup(0), rentWith1House(0), rentWith2House(0),
        rentWith3House(0), rentWith4House(0), rentWithHotels(0), houseCost(0), hotelCost(0),
        numberOfHouses(0), hasHotel(false), owner(nullptr) {}

    // Constructor with parameters
    Street(std::string name, Color color, int purchasePrice, int mortgageValue, int rentWithoutFullGroup,
           int rentWithFullGroup, int rentWith1House, int rentWith2House, int rentWith3House,
           int rentWith4House, int rentWithHotels, int houseCost, int hotelCost)
      : name(name), color(color), purchasePrice(purchasePrice), mortgageValue(mortgageValue),
        rentWithoutFullGroup(rentWithoutFullGroup), rentWithFullGroup(rentWithFullGroup),
        rentWith1House(rentWith1House), rentWith2House(rentWith2House), rentWith3House(rentWith3House),
        rentWith4House(rentWith4House), rentWithHotels(rentWithHotels), houseCost(houseCost),
        hotelCost(hotelCost), numberOfHouses(0), hasHotel(false), owner(nullptr) {}

    // Getters
    std::string getName() const { return name; }
    Color getColor() const { return color; }
    int getPurchasePrice() const { return purchasePrice; }
    int getNumberOfHouses() const { return numberOfHouses; }
    bool getHasHotel() const { return hasHotel; }
    int getHouseCost() const { return houseCost; }
    int getHotelCost() const { return hotelCost; }
    Player* getOwner() const { return owner; }

    // Setters
    void setOwner(Player* newOwner) { owner = newOwner; }

    // Calculate Rent based on property state (no houses, houses, or hotel)
    int getRent() const {
        if (this->owner == nullptr) return 0;
        if (hasHotel) { return rentWithHotels; }
        else {
            switch (numberOfHouses) {
                case 4: return rentWith4House;
                case 3: return rentWith3House;
                case 2: return rentWith2House;
                case 1: return rentWith1House;
                case 0: return this->owner->ownsFullColorGroup(this->color) ? rentWithFullGroup : rentWithoutFullGroup;
            }
        }
        return 0;
    }

    // Build a house (if the property does not already have a hotel or max houses)
    bool buildHouse() {
        // Check if the player owns the full color group
        if (this->owner->ownsFullColorGroup(this->color)) {
            // Check if the number of houses is less than 4
            if (numberOfHouses < 4 && !hasHotel) {
                numberOfHouses++;
                std::cout << "House built on " << this->name << ". Number of houses: " << numberOfHouses << std::endl;
                return true;
            } else {
                std::cout << "You can't add more houses. Maximum number of houses reached or hotel already built." << std::endl;
                return false;
            }
        } else {
            std::cout << "You must own all properties of this color group before building houses." << std::endl;
            return false;
        }
    }

    // Build a hotel (if there are 4 houses)
    bool buildHotel() {
        // Check if the player owns the full color group
        if (this->owner->ownsFullColorGroup(this->color)) {
            // Check if there are 4 houses and no hotel already built
            if (numberOfHouses == 4 && !hasHotel) {
                hasHotel = true;      // Build the hotel
                numberOfHouses = 0;   // Replace the 4 houses with a hotel
                std::cout << "Hotel built on " << this->name << std::endl;
                return true;
            } else if (hasHotel) {
                std::cout << "A hotel is already built on " << this->name << std::endl;
                return false;
            } else {
                std::cout << "You must have 4 houses on " << this->name << " to build a hotel." << std::endl;
                return false;
            }
        } else {
            std::cout << "You must own all properties of this color group before building a hotel." << std::endl;
            return false;
        }
    }

    // Reset property (used, for example, when starting a new game)
    void reset() {
        numberOfHouses = 0;  // Reset the number of houses to 0
        hasHotel = false;    // Remove the hotel if there was one
        owner = nullptr;     // Reset the owner (no owner)
        std::cout << "The property " << name << " has been reset." << std::endl;
    }
};

#endif // STREET_HPP