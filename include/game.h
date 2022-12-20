#ifndef GAME_H
#define GAME_H

#include "../src/game.c"

void printBoard(char *Board);

void promptPlayer(int player, char *Board);

int playerWin(int *Winner, char *Board);

int openSpot(char *Board);

#endif
