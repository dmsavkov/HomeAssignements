PROJECT = calculator
CXX = g++
CXXFLAGS = -Wall -Wextra
COMMON_DIR = ../common
SRC = main.cpp ${COMMON_DIR}/file_manager.cpp ${COMMON_DIR}/iostream_handler.cpp  \
				${COMMON_DIR}/calculator.cpp
	
OBJ = $(SRC:.cpp=.o) 

all: $(PROJECT)
$(PROJECT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(PROJECT)
