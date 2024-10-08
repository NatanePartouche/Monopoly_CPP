#ifndef BOARD_HPP
#define BOARD_HPP

#include <variant>
#include <vector>
#include "Properties/Street.hpp"
#include "Properties/RailRoad.hpp"
#include "Properties/Utility.hpp"
#include "SpecialSquare/CommunityChestCard.hpp"
#include "SpecialSquare/ChanceCard.hpp"
#include "SpecialSquare/Go.hpp"
#include "SpecialSquare/GoToJail.hpp"
#include "SpecialSquare/LuxuryTax.hpp"
#include "SpecialSquare/Jail.hpp"
#include "SpecialSquare/IncomeTax.hpp"
#include "SpecialSquare/FreeParking.hpp"

// The Board class represents the Monopoly game board.
class Board {
public:
    // Define a variant type (MapBoard) that can hold any square type
    using MapBoard = std::variant<
        Street,
        Utility,
        RailRoad,
        ChanceCard,
        CommunityChestCard,
        Go,
        GoToJail,
        LuxuryTax,
        Jail,
        IncomeTax,
        FreeParking
    >;

    // A vector to store the 40 squares on the Monopoly board
    std::vector<MapBoard> board;

    // Constructor to initialize the board with 40 squares
    Board() {
        // Resize the vector to 40 squares
        board.resize(40);

        // Initialize each square on the board using `emplace`
        board[0].emplace<Go>();
        board[1].emplace<Street>("Mediterranean Avenue", Color::Brown, 60, 30, 5, 10, 20, 40, 80, 160, 320, 50, 100);
        board[2].emplace<CommunityChestCard>();
        board[3].emplace<Street>("Baltic Avenue", Color::Brown, 60, 30, 5, 10, 20, 40, 80, 160, 320, 50, 100);
        board[4].emplace<IncomeTax>();
        board[5].emplace<RailRoad>("Reading Railroad");
        board[6].emplace<Street>("Oriental Avenue", Color::LightBlue, 100, 50, 6, 12, 30, 90, 270, 400, 550, 50, 50);
        board[7].emplace<ChanceCard>();
        board[8].emplace<Street>("Vermont Avenue", Color::LightBlue, 100, 50, 6, 12, 30, 90, 270, 400, 550, 50, 50);
        board[9].emplace<Street>("Connecticut Avenue", Color::LightBlue, 120, 60, 8, 16, 40, 100, 300, 450, 600, 50, 50);
        board[10].emplace<Jail>();  // Jail square
        board[11].emplace<Street>("St. Charles Place", Color::Pink, 140, 70, 10, 20, 50, 150, 450, 625, 750, 100, 100);
        board[12].emplace<Utility>("Electric Company");
        board[13].emplace<Street>("States Avenue", Color::Pink, 140, 70, 10, 20, 50, 150, 450, 625, 750, 100, 100);
        board[14].emplace<Street>("Virginia Avenue", Color::Pink, 160, 80, 12, 24, 60, 180, 500, 700, 900, 100, 100);
        board[15].emplace<RailRoad>("Pennsylvania Railroad");
        board[16].emplace<Street>("St. James Place", Color::Orange, 180, 90, 14, 28, 70, 200, 550, 750, 950, 100, 100);
        board[17].emplace<CommunityChestCard>();
        board[18].emplace<Street>("Tennessee Avenue", Color::Orange, 180, 90, 14, 28, 70, 200, 550, 750, 950, 100, 100);
        board[19].emplace<Street>("New York Avenue", Color::Orange, 200, 100, 16, 32, 80, 220, 600, 800, 1000, 100, 100);
        board[20].emplace<FreeParking>();  // Free Parking square
        board[21].emplace<Street>("Kentucky Avenue", Color::Red, 220, 110, 18, 36, 90, 250, 700, 875, 1050, 150, 150);
        board[22].emplace<ChanceCard>();
        board[23].emplace<Street>("Indiana Avenue", Color::Red, 220, 110, 18, 36, 90, 250, 700, 875, 1050, 150, 150);
        board[24].emplace<Street>("Illinois Avenue", Color::Red, 240, 120, 20, 40, 100, 300, 750, 925, 1100, 150, 150);
        board[25].emplace<RailRoad>("B&O Railroad");
        board[26].emplace<Street>("Atlantic Avenue", Color::Yellow, 260, 130, 22, 44, 110, 330, 800, 975, 1150, 150, 150);
        board[27].emplace<Street>("Ventnor Avenue", Color::Yellow, 260, 130, 22, 44, 110, 330, 800, 975, 1150, 150, 150);
        board[28].emplace<Utility>("Water Works");
        board[29].emplace<Street>("Marvin Gardens", Color::Yellow, 280, 140, 24, 48, 120, 360, 850, 1025, 1200, 150, 150);
        board[30].emplace<GoToJail>();  // Go to Jail square
        board[31].emplace<Street>("Pacific Avenue", Color::Green, 300, 150, 26, 52, 130, 390, 900, 1100, 1275, 200, 200);
        board[32].emplace<Street>("North Carolina Avenue", Color::Green, 300, 150, 26, 52, 130, 390, 900, 1100, 1275, 200, 200);
        board[33].emplace<CommunityChestCard>();
        board[34].emplace<Street>("Pennsylvania Avenue", Color::Green, 320, 160, 28, 56, 150, 450, 1000, 1200, 1400, 200, 200);
        board[35].emplace<RailRoad>("Short Line");
        board[36].emplace<ChanceCard>();
        board[37].emplace<Street>("Park Place", Color::DarkBlue, 350, 175, 35, 70, 175, 500, 1100, 1300, 1500, 200, 200);
        board[38].emplace<LuxuryTax>();
        board[39].emplace<Street>("Boardwalk", Color::DarkBlue, 400, 200, 50, 100, 200, 600, 1400, 1700, 2000, 200, 200);
    }

