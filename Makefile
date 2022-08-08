CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN = bin

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE	:= main

HEADERS = board.h king.h piece.h
SRC = main.cpp board.cpp king.cpp piece.cpp
OBJ = main.o board.o king.o piece.o

%.o: %.cpp $(HEADERS)
	$(CXX) -c $< -o $@ $(CXX_FLAGS)

all: $(EXECUTABLE)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(EXECUTABLE) $(OBJ)
