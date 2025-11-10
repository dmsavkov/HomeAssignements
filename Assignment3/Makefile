# Author: Савков Дмитрий 25.Б81-мм
# Contact: st140851@student.spbu.ru

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# lgtest_main has main function to RUN_ALL_TESTS() automatically
GTEST_FLAGS = -lgtest -lgtest_main -pthread

SRC = Transformer.cpp Autobot.cpp Decepticon.cpp Minibot.cpp Weapon.cpp Mission.cpp
OBJ = $(SRC:.cpp=.o)

SRC_TEST = test_transformer.cpp test_autobot.cpp test_decepticon.cpp test_minibot.cpp
OBJ_TEST = $(SRC_TEST:.cpp=.o)

MAIN = transformers
TESTS = all_tests

all: $(MAIN)

$(MAIN): main.o $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(TESTS): $(OBJ_TEST) $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(GTEST_FLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

test: $(TESTS)
	./$(TESTS)

run: $(MAIN)
	./$(MAIN)

clean:
	rm -f *.o $(MAIN) $(TESTS)

.PHONY: all test run clean