    // Handle the logic of a player's turn when they land on a square
    static void handlePlayerTurn(Board& board, Player& player) {
        // Get the player's current position on the board
        int playerPosition = player.getPosition();

        // Get the square the player landed on
        auto& square = board.board[playerPosition];

        // Use std::visit to handle the specific square type
        std::visit([&board, &player](auto&& obj) {
            using T = std::decay_t<decltype(obj)>;

            // Handle Street squares
            if constexpr (std::is_same_v<T, Street>) {
                auto& street = std::get<Street>(board.board[player.getPosition()]);
                if (street.getOwner() == nullptr) {
                    // If the street has no owner, offer the player the option to buy it
                    char choice;
                    bool validChoice = false;
                    while (!validChoice) {
                        std::cout << "The street " << street.getName()
                                  << " has no owner. \nDo you want to buy it for "
                                  << street.getPurchasePrice() << "M$ (y/n)? " << std::endl;
                        std::cin >> choice;
                        if (choice == 'y' || choice == 'Y') {
                            validChoice = true;
                            player.removeMoney(street.getPurchasePrice());
                            street.setOwner(&player);
                            player.addStreetProperty(&street);
                            std::cout << "You are now the owner of " << street.getName() << "!" << std::endl;
                        } else if (choice == 'n' || choice == 'N') {
                            validChoice = true;
                        } else {
                            std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << std::endl;
                        }
                    }
                } else {
                    // If the street is owned, the player must pay rent
                    std::cout << "This street already has an owner: " << street.getOwner()->getName() << std::endl;
                    std::cout << "\nThe rent is: " << street.getRent() << "M$" << std::endl;
                    player.removeMoney(street.getRent());
                    street.getOwner()->addMoney(street.getRent());
                }
            }
            // Handle RailRoad squares
            else if constexpr (std::is_same_v<T, RailRoad>) {
                auto& railroad = std::get<RailRoad>(board.board[player.getPosition()]);
                if (railroad.getOwner() == nullptr) {
                    char choice;
                    bool validChoice = false;
                    while (!validChoice) {
                        std::cout << "This Railroad " << railroad.getName()
                                  << " has no owner. \nDo you want to buy it for "
                                  << railroad.getPurchasePrice() << "M$ (y/n)? " << std::endl;
                        std::cin >> choice;
                        if (choice == 'y' || choice == 'Y') {
                            validChoice = true;
                            player.removeMoney(railroad.getPurchasePrice());
                            railroad.setOwner(&player);
                            player.addRailroadProperty(&railroad);
                            std::cout << "You are now the owner of the railroad: " << railroad.getName() << "!" << std::endl;
                        } else if (choice == 'n' || choice == 'N') {
                            validChoice = true;
                        } else {
                            std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << std::endl;
                        }
                    }
                } else {
                    std::cout << "This railroad already has an owner: " << railroad.getOwner()->getName() << std::endl;
                    std::cout << "\nThe rent is: " << railroad.getRent() << "M$" << std::endl;
                    player.removeMoney(railroad.getRent());
                    railroad.getOwner()->addMoney(railroad.getRent());
                }
            }
            // Handle Utility squares
            else if constexpr (std::is_same_v<T, Utility>) {
                auto& utility = std::get<Utility>(board.board[player.getPosition()]);
                if (utility.getOwner() == nullptr) {
                    char choice;
                    bool validChoice = false;
                    while (!validChoice) {
                        std::cout << "This Utility " << utility.getName()
                                  << " has no owner. \nDo you want to buy it for "
                                  << utility.getPurchasePrice() << "M$ (y/n)? " << std::endl;
                        std::cin >> choice;
                        if (choice == 'y' || choice == 'Y') {
                            validChoice = true;
                            player.removeMoney(utility.getPurchasePrice());
                            utility.setOwner(&player);
                            player.addUtilityProperty(&utility);
                            std::cout << "You are now the owner of the utility: " << utility.getName() << "!" << std::endl;
                        } else if (choice == 'n' || choice == 'N') {
                            validChoice = true;
                        } else {
                            std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << std::endl;
                        }
                    }
                } else {
                    std::cout << "This utility already has an owner: " << utility.getOwner()->getName() << std::endl;
                    std::cout << "Roll the dice to determine the rent..." << std::endl;
                    int rent = utility.getRent();
                    std::cout << "The rent is: " << rent << "M$" << std::endl;
                    player.removeMoney(rent);
                    utility.getOwner()->addMoney(rent);
                }
            }
            // Handle ChanceCard squares
            else if constexpr (std::is_same_v<T, ChanceCard>) {
                // Assuming the player lands on a Chance square
                std::cout << "You are on a Chance square. Drawing a card..." << std::endl;
                // Simulate drawing a Chance card and executing its action
                ChanceCard chanceCard(player, board);  // `owner` is the player, and `board` is the game board
                chanceCard.drawCard();  // This will randomly pick and execute a Chance card action
            }
            // Handle CommunityChestCard squares
            else if constexpr (std::is_same_v<T, CommunityChestCard>) {
                // Assuming the player lands on a Community Chest square
                std::cout << "You are on a Community Chest square. Drawing a card..." << std::endl;
                // Simulate drawing a Community Chest card and executing its action
                CommunityChestCard communityChestCard(player, board);  // `owner` is the player, and `board` is the game board
                communityChestCard.drawCard();  // This will randomly pick and execute a Community Chest card action
            }
            // Handle Go square (no action needed)
            else if constexpr (std::is_same_v<T, Go>) {
                std::cout << "You have landed on Go! Collect 200M$ as you pass." << std::endl;
            }
            // Handle GoToJail square
            else if constexpr (std::is_same_v<T, GoToJail>) {
                player.setPosition(10);  // Move player to Jail
                player.setInJail(true);  // Set player to "in jail" status
            }
            // Handle LuxuryTax square
            else if constexpr (std::is_same_v<T, LuxuryTax>) {
                std::cout << player.getName() << " has landed on the Luxury Tax square. You must pay 100M$!" << std::endl;
                player.removeMoney(100);  // Pay the luxury tax
            }
            // Handle Jail square (no action needed)
            else if constexpr (std::is_same_v<T, Jail>) {
                if (!player.isInJail()) {
                    std::cout << "You are on the 'Just Visiting' space of the jail." << std::endl;
                } else {
                    std::cout << "You are currently in jail." << std::endl;
                }
            }
            // Handle IncomeTax square
            else if constexpr (std::is_same_v<T, IncomeTax>) {
                std::cout << player.getName() << " has landed on the Income Tax square. You must pay 200M$!" << std::endl;
                player.removeMoney(200);  // Pay the income tax
            }
            // Handle FreeParking square (no action needed)
            else if constexpr (std::is_same_v<T, FreeParking>) {
                std::cout << "You are on the Free Parking space. Enjoy a break!" << std::endl;
            }
        }, square);
    }
};

#endif // BOARD_HPP