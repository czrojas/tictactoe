#include <stdio.h>

void printBoard(char* Board) {
  // This functions purpose is to print the playing board

  // initial i is 1 to be able to print newline if iteration is divisible by 3
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

  // FIXME: Make this agnostic
  if ( !player ) {
    printf("Player 0, please choose a position, 0-8: ");
    scanf("%d", &playerPos);
    Board[playerPos] = '0';
  }
 
  return; 
}

_Bool playerTies(char* Board) {
  return 1;
}



void playerWin(int Winner, char* Board) {}

int main(void) {
  // Board we will use
  char board[] = "---------";
  int winner = 1;

  printBoard(board);
  promptPlayer(0, board);
  printBoard(board);


  // Game Loop
  while ( !winner ) {
    
  }


  return 0;
}
