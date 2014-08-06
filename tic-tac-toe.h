/* File: tic-tac-toe.h */

const char EMPTY = ' ';
const char CROSS = 'X';
const char NAUGHT = 'O';
const char DRAW = 'D';


struct TicTacToe
{
    char board[3][3];  // 3x3 game board
    char player;       // Next player. Player is identified by the mark he
                       // uses; the player who marks CROSS always plays first
};

/* External function declarations */
// ADD YOUR CODE HERE


void initialize_game(TicTacToe& game);
bool next_move(TicTacToe& game, int x, int y);
char check_winner(const TicTacToe& game);
void print_game_board(const TicTacToe& game);


   
