#include <stdio.h>

void printBoard(char *Board) {
  // This functions purpose is to print the playing board
  // Initial i is 1 in order to print newline if iteration is divisible by 3
  putc('\n', stdout);
  for (int i = 1; i < 10; i++) {
    printf(" %c ", Board[i - 1]); // Print the board at [i-1] to print full board
    if (!(i % 3)) {
      // When i is 3,6,9
      putc('\n', stdout);
    }
  }
  putc('\n', stdout);
  return;
}

void promptPlayer(int player, char *Board) {
  int playerPos = 0;
  int newline = 0;

  printf("Player %d where do you want to place your piece? 0-8: ", player);
  int inp = scanf("%d", &playerPos) == 1;

  while ((getchar()) != '\n') {
    ++newline;
  }

  // prompting for valid postion
  // !i or (i and (!r or (r and t)))
  int y =
    (inp == 0) ||
    ((inp == 1) &&
     (!(playerPos >= 0 && playerPos <= 8) ||
      ((playerPos >= 0 && playerPos <= 8) &&
       (Board[playerPos] == 'X' || Board[playerPos] == 'O')))) ||
    (newline);

  while(y) {
    printf("Player %d please give a valid position (0-8): ", player);
    fflush(stdout);
    newline = 0;
    inp = scanf("%d", &playerPos) == 1;

    while ((getchar()) != '\n') {
      ++newline;
    }

    y =
      (inp == 0) ||
      ((inp == 1) &&
       (!(playerPos >= 0 && playerPos <= 8) ||
	((playerPos >= 0 && playerPos <= 8) &&
	 (Board[playerPos] == 'X' || Board[playerPos] == 'O')))) ||
      (newline);
  }


  if (player == 1) {
    Board[playerPos] = 88;
  }
  else {
    Board[playerPos] = 79;
  }
  return;
}

int playerWin(int *Winner, char *Board) {
  // We check all 3 horizontal, 3 vertical, forward & backward diagnols
  int results[8] = {
    Board[0] + Board[1] + Board[2], Board[3] + Board[4] + Board[5],
    Board[1] + Board[4] + Board[7], Board[2] + Board[5] + Board[8],
    Board[0] + Board[4] + Board[8], Board[2] + Board[4] + Board[6]};

  // Check for a winner, there is a winner if the result of expresion 3 *
  // asciivalue of player number representation on board (X or O)
  for (int i = 0; i < 8; ++i) {

    if (results[i] == 237) {
      // Ascii value of 0 is 47, hence 47*3 is 144 so
      *Winner = 0;
      return 1;
    }
    else if (results[i] == 264) {
      // Ascii value of 1 is 48, hence 48*3 is 147
      // so there are three 1s, Winner!
      *Winner = 1;
      return 2;
    }
  }
  return 0;
}

int openSpot(char *Board) {
  // Check if there is space for players to make a move
  int count = 0;
  for (int i = 0; i < 9; ++i) {
    if (Board[i] == 'X' || Board[i] == 'O') {
      count++;
    }
  }
  if (count < 9) {
    return 1;
  }
  return 0;
}
