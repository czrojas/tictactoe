#include <stdio.h>

void printBoard(char* Board) {
  // This functions purpose is to print the playing board

  // Initial I Is 1 To Be Able To Print Newline If Iteration Is Divisible By 3
  for (int i = 1; i < 10; i++) {

    printf("%c", Board[i-1]); // Print the board at [i-1] to print full board
    if ( !(i%3) ) {
      // When i is 3,6,9
      printf("\n");
      }
  }

  return;
}

void promptPlayer(int player, char* Board) {
  int playerPos = 0;

  printf("Player %d where do you want to place your piece? 0-8: ", player);
  scanf("%d", &playerPos);

  while(playerPos < 0 || playerPos > 8) {
    printf("Player %d please give a valid position (0-8): ", player);
    scanf("%d", &playerPos);
  }

  
  Board[playerPos] = (char) 48 + player;

  return;
}

int playerWin(int *Winner, char* Board) {

  int results[8] = {Board[0]+Board[1]+Board[2], Board[3]+Board[4]+Board[5],
		    Board[6]+Board[7]+Board[8], Board[0]+Board[3]+Board[6],
		    Board[1]+Board[4]+Board[7], Board[2]+Board[5]+Board[8],
		    Board[0]+Board[4]+Board[8], Board[2]+Board[4]+Board[6]};

  for (int i = 0; i < 8; ++i) {
    if (results[i] == 144) {
      *Winner = 0;
      return 1;
    }
    else if (results[i] == 147) {
      *Winner = 1;
      return 2;
    }
  }

  return 0;
}


int openSpot(char* Board) {
  // Check if there is space for players to make a move
  for (int i = 0; i < 9; ++i) {
    if (Board[i] == '-') {
      return 1;
    }
  }
  
  return 0;
}

int main(void) {
  // Board we will use
  char board[] = "---------";
  int winner = -1;

  printBoard(board);
  promptPlayer(0, board);

  int j = 1;
  // Game loop
  while ( !(playerWin(&winner, board)) && openSpot(board)) {
    int player = (j % 2);
    printBoard(board);
    promptPlayer(player, board);
    ++j;

  }

  if (!openSpot(board)) {
    printf("\nThe match ends in a draw.\n\n");
    printBoard(board);
    printf("\n");
  }
  else {
    printf("\nPlayer %d has won the match.\n\n", winner);
    printBoard(board);
    printf("\n");
  }

  return 0;
}
