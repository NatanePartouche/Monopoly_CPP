# Makefile for Monopoly_CPP project

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Directories
SRC_DIR = .
BUILD_DIR = build
INCLUDE_DIRS = -I$(SRC_DIR)/Card -I$(SRC_DIR)/Player -I$(SRC_DIR)/Properties -I$(SRC_DIR)/SpecialSquare -I$(SRC_DIR)/Tests

# Source files for the main program
SRC_FILES = $(wildcard $(SRC_DIR)/main.cpp $(SRC_DIR)/Player/*.cpp $(SRC_DIR)/SpecialSquare/*.cpp)

# Source files for tests
TEST_SRC_FILES = $(wildcard $(SRC_DIR)/Tests/*.cpp $(SRC_DIR)/Player/*.cpp $(SRC_DIR)/SpecialSquare/*.cpp)

# Object files for main and test programs
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))
TEST_OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_SRC_FILES))

# Binary files
TARGET = $(BUILD_DIR)/Monopoly_CPP
TEST_TARGET = $(BUILD_DIR)/Monopoly_Tests

# SFML settings (Libraries)
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lX11

# Default target: compile the main program
all: $(TARGET)

# Rule to compile the main program
$(TARGET): $(OBJ_FILES)
	@echo "Linking the main executable: $(TARGET)"
	$(CXX) $(OBJ_FILES) -o $(TARGET) $(SFML_LIBS)

# Rule to compile object files for the main program
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Create the directory if it doesn't exist
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Rule to compile and link the test program and run it
tests: $(TEST_TARGET)
	@echo "Running the tests"
	./$(TEST_TARGET)

# Rule to compile the test program
$(TEST_TARGET): $(TEST_OBJ_FILES)
	@echo "Linking the test executable: $(TEST_TARGET)"
	$(CXX) $(TEST_OBJ_FILES) -o $(TEST_TARGET) $(SFML_LIBS)

# Run the main program
run: $(TARGET)
	@echo "Running the main program"
	./$(TARGET)

# Clean the build directory
clean:
	@echo "Cleaning the build directory"
	rm -rf $(BUILD_DIR)

.PHONY: all run tests clean