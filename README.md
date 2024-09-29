# Monopoly_CPP

## Overview

**Monopoly_CPP** is a C++ implementation of the classic Monopoly board game designed for 2 to 8 players, playable on the same computer. 
This version follows traditional Monopoly rules, allowing players to buy properties, build houses and hotels, pay rent, and try to bankrupt their opponents. 
The game is built using C++ and includes a graphical interface to display the board and player status.

## Features

- **Supports 2 to 8 players**: Play the game with multiple players on a single computer.
- **Dynamic Board**: The board contains 40 slots with various types such as streets, train stations, utilities, and special slots.
- **Properties**: Players can purchase streets, build houses and hotels, and collect rent from other players.
- **Train Stations**: 4 train stations are available, and rent increases with the number of stations owned by the same player.
- **Utilities**: Water and electric companies charge players based on their dice roll.
- **Special Slots**: Include taxes, jail, free parking, and surprise slots offering various bonuses or penalties.
- **Game Objective**: The game is won when a player accumulates 4000 currency units or all other players go bankrupt.

## Game Rules

- Each player starts with 1500 currency units.
- Players take turns rolling two dice to move around the board.
- If a player lands on a free property, they can purchase it.
- Players collect 200 currency units every time they pass the starting point.
- If a player lands on another player’s property, they must pay rent based on the development of the property (houses, hotels).
- Players can build houses and hotels on properties, increasing the rent.
- A player who cannot pay rent or other fees becomes bankrupt and is eliminated from the game.
- The game ends when one player remains or when a player reaches 4000 currency units.

### Special Slots

- **Surprise Slots**: Provide random events, such as "Get out of jail free" cards or monetary rewards.
- **Free Parking**: Landing here allows the player to skip their turn without penalty.
- **Tax Slots**: Players pay a fixed amount when landing on these slots.
- **Jail**: Players can go to jail if they land on the "Go to Jail" square or roll a double three times in a row. They can get out by paying a fine, using a "Get out of jail free" card, or rolling a double.


### Streets in the Game

This Monopoly version includes several streets divided into color groups, each with its own price, rent, and building costs. Below is a list of streets included in the game:

	1.	Mediterranean Avenue (Brown)
Price: 60 | Rent: 5 | House Price: 50 | Rent with Houses: 10, 20, 40, 80, 160 | Rent with Hotel: 320
2.	Baltic Avenue (Brown)
Price: 60 | Rent: 5 | House Price: 50 | Rent with Houses: 10, 20, 40, 80, 160 | Rent with Hotel: 320
3.	Oriental Avenue (Light Blue)
Price: 100 | Rent: 6 | House Price: 50 | Rent with Houses: 12, 30, 90, 270, 400 | Rent with Hotel: 550
4.	Vermont Avenue (Light Blue)
Price: 100 | Rent: 6 | House Price: 50 | Rent with Houses: 12, 30, 90, 270, 400 | Rent with Hotel: 550
5.	Connecticut Avenue (Light Blue)
Price: 120 | Rent: 8 | House Price: 50 | Rent with Houses: 16, 40, 100, 300, 450 | Rent with Hotel: 600
6.	St. Charles Place (Pink)
Price: 140 | Rent: 10 | House Price: 100 | Rent with Houses: 20, 50, 150, 450, 625 | Rent with Hotel: 750
7.	States Avenue (Pink)
Price: 140 | Rent: 10 | House Price: 100 | Rent with Houses: 20, 50, 150, 450, 625 | Rent with Hotel: 750
8.	Virginia Avenue (Pink)
Price: 160 | Rent: 12 | House Price: 100 | Rent with Houses: 24, 60, 180, 500, 700 | Rent with Hotel: 900
9.	St. James Place (Orange)
Price: 180 | Rent: 14 | House Price: 100 | Rent with Houses: 28, 70, 200, 550, 750 | Rent with Hotel: 950
10.	Tennessee Avenue (Orange)
Price: 180 | Rent: 14 | House Price: 100 | Rent with Houses: 28, 70, 200, 550, 750 | Rent with Hotel: 950
11.	New York Avenue (Orange)
Price: 200 | Rent: 16 | House Price: 100 | Rent with Houses: 32, 80, 220, 600, 800 | Rent with Hotel: 1000
12.	Kentucky Avenue (Red)
Price: 220 | Rent: 18 | House Price: 150 | Rent with Houses: 36, 90, 250, 700, 875 | Rent with Hotel: 1050
13.	Indiana Avenue (Red)
Price: 220 | Rent: 18 | House Price: 150 | Rent with Houses: 36, 90, 250, 700, 875 | Rent with Hotel: 1050
14.	Illinois Avenue (Red)
Price: 240 | Rent: 20 | House Price: 150 | Rent with Houses: 40, 100, 300, 750, 925 | Rent with Hotel: 1100
15.	Atlantic Avenue (Yellow)
Price: 260 | Rent: 22 | House Price: 150 | Rent with Houses: 44, 110, 330, 800, 975 | Rent with Hotel: 1150
16.	Ventnor Avenue (Yellow)
Price: 260 | Rent: 22 | House Price: 150 | Rent with Houses: 44, 110, 330, 800, 975 | Rent with Hotel: 1150
17.	Marvin Gardens (Yellow)
Price: 280 | Rent: 24 | House Price: 150 | Rent with Houses: 48, 120, 360, 850, 1025 | Rent with Hotel: 1200
18.	Pacific Avenue (Green)
Price: 300 | Rent: 26 | House Price: 200 | Rent with Houses: 52, 130, 390, 900, 1100 | Rent with Hotel: 1275
19.	North Carolina Avenue (Green)
Price: 300 | Rent: 26 | House Price: 200 | Rent with Houses: 52, 130, 390, 900, 1100 | Rent with Hotel: 1275
20.	Pennsylvania Avenue (Green)
Price: 320 | Rent: 28 | House Price: 200 | Rent with Houses: 56, 150, 450, 1000, 1200 | Rent with Hotel: 1400
21.	Park Place (Dark Blue)
Price: 350 | Rent: 35 | House Price: 200 | Rent with Houses: 70, 175, 500, 1100, 1300 | Rent with Hotel: 1500
22.	Boardwalk (Dark Blue)
Price: 400 | Rent: 50 | House Price: 200 | Rent with Houses: 100, 200, 600, 1400, 1700 | Rent with Hotel: 2000

