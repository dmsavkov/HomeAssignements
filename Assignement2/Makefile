PROJECT = file_worker
CXX = g++
CXXFLAGS = -Wall -Wextra
SRC = main.cpp file_manager.cpp iostream_handler.cpp calculator.cpp

OBJ = $(SRC:.cpp=.o) 

all: $(PROJECT)
$(PROJECT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(PROJECT)
