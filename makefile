CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = main.cpp Lexer.cpp Automate.cpp
OBJ = $(SRC:.cpp=.o)

all: prog

prog: $(OBJ)
	$(CXX) $(OBJ) -o prog

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	del *.o *.exe
