// ADD YOUR CODE HERE: #include etc.
#include <iostream>
#include <string>
#include "tic-tac-toe.h"

using namespace std;

int main(void)
{
    TicTacToe game;
    bool end_of_game = false; // To keep track the status of the game

    initialize_game(game); // Empty the game board; set X as the first player

    while (!end_of_game)
    {
        int x, y; // Coordinates of the next move; start at (1,1)
        
        if (game.player == CROSS)
            cout << "Play 1's turn: Where do you want to put your cross?" << endl;
        else
            cout << "Play 2's turn: Where do you want to put your naught?" << endl;
        
        cout << "Row (1-3): ";
        cin >> x;
        cout << "Column (1-3): ";
        cin >> y;

        if ((x > 0) && (x <= 3))
        {
            if ((y > 0) && (y <= 3))
            {
                if (next_move(game, x, y))
                    print_game_board(game);
                else
                    continue;

                // Check if someone wins the game or it is already a draw game.
                // If so, stop the program.
                switch (check_winner(game))
                {   
                    case CROSS:
                        cout << "The winner is: Player 1" << endl;
                        end_of_game = true;
                        break;
                    case NAUGHT:
                        cout << "The winner is: Player 2" << endl;
                        end_of_game = true;
                        break;
                    case DRAW:
                        cout << "The game ends in a draw!"  << endl;
                        end_of_game = true;
                        break;
                    default: // Switch player
                        game.player = (game.player == CROSS) ? NAUGHT : CROSS;
                        break;
                }
            }
            else
                cout << "Invalid column number! Input again!" << endl;
        }
        else
            cout << "Invalid row number! Input again!" << endl;
    }

    return 0;
}
