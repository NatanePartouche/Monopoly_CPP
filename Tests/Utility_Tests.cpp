#include "doctest.h"
#include "../Properties/Utility.hpp"
#include "../Player/Player.hpp"

// Test the initial state of a Utility object
TEST_CASE("Utility initial state") {
    Utility utility("Water Works");

    CHECK(utility.getName() == "Water Works");  // Verify the name
    CHECK(utility.getPurchasePrice() == 150);  // Verify the purchase price
    CHECK(utility.getOwner() == nullptr);  // There should be no owner initially
    CHECK(utility.getRent() == 0);  // Rent should be 0 if there is no owner
}

// Test setting and getting the owner of a Utility
TEST_CASE("Utility ownership") {
    Player player("Alice");
    Utility utility("Electric Company");

    CHECK(utility.getOwner() == nullptr);  // Initially, there should be no owner
    utility.setOwner(&player);  // Set the owner to the player
    CHECK(utility.getOwner() == &player);  // Check that the owner is now set
}

// Test resetting the owner of the utility
TEST_CASE("Utility reset owner") {
    Player player("John");
    Utility utility("Electric Company");

    utility.setOwner(&player);
    player.addUtilityProperty(&utility);

    CHECK(utility.getOwner() == &player);  // Verify the owner

    // Reset the owner to nullptr
    utility.setOwner(nullptr);

    CHECK(utility.getOwner() == nullptr);  // Owner should be reset to no owner
    CHECK(utility.getRent() == 0);  // Rent should be 0 when there is no owner
}

// Test changing the owner of the utility
TEST_CASE("Change Utility owner") {
    Player player1("Alice");
    Player player2("Bob");
    Utility utility("Electric Company");

    utility.setOwner(&player1);  // Initially owned by Alice
    CHECK(utility.getOwner() == &player1);

    utility.setOwner(&player2);  // Change ownership to Bob
    CHECK(utility.getOwner() == &player2);  // Verify new ownership
}

// Test edge case: rent calculation without an owner
TEST_CASE("Utility rent calculation without owner") {
    Utility utility("Electric Company");

    CHECK(utility.getRent() == 0);  // Rent should be 0 if there is no owner
}