CC = g++
LIBS = -lm -pg
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/set.o $(OBJ)/main.o
HDRS = $(INC)/set.hpp
CFLAGS = -I$(INC) -pg -c
EXE = $(BIN)/pa10.out

all: $(OBJ) $(EXE)

$(OBJ):
	mkdir -p $(OBJ)

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/set.o: $(HDRS) $(SRC)/set.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/set.o $(SRC)/set.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

run: $(EXE)
	./$(EXE)

clean:
	rm -rf 
