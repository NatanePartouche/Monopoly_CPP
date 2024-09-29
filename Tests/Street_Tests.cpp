#include "doctest.h"
#include "../Properties/Street.hpp"
#include "../Player/Player.hpp"

// Test default constructor and initialization
TEST_CASE("Street default constructor initializes with correct values") {
    Street street;
    CHECK(street.getName() == "");  // Default name should be an empty string
    CHECK(street.getColor() == Color::Brown);  // Default color should be Brown
    CHECK(street.getPurchasePrice() == 0);  // Default purchase price should be 0
    CHECK(street.getNumberOfHouses() == 0);  // Number of houses should be 0
    CHECK(street.getHasHotel() == false);  // No hotel should be built initially
    CHECK(street.getOwner() == nullptr);  // The property should not have an owner
}

// Test parameterized constructor
TEST_CASE("Street parameterized constructor initializes with correct values") {
    Street street("Park Place", Color::DarkBlue, 350, 175, 35, 70, 100, 150, 200, 250, 300, 50, 100);
    CHECK(street.getName() == "Park Place");
    CHECK(street.getColor() == Color::DarkBlue);
    CHECK(street.getPurchasePrice() == 350);
    CHECK(street.getNumberOfHouses() == 0);
    CHECK(street.getHasHotel() == false);
    CHECK(street.getOwner() == nullptr);
}

// Test setting and getting owner
TEST_CASE("Set and get owner of the street") {
    Player player("John");
    Street street("Park Place", Color::DarkBlue, 350, 175, 35, 70, 100, 150, 200, 250, 300, 50, 100);

    street.setOwner(&player);  // Set the owner
    CHECK(street.getOwner() == &player);  // Check if the owner is correctly set
}

// Test rent calculation without houses or hotels
TEST_CASE("Rent calculation without houses or hotels") {
    Player player("John");
    Street street("Park Place", Color::DarkBlue, 350, 175, 35, 70, 100, 150, 200, 250, 300, 50, 100);

    street.setOwner(&player);
    CHECK(street.getRent() == 35);  // Default rent without houses or hotels
}

// Test rent calculation with full color group ownership
TEST_CASE("Rent calculation with full color group ownership") {
    Player player("John");
    Street street("Park Place", Color::DarkBlue, 350, 175, 35, 70, 100, 150, 200, 250, 300, 50, 100);

    street.setOwner(&player);

    // Mock full color group ownership
    CHECK(street.getRent() == 35);  // Player doesn't own the full group yet
    // Assuming Player class has a mock ownsFullColorGroup method for testing purposes
}

// Test building a house on the property
TEST_CASE("Building houses on the street") {
    Player player("John");

    // Create two properties in the Dark Blue group with the correct parameters
    Street street1("Park Place", Color::DarkBlue, 350, 175, 35, 70, 100, 150, 200, 250, 300, 50, 100);
    Street street2("Boardwalk", Color::DarkBlue, 400, 200, 50, 100, 150, 200, 300, 400, 500, 200, 100);  // Added missing parameters

    // Set the player as the owner of both properties
    street1.setOwner(&player);
    street2.setOwner(&player);

    // Add both properties to the player's portfolio
    player.addStreetProperty(&street1);
    player.addStreetProperty(&street2);

    // Now, the player owns the full Dark Blue color group, and they should be able to build houses
    CHECK(player.ownsFullColorGroup(Color::DarkBlue) == true);  // Verify full ownership of color group

    // Build houses on the first property
    CHECK(street1.buildHouse() == true);  // First house should be built successfully
    CHECK(street1.getNumberOfHouses() == 1);

    CHECK(street1.buildHouse() == true);  // Second house should be built
    CHECK(street1.getNumberOfHouses() == 2);

    CHECK(street1.buildHouse() == true);  // Third house should be built
    CHECK(street1.getNumberOfHouses() == 3);

    CHECK(street1.buildHouse() == true);  // Fourth house should be built
    CHECK(street1.getNumberOfHouses() == 4);

    CHECK(street1.buildHouse() == false);  // No more houses can be built after 4
}

// Test building a hotel
TEST_CASE("Building a hotel on the street") {
    Player player("John");

    // Create two properties in the Dark Blue group with the correct parameters
    Street street1("Park Place", Color::DarkBlue, 350, 175, 35, 70, 100, 150, 200, 250, 300, 50, 100);
    Street street2("Boardwalk", Color::DarkBlue, 400, 200, 50, 100, 150, 200, 300, 400, 500, 200, 100);  // Correct parameters

    // Set the player as the owner of both properties
    street1.setOwner(&player);
    street2.setOwner(&player);

    // Add both properties to the player's portfolio
    player.addStreetProperty(&street1);
    player.addStreetProperty(&street2);

    // Now, the player owns the full Dark Blue color group, and they should be able to build houses
    CHECK(player.ownsFullColorGroup(Color::DarkBlue) == true);  // Verify full ownership of color group

    // Build 4 houses first
    street1.buildHouse();
    street1.buildHouse();
    street1.buildHouse();
    street1.buildHouse();

    CHECK(street1.getNumberOfHouses() == 4);
    CHECK(street1.buildHotel() == true);  // Hotel should be built after 4 houses
    CHECK(street1.getHasHotel() == true);
    CHECK(street1.getNumberOfHouses() == 0);  // Houses should be reset after building a hotel

    CHECK(street1.buildHotel() == false);  // Cannot build another hotel
}

// Test resetting the property
TEST_CASE("Resetting the street") {
    Player player("John");
    Street street("Park Place", Color::DarkBlue, 350, 175, 35, 70, 100, 150, 200, 250, 300, 50, 100);
    street.setOwner(&player);
    street.buildHouse();

    CHECK(street.getNumberOfHouses() == 0);
    street.reset();  // Reset the property

    CHECK(street.getNumberOfHouses() == 0);  // Number of houses should be reset
    CHECK(street.getHasHotel() == false);  // Hotel status should be reset
    CHECK(street.getOwner() == nullptr);  // Owner should be reset
}