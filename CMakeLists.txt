# Définit la version minimum de CMake
cmake_minimum_required(VERSION 3.10)

# Nom du projet global
project(Monopoly_CPP)

# Définit le standard C++ à utiliser
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajoute les fichiers sources pour le programme principal
set(SOURCES
        main.cpp
        Player/Player.cpp
        Player/Token.cpp
        SpecialSquare/CommunityChestCard.cpp
        SpecialSquare/ChanceCard.cpp
)

# Ajoute les répertoires contenant les fichiers d'en-tête
include_directories(
        ${CMAKE_SOURCE_DIR}/Card
        ${CMAKE_SOURCE_DIR}/Player
        ${CMAKE_SOURCE_DIR}/Properties
        ${CMAKE_SOURCE_DIR}/SpecialSquare
        ${CMAKE_SOURCE_DIR}/Tests  # Inclure le dossier des tests où se trouve doctest.h
)

# Trouve et lie les composants SFML requis pour les projets
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(X11 REQUIRED)

# -----------------------------------------
# Projet 1: Génère l'exécutable principal
# -----------------------------------------
add_executable(Monopoly_CPP ${SOURCES})

# Lie les bibliothèques SFML et X11 à l'exécutable Monopoly_CPP
target_link_libraries(Monopoly_CPP sfml-graphics sfml-window sfml-system ${X11_LIBRARIES})

# Inclut les répertoires d'en-têtes X11
include_directories(${X11_INCLUDE_DIR})

# -----------------------------------------
# Projet 2: Génère l'exécutable pour les tests
# -----------------------------------------
# Ajoute les fichiers sources pour les tests
set(TEST_SOURCES
        Tests/Board_Tests.cpp
        Tests/Dice_Tests.cpp
        Tests/Player_Tests.cpp
        Tests/RailRoad_Tests.cpp
        Tests/Street_Tests.cpp
        Tests/Token_Tests.cpp
        Tests/Utility_Tests.cpp

        Player/Player.cpp
        Player/Token.cpp
        SpecialSquare/CommunityChestCard.cpp
        SpecialSquare/ChanceCard.cpp
)

# Ajoute l'exécutable pour les tests
add_executable(Monopoly_Tests ${TEST_SOURCES})

# Lie les bibliothèques nécessaires aux tests
target_link_libraries(Monopoly_Tests PRIVATE sfml-graphics sfml-window sfml-system ${X11_LIBRARIES})

# Active les tests
enable_testing()

# Ajoute les tests à CTest
add_test(NAME MonopolyTests COMMAND Monopoly_Tests)