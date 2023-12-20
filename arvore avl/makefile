#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#           : make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lstdc++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/arv.o
HDRS = $(INC)/arv.hpp
CFLAGS = -g -std=c++14 -Wall -c -I$(INC)

EXE = $(BIN)/pa.out

all: $(EXE)
	
$(BIN)/pa.out: $(OBJS)
	$(CC) -o $(BIN)/pa.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/arv.o: $(HDRS) $(SRC)/arv.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/arv.o $(SRC)/arv.cpp 

	
clean:
	rm -f $(EXE) $(OBJS)