### Additional Slots

	23.	Go: Starting point, players collect 200 currency when passing.
	24.	Community Chest: Draw a card from the Community Chest deck.
	25.	Income Tax: Pay 10% or 200 currency units (whichever is less).
	26.	Reading Railroad: Price: 200 | Rent varies by the number of railroads owned.
	27.	Chance: Draw a card from the Chance deck.
	28.	Jail: Players may land in Jail and need to pay or roll doubles to escape.
	29.	Electric Company (Utility): Price: 150 | Rent: 4 times the dice roll.
	30.	Water Works (Utility): Price: 150 | Rent: 4 times the dice roll.
	31.	B&O Railroad: Price: 200 | Rent varies by the number of railroads owned.
	32.	Free Parking: No action occurs here; it is a resting spot.
	33.	Pennsylvania Railroad: Price: 200 | Rent varies by the number of railroads owned.
	34.	Go to Jail: Player goes directly to Jail.
	35.	Short Line Railroad: Price: 200 | Rent varies by the number of railroads owned.
	36.	Luxury Tax: Pay 100 currency units.

## Project Structure

The project is organized into several directories and files:

```
Monopoly_CPP/
│
├── cmake-build-debug/     # Build directory (generated files)
├── Player/                # Contains player-related classes
│   ├── Player.cpp
│   ├── Player.hpp
│   ├── Token.cpp
│   ├── Token.hpp
│
├── Properties/            # Property-related classes
│   ├── Color.hpp
│   ├── RailRoad.hpp
│   ├── Street.hpp
│   ├── Utility.hpp
│
├── SpecialSquare/         # Special square classes (e.g., Chance, Tax)
│   ├── ChanceCard.cpp
│   ├── ChanceCard.hpp
│   ├── CommunityChestCard.cpp
│   ├── CommunityChestCard.hpp
│   ├── FreeParking.hpp
│   ├── Go.hpp
│   ├── GoToJail.hpp
│   ├── IncomeTax.hpp
│   ├── Jail.hpp
│   ├── LuxuryTax.hpp
│
├── Tests/                 # Unit tests for various components
│   ├── Board_Tests.cpp
│   ├── Dice_Tests.cpp
│   ├── doctest.h
│   ├── Player_Tests.cpp
│   ├── RailRoad_Tests.cpp
│   ├── Street_Tests.cpp
│   ├── Token_Tests.cpp
│   ├── Utility_Tests.cpp
│
├── arial.ttf              # Font file used in the graphical interface
├── Battleship.png         # Token image for battleship
├── board.png              # Image representing the Monopoly board
├── Boot.png               # Token image for boot
├── Car.png                # Token image for car
├── Cat.png                # Token image for cat
├── Dog.png                # Token image for dog
├── Iron.png               # Token image for iron
├── Thimble.png            # Token image for thimble
├── Top hat.png            # Token image for top hat
├── Wheelbarrow.png        # Token image for wheelbarrow
├── Board.hpp              # Header file for board-related functionality
├── Dice.hpp               # Header file for dice functionality
├── main.cpp               # Main program file
├── CMakeLists.txt         # CMake build configuration
├── Makefile               # Makefile for building and running the project
├── README.md              # Project documentation (this file)
```

## Build and Run Instructions

To compile and run the game, you can use the following commands:

### Compilation

- **Compile the main program:**
  ```bash
  make
  ```

- **Compile and execute the main program:**
  ```bash
  make run
  ```

- **Compile and execute the unit tests:**
  ```bash
  make tests
  ```

- **Clean the build directory:**
  ```bash
  make clean
  ```

## Dependencies

This project depends on the following libraries:
- **SFML**: For the graphical interface and handling player inputs.
- **C++17**: The game is written in C++17, so you need a compiler that supports this standard.

### Installation Instructions for SFML

1. Install SFML:
    - On Ubuntu/Debian:
      ```bash
      sudo apt-get install libsfml-dev
      ```
    - On Windows or macOS, you can follow the [SFML installation guide](https://www.sfml-dev.org/tutorials/2.6/).

2. Ensure CMake is installed to configure the project:
   ```bash
   sudo apt-get install cmake
   ```

## How to Play

1. Run the game using `make run`.
2. Players will take turns rolling two dice and moving their token around the board.
3. Buy properties, build houses, and collect rent from other players to increase your wealth.
4. The game continues until only one player remains or a player reaches 4000 currency units.
5. Follow the on-screen instructions to manage properties, pay rent, and handle special squares.

## Testing

The project includes unit tests to validate the game logic. You can run the tests by using:

```bash
make tests
```