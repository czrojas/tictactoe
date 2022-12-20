#include "game.h"
#include <stdio.h>

int main() {

  char board[] = "012345678";
  int winner = -1;
  int j = 1;

  puts("#################\nTicTacToe: Start!\n#################");
  printBoard(board);
  promptPlayer(0, board);

  // Game loop
  while (!(playerWin(&winner, board)) && openSpot(board)) {
    int player = (j % 2); // alternates between 1 & 0
    printBoard(board);
    promptPlayer(player, board);
    ++j;
  }

  if (!openSpot(board)) {
    // If no spots left declare draw
    puts("\nThe match ends in a draw.\n\n");
    printBoard(board);
    putc('\n', stdout);
  }

  else {
    // Declare winner
    printf("\nPlayer %d has won the match.\n\n", winner);
    printBoard(board);
    putc('\n', stdout);
  }
  return 0;
}
