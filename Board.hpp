#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include "../Player/Player.hpp"
#include "Street.hpp"
#include "RailRoad.hpp"
#include "Utility.hpp"
#include "Card/CommunityChestCard.hpp"
#include "Card/ChanceCard.hpp"
#include "SpecialSquare/Go.hpp"
#include "SpecialSquare/GoToJail.hpp"
#include "SpecialSquare/LuxuryTax.hpp"
#include "SpecialSquare/Jail.hpp"
#include "SpecialSquare/IncomeTax.hpp"
#include "SpecialSquare/FreeParking.hpp"

class Board {
public:
    // Définir le conteneur variant pour contenir les différents types de cases
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

    // Créer un vector pour contenir les 40 objets de types différents
    std::vector<MapBoard> board;

    // Constructor
    Board() {
        // Redimensionner le vecteur pour contenir 40 éléments
        board.resize(40);

        // Initialiser les cases selon le plateau Monopoly avec emplace
        board[0].emplace<Go>();
        board[1].emplace<Street>("Mediterranean Avenue",Color::Brown, 60, 30, 2, 4, 10, 30, 90, 160, 250, 50, 50);
        board[2].emplace<CommunityChestCard>();
        board[3].emplace<Street>("Baltic Avenue",Color::Brown, 60, 30, 4, 8, 20, 60, 180, 320, 450, 50, 50);
        board[4].emplace<IncomeTax>();
        board[5].emplace<RailRoad>("Reading Railroad");
        board[6].emplace<Street>("Oriental Avenue",Color::LightBlue, 100, 50, 6, 12, 30, 90, 270, 400, 550, 50, 50);
        board[7].emplace<ChanceCard>();
        board[8].emplace<Street>("Vermont Avenue",Color::LightBlue, 100, 50, 6, 12, 30, 90, 270, 400, 550, 50, 50);
        board[9].emplace<Street>("Connecticut Avenue",Color::LightBlue, 120, 60, 8, 16, 40, 100, 300, 450, 600, 50, 50);
        board[10].emplace<Jail>();
        board[11].emplace<Street>("St. Charles Place",Color::Pink, 140, 70, 10, 20, 50, 150, 450, 625, 750, 100, 100);
        board[12].emplace<Utility>("Electric Company");
        board[13].emplace<Street>("States Avenue",Color::Pink, 140, 70, 10, 20, 50, 150, 450, 625, 750, 100, 100);
        board[14].emplace<Street>("Virginia Avenue",Color::Pink, 160, 80, 12, 24, 60, 180, 500, 700, 900, 100, 100);
        board[15].emplace<RailRoad>("Pennsylvania Railroad");
        board[16].emplace<Street>("St. James Place",Color::Orange, 180, 90, 14, 28, 70, 200, 550, 750, 950, 100, 100);
        board[17].emplace<CommunityChestCard>();
        board[18].emplace<Street>("Tennessee Avenue",Color::Orange, 180, 90, 14, 28, 70, 200, 550, 750, 950, 100, 100);
        board[19].emplace<Street>("New York Avenue",Color::Orange, 200, 100, 16, 32, 80, 220, 600, 800, 1000, 100, 100);
        board[20].emplace<FreeParking>();
        board[21].emplace<Street>("Kentucky Avenue",Color::Red, 220, 110, 18, 36, 90, 250, 700, 875, 1050, 150, 150);
        board[22].emplace<ChanceCard>();
        board[23].emplace<Street>("Indiana Avenue",Color::Red, 220, 110, 18, 36, 90, 250, 700, 875, 1050, 150, 150);
        board[24].emplace<Street>("Illinois Avenue",Color::Red, 240, 120, 20, 40, 100, 300, 750, 925, 1100, 150, 150);
        board[25].emplace<RailRoad>("B&O Railroad");
        board[26].emplace<Street>("Atlantic Avenue",Color::Yellow, 260, 130, 22, 44, 110, 330, 800, 975, 1150, 150, 150);
        board[27].emplace<Street>("Ventnor Avenue",Color::Yellow, 260, 130, 22, 44, 110, 330, 800, 975, 1150, 150, 150);
        board[28].emplace<Utility>("Water Works");
        board[29].emplace<Street>("Marvin Gardens", Color::Yellow, 280, 140, 24, 48, 120, 360, 850, 1025, 1200, 150, 150);
        board[30].emplace<GoToJail>(); // Go to jail
        board[31].emplace<Street>("Pacific Avenue",Color::Green, 300, 150, 26, 52, 130, 390, 900, 1100, 1275, 200, 200);
        board[32].emplace<Street>("North Carolina Avenue",Color::Green, 300, 150, 26, 52, 130, 390, 900, 1100, 1275, 200, 200);
        board[33].emplace<CommunityChestCard>();
        board[34].emplace<Street>("Pennsylvania Avenue",Color::Green, 320, 160, 28, 56, 150, 450, 1000, 1200, 1400, 200, 200);
        board[35].emplace<RailRoad>("Short Line");
        board[36].emplace<ChanceCard>();
        board[37].emplace<Street>("Park Place", Color::DarkBlue, 350, 175, 35, 70, 175, 500, 1100, 1300, 1500, 200, 200);
        board[38].emplace<LuxuryTax>();
        board[39].emplace<Street>("Boardwalk", Color::DarkBlue, 400, 200, 50, 100, 200, 600, 1400, 1700, 2000, 200, 200);
    }
};

#endif // BOARD_HPP