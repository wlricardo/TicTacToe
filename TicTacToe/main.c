#include <stdio.h>
#include <stdlib.h>

/** Function prototypes **/
void display_menu();
void display_board();
int select_square(int, int);
void check_for_winner();

/** Global variables **/
char board[3][3];
char winner = ' ';
int current_player = 0;
int select_game = 0;

int main()
{
   int i, j;
   int op;

   for (i=0; i<3; i++) {
      for (j=0; j<3; j++) {
         board[i][j] = ' ';
      }
   }

   display_menu();
   scanf("%d", &op);

   display_board();



   return 0;
}

/** Functions implementations **/
/* Function to select a game */
void display_menu() {
   printf("\n****************************");
   printf("\n Select a game: \n");
   printf("\n [1] Player 1 vs Player 2");
   printf("\n [2] Player 1 vs Computer");
   printf("\n [4] Computer vs Computer");
   printf("\n****************************\n >> ");
}

/* Function to show the game board */
void display_board() {
   system("CLS");
   printf("   \n\t|\t|\n");
   printf("   \t|\t|\n");
   printf("   %c\t|%c\t|%c\n", board[0][0], board[0][1], board[0][2]);
   printf(" -------+-------+--------\n");
   printf("   \t|\t|\n");
   printf("   %c\t|%c\t|%c\n", board[1][0], board[1][1], board[1][2]);
   printf(" -------+-------+--------\n");
   printf("   \t|\t|\n");
   printf("   %c\t|%c\t|%c\n", board[2][0], board[2][1], board[2][2]);
   printf("   \t|\t|\n");
}

/* Function to select a board's empty square */
int select_square(int square, int player) {
   switch (square)
   {
      case 1:
      case 2:
      case 3:
         if ((board[0][square-1] == ' ') && (player == 1 || player == 0)) {
            board[0][square-1] = 'X';
            return 0;
         } else if ((board[0][square-1] == ' ') && (player == 2)) {
            board[0][square-1] = 'O';
            return 0;
         } else {
            return 1;
         }
         break;
      case 4:
      case 5:
      case 6:
         if ((board[1][square-1] == ' ') && (player == 1 || player == 0)) {
            board[1][square-4] = 'X';
            return 0;
         } else if ((board[1][square-4] == ' ') && (player == 2)) {
            board[1][square-4] = 'O';
            return 0;
         } else {
            return 1;
         }
         break;
      case 7:
      case 8:
      case 9:
         if ((board[2][square-1] == ' ') && (player == 1 || player == 0)) {
            board[2][square-7] = 'X';
            return 0;
         } else if ((board[1][square-4] == ' ') && (player == 2)) {
            board[2][square-7] = 'O';
            return 0;
         } else {
            return 1;
         }
   }
}

/* Function to verify if theres is a winner */
void check_for_winner() {
   int i, j = 0;
   int cat = 0;

   for (i=0; i<3; i++) {
      if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
         winner = 'X';
      } else if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X'){
         winner = 'X';
      } else if (board[j][j] == 'X' && board[j+1][j+1] == 'X' && board[j+2][j+2] == 'X') {
         winner = 'X';
      } else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
         winner = 'X';
      } else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
         winner = 'O';
      } else if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O'){
         winner = 'O';
      } else if (board[j][j] == 'O' && board[j+1][j+1] == 'O' && board[j+2][j+2] == 'O') {
         winner = 'O';
      } else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
         winner = 'O';
      }
   }

   if (winner == 'X') {
      printf("\n X won !!\n");
      return;
   }
   if (winner == 'O') {
      printf("\n O won !!\n");
      return;
   }

   for (i=0; i<3; i++) {
      for (j=0; j<3; j++) {
         if (board[i][j] != ' ') {
            cat++;
         }
      }
   }

   if (cat == 9) {
      winner = 'C';
      printf("\n CAT game !!\n");
      return;
   }
}
