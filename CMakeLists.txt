# Définit la version minimum de CMake
cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(Monopoly_CPP)

# Définit le standard C++ à utiliser
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajoute les fichiers sources (main.cpp et les autres fichiers .cpp)
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
)

# Génère l'exécutable à partir des sources
add_executable(Monopoly_CPP ${SOURCES})

# Si tu as d'autres fichiers source à part main.cpp, tu peux les ajouter ici
# Par exemple, si tu as un fichier Board.cpp, ajoute-le dans SOURCES
