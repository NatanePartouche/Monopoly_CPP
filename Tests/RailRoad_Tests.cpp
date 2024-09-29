#include "doctest.h"
#include "../Properties/RailRoad.hpp"
#include "../Player/Player.hpp"

// Test that the initial state of the railroad is correct
TEST_CASE("RailRoad initial state") {
    RailRoad railroad("Reading Railroad");

    CHECK(railroad.getName() == "Reading Railroad");  // Name should be correct
    CHECK(railroad.getPurchasePrice() == 200);  // Purchase price should be $200
    CHECK(railroad.getOwner() == nullptr);  // Initially, the railroad should have no owner
    CHECK(railroad.getRent() == 0);  // If no owner, rent should be 0
}

// Test setting the owner and verifying rent with different numbers of railroads
TEST_CASE("RailRoad ownership and rent calculation") {
    Player player("John");
    RailRoad railroad1("Reading Railroad");
    RailRoad railroad2("B&O Railroad");
    RailRoad railroad3("Pennsylvania Railroad");
    RailRoad railroad4("Short Line");

    // Initially, no railroads should have an owner
    CHECK(railroad1.getOwner() == nullptr);
    CHECK(railroad1.getRent() == 0);

    // Set the player as the owner of one railroad
    railroad1.setOwner(&player);
    player.addRailroadProperty(&railroad1);

    CHECK(railroad1.getOwner() == &player);
    CHECK(railroad1.getRent() == 25);  // Rent should be $25 with 1 railroad

    // Add a second railroad to the player
    railroad2.setOwner(&player);
    player.addRailroadProperty(&railroad2);

    CHECK(railroad1.getRent() == 50);  // Rent should be $50 with 2 railroads
    CHECK(railroad2.getRent() == 50);  // Rent should also be $50 for the second railroad

    // Add a third railroad to the player
    railroad3.setOwner(&player);
    player.addRailroadProperty(&railroad3);

    CHECK(railroad1.getRent() == 100);  // Rent should be $100 with 3 railroads
    CHECK(railroad3.getRent() == 100);  // Rent should also be $100 for the third railroad

    // Add a fourth railroad to the player
    railroad4.setOwner(&player);
    player.addRailroadProperty(&railroad4);

    CHECK(railroad1.getRent() == 200);  // Rent should be $200 with 4 railroads
    CHECK(railroad4.getRent() == 200);  // Rent should also be $200 for the fourth railroad
}

// Test that rent returns 0 when there is no owner
TEST_CASE("RailRoad rent with no owner") {
    RailRoad railroad("Reading Railroad");

    CHECK(railroad.getRent() == 0);  // No owner, rent should be 0
}

// Test resetting ownership
TEST_CASE("RailRoad reset ownership") {
    Player player("John");
    RailRoad railroad("Reading Railroad");

    railroad.setOwner(&player);
    player.addRailroadProperty(&railroad);

    CHECK(railroad.getOwner() == &player);  // Verify ownership is set correctly

    // Reset the ownership
    railroad.setOwner(nullptr);

    CHECK(railroad.getOwner() == nullptr);  // Owner should now be reset
    CHECK(railroad.getRent() == 0);  // Rent should be 0 when there is no owner
}