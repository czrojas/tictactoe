#include <stdio.h>

void printBoard(char* Board) {
  // This functions purpose is to print the playing board

  // Initial i is 1 in order to print newline if iteration is divisible by 3
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

  // prompting for valid postion
  while(playerPos < 0 || playerPos > 8) {
    printf("Player %d please give a valid position (0-8): ", player);
    scanf("%d", &playerPos);
  }

  if(player) {
    while(Board[playerPos] == 'O') {
      printf("Player 1 please pick a valid position not already taken: ");
      scanf("%d", &playerPos);
    }
    Board[playerPos] = (char) 88;
    return;

  }
  else {
    while(Board[playerPos] == 'X') {
      printf("Player 0 please pick a valid position not already taken: ");
      scanf("%d", &playerPos);
    }
    Board[playerPos] = (char) 79;
    return;
  }

}

int playerWin(int *Winner, char* Board) {
  // We check all 3 horizontal, 3 vertical, forward & backward diagnols
  int results[8] = {Board[0]+Board[1]+Board[2], Board[3]+Board[4]+Board[5],
		    Board[1]+Board[4]+Board[7], Board[2]+Board[5]+Board[8],
		    Board[0]+Board[4]+Board[8], Board[2]+Board[4]+Board[6]};
  
  // Check for a winner, there is a winner if the result of expresion 3 * asciivalue of player number representation on board (X or O)
  for (int i = 0; i < 8; ++i) {
    if (results[i] == 237) { // Ascii value of 0 is 47, hence 47*3 is 144 so there are three 0s, Winnner!
      *Winner = 0;
      return 1;
    }
    else if (results[i] == 264) { // Ascii value of 1 is 48, hence 48*3 is 147 so there are three 1s, Winner!
      *Winner = 1;
      return 2;
    }
  }

  return 0;
}


int openSpot(char* Board) {
  // Check if there is space for players to make a move
  int count = 0;
  for (int i = 0; i < 9; ++i) {
    if (Board[i] == 'X' || Board[i] == 'O') {
      count ++;
    }
  }
  if (count < 9) {
    return 1;
  }
  
  return 0;
}

int main(void) {
  // Board we will use
  char board[] = "012345678";
  int winner = -1;

  printBoard(board);
  promptPlayer(0, board);
  

  int j = 1;
  // Game loop
  while ( !(playerWin(&winner, board)) && openSpot(board)) {
    int player = (j % 2); // alternates between 1 & 0
    printBoard(board);
    promptPlayer(player, board);
    ++j;

  }

  if (!openSpot(board)) { // If no spots left declare draw
    printf("\nThe match ends in a draw.\n\n");
    printBoard(board);
    printf("\n");
  }
  else { // Declare winner
    printf("\nPlayer %d has won the match.\n\n", winner);
    printBoard(board);
    printf("\n");
  }

  return 0;
}

