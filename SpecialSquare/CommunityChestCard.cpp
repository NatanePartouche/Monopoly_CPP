#include "CommunityChestCard.hpp"
#include "../Board.hpp"
#include "../Properties/Street.hpp"
#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>   // for srand()

// Temporary "dummy" objects to initialize references
Player dummyPlayer1;
Board dummyBoard1;

// Default constructor that initializes with "dummy" references
CommunityChestCard::CommunityChestCard()
    : owner(dummyPlayer1), board(dummyBoard1) {}

// Constructor that initializes with actual player and board references
CommunityChestCard::CommunityChestCard(Player &owner, Board &board)
    : owner(owner), board(board) {
    // Initialize the actions when the object is created
    initActions(owner, board);
    // Initialize the random number generator
    std::srand(std::time(nullptr));
}

// Initialize all the actions related to the Community Chest cards
void CommunityChestCard::initActions(Player &owner, Board &board) {
    // Advance to Go action
    actions.push_back([&owner]() {
        std::cout << "Advance to Go (Collect $200)" << std::endl;
        owner.setPosition(0);  // Move the player to Go
        owner.addMoney(200);   // Give the player $200
    });

    // Bank pays $50 dividend action
    actions.push_back([&owner]() {
        std::cout << "Bank pays you dividend of $50" << std::endl;
        owner.addMoney(50);  // Add $50 to the player's balance
    });

    // Go back 3 spaces action
    actions.push_back([&owner, &board]() {
        std::cout << "Go back 3 spaces" << std::endl;
        owner.setPosition(owner.getPosition() - 3);  // Move the player back 3 spaces
        // Call the handlePlayerTurn function
        Board::handlePlayerTurn(board, owner);  // Correct call of static function
    });

    // Go to Jail action
    actions.push_back([&owner]() {
        std::cout << "Go directly to Jail – do not pass Go, do not collect $200" << std::endl;
        owner.setPosition(10);  // Assuming 10 is the position for Jail
        owner.setInJail(true);  // Assuming `setInJail` is a method of Player
    });

    // Repairs on properties action
    actions.push_back([&owner]() {
        std::cout << "Make general repairs on all your property – For each house pay $25 – For each hotel $100" << std::endl;
        int taxHotel = 0;  // Counter for the number of hotels
        int taxHouse = 0;  // Counter for the number of houses
        for (Street* street : owner.getStreetProperties()) {
            taxHouse += street->getNumberOfHouses();  // Add the number of houses for this property
            if (street->getHasHotel()) {
                taxHotel++;  // Increment if the property has a hotel
            }
        }
        int totalCost = (taxHouse * 25) + (taxHotel * 100);  // $25 per house, $100 per hotel
        std::cout << "You must pay $" << totalCost << " for repairs on your properties." << std::endl;
        owner.removeMoney(totalCost);  // Deduct the total cost from the player's money
    });

    // Pay poor tax action
    actions.push_back([&owner]() {
        std::cout << "Pay poor tax of $15" << std::endl;
        owner.removeMoney(15);  // Deduct $15 from the player's balance
    });

    // Trip to Reading Railroad action
    actions.push_back([&owner, &board]() {
        std::cout << "Take a trip to Reading Railroad – If you pass Go, collect $200" << std::endl;
        if (owner.getPosition() >= 5) {
            owner.addMoney(200);  // Collect $200 if they pass Go
        }
        owner.setPosition(5);  // Move the player to Reading Railroad
        Board::handlePlayerTurn(board, owner);  // Correct call of static function
    });

    // Walk on the Boardwalk action
    actions.push_back([&owner, &board]() {
        std::cout << "Take a walk on the Boardwalk – Advance token to Boardwalk" << std::endl;
        owner.setPosition(39);  // Move the player to Boardwalk
        Board::handlePlayerTurn(board, owner);  // Correct call of static function
    });

    // Elected Chairman of the Board action
    actions.push_back([&owner]() {
        std::cout << "You have been elected Chairman of the Board – Pay each player $50" << std::endl;
        // Logic for paying each player $50
    });

    // Building loan matures action
    actions.push_back([&owner]() {
        std::cout << "Your building loan matures – Collect $150" << std::endl;
        owner.addMoney(150);  // Add $150 to the player's balance
    });

    // Get out of Jail Free action
    actions.push_back([&owner]() {
        std::cout << "Get out of Jail Free – This card may be kept until needed or traded" << std::endl;
        owner.setCard_out_of_jail(true);  // Grant the player a Get Out of Jail Free card
    });

    // Advance to Illinois Ave. action
    actions.push_back([&owner, &board]() {
        std::cout << "Advance to Illinois Ave. – If you pass Go, collect $200" << std::endl;
        if (owner.getPosition() >= 24) {
            owner.addMoney(200);  // Collect $200 if they pass Go
        }
        owner.setPosition(24);  // Move the player to Illinois Ave.
        Board::handlePlayerTurn(board, owner);  // Correct call of static function
    });

    // Advance to St. Charles Place action
    actions.push_back([&owner, &board]() {
        std::cout << "Advance to St. Charles Place – If you pass Go, collect $200" << std::endl;
        if (owner.getPosition() >= 11) {
            owner.addMoney(200);  // Collect $200 if they pass Go
        }
        owner.setPosition(11);  // Move the player to St. Charles Place
        Board::handlePlayerTurn(board, owner);  // Correct call of static function
    });

    // Assessed for street repairs action
    actions.push_back([&owner]() {
        std::cout << "You are assessed for street repairs – $40 per house, $115 per hotel" << std::endl;
        int taxHotel = 0;
        int taxHouse = 0;
        for (Street* street : owner.getStreetProperties()) {
            taxHouse += street->getNumberOfHouses();
            if (street->getHasHotel()) {
                taxHotel++;
            }
        }
        int totalCost = (taxHouse * 40) + (taxHotel * 115);
        std::cout << "You must pay $" << totalCost << " for repairs on your properties." << std::endl;
        owner.removeMoney(totalCost);
    });

    // Advance to nearest Utility action
    actions.push_back([&owner, &board]() {
        std::cout << "Advance to the nearest Utility – If unowned you may buy it from the Bank. If owned, throw dice and pay the owner a total ten times the amount thrown." << std::endl;
        int currentPosition = owner.getPosition();
        int nearestUtility = (currentPosition < 12) ? 12 : (currentPosition < 28) ? 28 : 12;
        owner.setPosition(nearestUtility);
        Board::handlePlayerTurn(board, owner);
    });

    // Advance to nearest Railroad action
    actions.push_back([&owner, &board]() {
        std::cout << "Advance to the nearest Railroad – If unowned you may buy it from the Bank. If owned, pay rent." << std::endl;
        int currentPosition = owner.getPosition();
        int nearestRailroad = (currentPosition < 5) ? 5 : (currentPosition < 15) ? 15 : (currentPosition < 25) ? 25 : (currentPosition < 35) ? 35 : 5;
        owner.setPosition(nearestRailroad);
        Board::handlePlayerTurn(board, owner);
    });
}

// Draw a random Community Chest card and execute the associated action
void CommunityChestCard::drawCard() {
    int randomIndex = std::rand() % actions.size();  // Generate a random index
    actions[randomIndex]();  // Execute the corresponding action
}