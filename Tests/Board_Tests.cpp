#include "doctest.h"
#include "../Board.hpp"

// Test that the board has been correctly initialized
TEST_CASE("Board initialization test") {
    Board board;

    // Check that the first square is a 'Go' square
    CHECK(std::holds_alternative<Go>(board.board[0]));

    // Check the first property is "Mediterranean Avenue"
    REQUIRE(std::holds_alternative<Street>(board.board[1]));
    const Street& medAve = std::get<Street>(board.board[1]);
    CHECK(medAve.getName() == "Mediterranean Avenue");
    CHECK(medAve.getColor() == Color::Brown);
    CHECK(medAve.getPurchasePrice() == 60);
    CHECK(medAve.getHouseCost() == 50);
    CHECK(medAve.getHotelCost() == 100);

    // Check that the third square is a Community Chest
    CHECK(std::holds_alternative<CommunityChestCard>(board.board[2]));

    // Check the railroad is "Reading Railroad"
    REQUIRE(std::holds_alternative<RailRoad>(board.board[5]));
    const RailRoad& readingRR = std::get<RailRoad>(board.board[5]);
    CHECK(readingRR.getName() == "Reading Railroad");

    // Check the utility is "Electric Company"
    REQUIRE(std::holds_alternative<Utility>(board.board[12]));
    const Utility& electricCompany = std::get<Utility>(board.board[12]);
    CHECK(electricCompany.getName() == "Electric Company");

    // Check that a jail square exists at the right position
    CHECK(std::holds_alternative<Jail>(board.board[10]));

    // Check that the "Boardwalk" street is correctly initialized
    REQUIRE(std::holds_alternative<Street>(board.board[39]));
    const Street& boardwalk = std::get<Street>(board.board[39]);
    CHECK(boardwalk.getName() == "Boardwalk");
    CHECK(boardwalk.getPurchasePrice() == 400);
    CHECK(boardwalk.getHotelCost() == 200);
}

// Test board square types
TEST_CASE("Verify each type of square on the board") {
    Board board;

    // Check various squares
    CHECK(std::holds_alternative<Go>(board.board[0]));
    CHECK(std::holds_alternative<Street>(board.board[1]));
    CHECK(std::holds_alternative<CommunityChestCard>(board.board[2]));
    CHECK(std::holds_alternative<IncomeTax>(board.board[4]));
    CHECK(std::holds_alternative<RailRoad>(board.board[5]));
    CHECK(std::holds_alternative<ChanceCard>(board.board[7]));
    CHECK(std::holds_alternative<Jail>(board.board[10]));
    CHECK(std::holds_alternative<Utility>(board.board[12]));
    CHECK(std::holds_alternative<FreeParking>(board.board[20]));
    CHECK(std::holds_alternative<GoToJail>(board.board[30]));
    CHECK(std::holds_alternative<LuxuryTax>(board.board[38]));
}

// Test street properties
TEST_CASE("Street properties correctness") {
    Board board;

    // Test "Park Place"
    REQUIRE(std::holds_alternative<Street>(board.board[37]));
    const Street& parkPlace = std::get<Street>(board.board[37]);
    CHECK(parkPlace.getName() == "Park Place");
    CHECK(parkPlace.getColor() == Color::DarkBlue);
    CHECK(parkPlace.getPurchasePrice() == 350);

    // Test "Boardwalk"
    REQUIRE(std::holds_alternative<Street>(board.board[39]));
    const Street& boardwalk = std::get<Street>(board.board[39]);
    CHECK(boardwalk.getName() == "Boardwalk");
    CHECK(boardwalk.getColor() == Color::DarkBlue);
    CHECK(boardwalk.getPurchasePrice() == 400);
}

// Test utility properties
TEST_CASE("Utility properties correctness") {
    Board board;

    // Test "Electric Company"
    REQUIRE(std::holds_alternative<Utility>(board.board[12]));
    const Utility& electricCompany = std::get<Utility>(board.board[12]);
    CHECK(electricCompany.getName() == "Electric Company");

    // Test "Water Works"
    REQUIRE(std::holds_alternative<Utility>(board.board[28]));
    const Utility& waterWorks = std::get<Utility>(board.board[28]);
    CHECK(waterWorks.getName() == "Water Works");
}

// Test railroad properties
TEST_CASE("Railroad properties correctness") {
    Board board;

    // Test "Reading Railroad"
    REQUIRE(std::holds_alternative<RailRoad>(board.board[5]));
    const RailRoad& readingRR = std::get<RailRoad>(board.board[5]);
    CHECK(readingRR.getName() == "Reading Railroad");

    // Test "B&O Railroad"
    REQUIRE(std::holds_alternative<RailRoad>(board.board[25]));
    const RailRoad& boRR = std::get<RailRoad>(board.board[25]);
    CHECK(boRR.getName() == "B&O Railroad");

    // Test "Short Line"
    REQUIRE(std::holds_alternative<RailRoad>(board.board[35]));
    const RailRoad& shortLineRR = std::get<RailRoad>(board.board[35]);
    CHECK(shortLineRR.getName() == "Short Line");
}