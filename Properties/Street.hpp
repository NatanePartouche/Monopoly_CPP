#ifndef STREET_HPP
#define STREET_HPP

#include <string>
#include "../Player/Player.hpp"
#include "Color.hpp"
class Player;

// The Street class represents a type of property on the Monopoly board
class Street {
public:
    std::string name;            // Name of the street (e.g., "Park Place")
    Color color;                 // Color group of the street (e.g., Brown, Light Blue)
    int purchasePrice;           // The price to purchase the property
    int mortgageValue;           // The value of the mortgage for the property
    int rentWithoutFullGroup;    // Rent when the player does NOT own the full color group
    int rentWithFullGroup;       // Rent when the player owns all properties in the color group
    int rentWith1House;          // Rent when 1 house is built on the property
    int rentWith2House;          // Rent when 2 houses are built
    int rentWith3House;          // Rent when 3 houses are built
    int rentWith4House;          // Rent when 4 houses are built
    int rentWithHotels;          // Rent when a hotel is built
    int houseCost;               // Cost to build a house on this property
    int hotelCost;               // Cost to build a hotel

    int numberOfHouses;          // Number of houses currently built on the property
    bool hasHotel;               // Whether a hotel has been built on the property
    Player* owner;               // The current owner of the property, nullptr if unowned

public:
    // Default constructor initializes everything to default values
    Street() : name(""), color(Color::Brown), purchasePrice(0), mortgageValue(0),
        rentWithoutFullGroup(0), rentWithFullGroup(0), rentWith1House(0), rentWith2House(0),
        rentWith3House(0), rentWith4House(0), rentWithHotels(0), houseCost(0), hotelCost(0),
        numberOfHouses(0), hasHotel(false), owner(nullptr) {}

    // Constructor that initializes a Street object with specific values for each field
    Street(std::string name, Color color, int purchasePrice, int mortgageValue, int rentWithoutFullGroup,
           int rentWithFullGroup, int rentWith1House, int rentWith2House, int rentWith3House,
           int rentWith4House, int rentWithHotels, int houseCost, int hotelCost)
      : name(name), color(color), purchasePrice(purchasePrice), mortgageValue(mortgageValue),
        rentWithoutFullGroup(rentWithoutFullGroup), rentWithFullGroup(rentWithFullGroup),
        rentWith1House(rentWith1House), rentWith2House(rentWith2House), rentWith3House(rentWith3House),
        rentWith4House(rentWith4House), rentWithHotels(rentWithHotels), houseCost(houseCost),
        hotelCost(hotelCost), numberOfHouses(0), hasHotel(false), owner(nullptr) {}

    // Getters

    // Returns the name of the street
    std::string getName() const { return name; }

    // Returns the color group of the street
    Color getColor() const { return color; }

    // Returns the purchase price of the street
    int getPurchasePrice() const { return purchasePrice; }

    // Returns the number of houses on the street
    int getNumberOfHouses() const { return numberOfHouses; }

    // Returns whether there is a hotel on the street
    bool getHasHotel() const { return hasHotel; }

    // Returns the cost to build a house on the street
    int getHouseCost() const { return houseCost; }

    // Returns the cost to build a hotel on the street
    int getHotelCost() const { return hotelCost; }

    // Returns the current owner of the street
    Player* getOwner() const { return owner; }

    // Setters

    // Sets the owner of the street to the given Player
    void setOwner(Player* newOwner) { owner = newOwner; }

    // Calculates the rent based on the property state (number of houses or hotel)
    int getRent() const {
        // If the property has no owner, the rent is 0
        if (this->owner == nullptr) return 0;

        // If a hotel is built, return the hotel rent
        if (hasHotel) { return rentWithHotels; }
        else {
            // Return the rent based on the number of houses
            switch (numberOfHouses) {
                case 4: return rentWith4House;
                case 3: return rentWith3House;
                case 2: return rentWith2House;
                case 1: return rentWith1House;
                case 0:
                    // If no houses, check if the player owns the full color group
                    return this->owner->ownsFullColorGroup(this->color) ? rentWithFullGroup : rentWithoutFullGroup;
            }
        }
        return 0;
    }

    // Method to build a house if the property does not have the maximum number of houses or a hotel
    bool buildHouse() {
        // Check if the player owns all properties in the color group
        if (this->owner->ownsFullColorGroup(this->color)) {
            // Check if the property has fewer than 4 houses and no hotel
            if (numberOfHouses < 4 && !hasHotel) {
                numberOfHouses++;  // Increase the house count
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

    // Method to build a hotel if there are 4 houses on the property
    bool buildHotel() {
        // Check if the player owns the full color group
        if (this->owner->ownsFullColorGroup(this->color)) {
            // Check if there are 4 houses and no hotel built
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

    // Resets the property to its initial state (for example, at the start of a new game)
    void reset() {
        numberOfHouses = 0;  // Reset the number of houses to 0
        hasHotel = false;    // Remove the hotel if there was one
        owner = nullptr;     // Reset the owner to no owner
        std::cout << "The property " << name << " has been reset." << std::endl;
    }
};

#endif // STREET_HPP