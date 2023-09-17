#include <iostream>

using namespace std;

void displayBoard(char board[3][3]);
int checkWin(char board[3][3]);

int main() 
{
	play_again:
	char board[3][3];
	int turns = 0, play_again = 0, place = 0, row_cord, column_cord, win = 2;

	//Initializing an empty board
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '_';
			cout << "_" << "  ";
		}

		cout << "\n";
	}

	while (turns <= 8 || play_again == 1)
	{
		//Initializing turns and play again to 0 to restart
		if (play_again == 1)
		{
			turns = 0;
			play_again = 0;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					board[i][j] = '_';
					cout << "_" << "  ";
				}

				cout << "\n";
			}
		}
		else if (play_again == -1)
		{
			break;
		}
		//X moves first, then O
		if (turns % 2 == 0)
		{
			x_turn:
			cout << "\nX's turn";

			//Displaying our board
			displayBoard(board);

			cout << "\nEnter row that you want to place X in: ";
			cin >> row_cord;
			row_cord -= 1;

			cout << "\nEnter column that you want to place X in: ";
			cin >> column_cord;
			column_cord -= 1;

			//Checking if char can be placed there
			if (board[row_cord][column_cord] == '_')
			{
				board[row_cord][column_cord] = 'X';
			}
			else
			{
				cout << "Location already occupied!";
				goto x_turn;
			}

			win = checkWin(board);

			if (win == 1)
			{
				cout << "\n\nX Wins!";
				cout << "\nWould you like to play again? (Enter 1 for yes, -1 for no): ";
				cin >> play_again;
			}
			else if (win == 0)
			{
				cout << "\n\nGame is a Draw!";
				cout << "\nWould you like to play again? (Enter 1 for yes, -1 for no): ";
				cin >> play_again;
			}
			turns++;
		}
		else
		{
		o_turn:
			cout << "\nO's turn";

			//Displaying our board
			displayBoard(board);

			cout << "\nEnter row that you want to place 0 in: ";
			cin >> row_cord;
			row_cord -= 1;

			cout << "\nEnter column that you want to place O in: ";
			cin >> column_cord;
			column_cord -= 1;

			//Checking if char can be placed there
			if (board[row_cord][column_cord] == '_')
			{
				board[row_cord][column_cord] = 'O';
			}
			else
			{
				cout << "Location already occupied!";
				goto o_turn;
			}

			win = checkWin(board);

			if (win == -1)
			{
				cout << "\n\nO Wins!";
				cout << "\nWould you like to play again? (Enter 1 for yes, -1 for no): ";
				cin >> play_again;
			}
			else if (win == 0)
			{
				cout << "\n\nGame is a Draw!";
				cout << "\nWould you like to play again? (Enter 1 for yes, 0 for no): ";
				cin >> play_again;
			}

			turns++;
		}
	}

	if (turns == 9)
	{
		cout << "\nGame is draw!";
		cout << "\nWould you like to play again? (1 for yes, -1 for no): ";
		cin >> play_again;

		if (play_again == 1)
		{
			goto play_again;
		}
	}
}

//Displaying our board
void displayBoard(char board[3][3])
{
	cout << "\n\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << "  ";
		}
		cout << "\n";
	}
}

//Checking win
int checkWin(char board[3][3])
{
	if (
		board[0][0] == 'X' && board[0][0] == board[0][1] && board[0][1] == board[0][2] ||
		board[1][0] == 'X' && board[1][0] == board[1][1] && board[1][1] == board[1][2] ||
		board[2][0] == 'X' && board[2][0] == board[2][1] && board[2][1] == board[2][2] ||
		board[0][0] == 'X' && board[0][0] == board[1][0] && board[1][0] == board[2][0] ||
		board[0][1] == 'X' && board[0][1] == board[1][1] && board[1][1] == board[2][1] ||
		board[0][2] == 'X' && board[0][2] == board[1][2] && board[1][2] == board[2][2] ||
		board[0][0] == 'X' && board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
		board[0][2] == 'X' && board[0][2] == board[1][1] && board[1][1] == board[2][0]
		)
	{
		return 1;
	}
	else if (
		board[0][0] == 'O' && board[0][0] == board[0][1] && board[0][1] == board[0][2] ||
		board[1][0] == 'O' && board[1][0] == board[1][1] && board[1][1] == board[1][2] ||
		board[2][0] == 'O' && board[2][0] == board[2][1] && board[2][1] == board[2][2] ||
		board[0][0] == 'O' && board[0][0] == board[1][0] && board[1][0] == board[2][0] ||
		board[0][1] == 'O' && board[0][1] == board[1][1] && board[1][1] == board[2][1] ||
		board[0][2] == 'O' && board[0][2] == board[1][2] && board[1][2] == board[2][2] ||
		board[0][0] == 'O' && board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
		board[0][2] == 'O' && board[0][2] == board[1][1] && board[1][1] == board[2][0]
		)
	{
		return -1;
	}
}