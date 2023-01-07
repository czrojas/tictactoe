CC=gcc
CFLAGS=-Wall -ggdb
INCLUDE=include
SRC=src

OBJS=tictactoe.o
OBJSDIR=objs

BIN=tictactoe
BUILDDIR=bin

$(BUILDDIR)/$(BIN) : $(OBJSDIR)/$(OBJS) | $(BUILDDIR)
	$(CC) $(CFLAGS) $(OBJSDIR)/$(OBJS) -o $(BUILDDIR)/$(BIN)

$(OBJSDIR)/$(OBJS) : $(SRC)/main.c | $(OBJSDIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/main.c -o $(OBJSDIR)/$(OBJS)

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(OBJSDIR):
	mkdir $(OBJSDIR)

clean:
	rm $(BUILDDIR)/* $(OBJSDIR)/*
