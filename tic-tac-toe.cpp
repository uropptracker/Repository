// ADD YOUR CODE HERE: #include etc.
#include <iostream>
#include <string>
#include "tic-tac-toe.h"

using namespace std;

/*
 * Initialize all the cells of the game board to EMPTY.
 * And set the first player to use CROSS marks.
 */

// ADD YOUR CODE HERE FOR THE FUNCTION
void initialize_game(TicTacToe& game)
{
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			game.board[i][j] = EMPTY;
	game.player = CROSS;
}



/*
 * To mark the next move by the player. Note that the position (x, y) starts 
 * from (1, 1), but C++ array starts at (0, 0), so one has to subtract 1 from 
 * each coordinate.
 *
 * Return: true if it is a valid move, otherwise false and the user has to input 
 *         the position again.
 */
// ADD YOUR CODE HERE FOR THE FUNCTION
bool next_move(TicTacToe& game, int x, int y)
{
	if (game.board[x-1][y-1] == EMPTY)
	{
		game.board[x-1][y-1] = (game.player == CROSS) ? CROSS : NAUGHT;
		return true;
	}
	cout << "Position (" << x << ", " << y << ") is already occupied! Input again!" << endl;
	return false;
}


/*
 * Check if player 1/2 has won the game or if the game ends in a draw.
 * Return value:
 *     EMPTY -- no one wins and game continues;
 *     CROSS -- player 1 wins;
 *     NAUGHT -- player 2 wins;
 *     DRAW -- draw;
 */
// ADD YOUR CODE HERE FOR THE FUNCTION
char check_winner(const TicTacToe& game)
{
	//ROW CHECKING
	for (int i=0; i<3; i++)
	{
		//Row checking
		if (game.board[i][0] == CROSS && game.board[i][1] == CROSS && game.board[i][2] == CROSS)
			return CROSS;
		else if (game.board[i][0] == NAUGHT && game.board[i][1] == NAUGHT && game.board[i][2] == NAUGHT)
			return NAUGHT;
		//Column checking
		else if (game.board[0][i] == CROSS && game.board[1][i] == CROSS && game.board[2][i] == CROSS)
			return CROSS;
		else if (game.board[0][i] == NAUGHT && game.board[1][i] == NAUGHT && game.board[2][i] == NAUGHT)
			return NAUGHT;
	}
	//Diagonal checking
	if (game.board[0][0] == CROSS && game.board[1][1] == CROSS && game.board[2][2] == CROSS)
		return CROSS;
	else if (game.board[0][0] == NAUGHT && game.board[1][1] == NAUGHT && game.board[2][2] == NAUGHT)
		return NAUGHT;
	if (game.board[0][2] == CROSS && game.board[1][1] == CROSS && game.board[2][0] == CROSS)
		return CROSS;
	else if (game.board[0][2] == NAUGHT && game.board[1][1] == NAUGHT && game.board[2][0] == NAUGHT)
		return NAUGHT;

	//EMPTY checking
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			if (game.board[i][j] == EMPTY)
				return EMPTY;

	return DRAW;
}



// Print the result after each move
void print_game_board(const TicTacToe& game)
{
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
                cout << ' ' << game.board[i][j];
                if (j < 2)
                    cout << " |";
                else
                    cout << endl;
            }

            if (i < 2)
                cout << "-----------" << endl;
    }

    cout << endl;
}
