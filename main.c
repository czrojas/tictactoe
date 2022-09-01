#include <stdio.h>
#include <string.h>

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
  Board[playerPos] = (char) 48 + player;

  return;
}

int playerWin(char* Board) {
  
  return 0;
}

int openSpot(char* Board) {

  return 1;
}


int main(void) {
  // Board we will use
  char board[] = "---------";

  printBoard(board);
  promptPlayer(0, board);

  int j = 1;
  // Game loop
  while ( !(playerWin(board)) && openSpot(board)) {
    int player = (j % 2);
    printBoard(board);
    promptPlayer(player, board);
    ++j;
   
  }


  return 0;
}
