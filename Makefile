CC=gcc
CFLAGS=-Wall -ggdb
OBJS=tictactoe.o
BIN=tictactoe
INCLUDE=include
SRC=src

bin/$(BIN) : objs/$(OBJS)
	$(CC) $(CFLAGS) objs/$(OBJS) -o bin/$(BIN)

objs/$(OBJS) : $(SRC)/main.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/main.c -o objs/$(OBJS)

clean:
	rm bin/* objs/*
