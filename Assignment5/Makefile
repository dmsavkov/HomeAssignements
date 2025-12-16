CXX = g++
CXXFLAGS = -Wall -g -std=c++17 -Isrc
TEST_LIBS = -lgtest -lgtest_main -pthread

MAIN_SRC = main.cpp
MAIN_OBJ = main.o

TEST_SRC = test_matrix.cpp test_rational.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

APP_NAME = matrix
TEST_NAME = run_tests

all: $(APP_NAME) $(TEST_NAME)

$(APP_NAME): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_NAME): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(TEST_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o tests/*.o $(APP_NAME) $(TEST_NAME)