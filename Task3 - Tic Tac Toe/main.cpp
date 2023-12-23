#include <iostream>
#include <vector>
#include <limits>
#include <string>

#define GOLDEN 214
#define SEAFOAM 50
#define GREEN 42
#define BROWN 173
#define RED 196
#define WHITE 15

enum class GameState
{
	NOTHING = -1,
	DRAW,
	X, O
};

void printboard(std::vector<char> & board, GameState curr_player);
GameState check_game_state(std::vector<char> & board, GameState player);
GameState get_player(char c);
bool is_empty_cell(char c);
char play_again(void);
std::string set_color(int color);
std::string reset_style(void);
std::string cell(std::vector<char> & board, int i);

int main()
{
	while (true)
	{
		/* Board indexing:
		* board[3 * r + c]
		* r : row
		* c : column
		*/
		std::vector<char> board = {'1','2','3','4','5','6','7','8','9'};

		GameState player = GameState::X;
		while (true)
		{
			printboard(board, player); // Print the game board

			// Prompt the current player for a move
			std::cout << set_color(player == GameState::X ? GOLDEN : SEAFOAM)
				<< "Player " << (int)player << reset_style()
				<< " enter a move: ";

			int move;
			std::cin >> move;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
			}

			// Validate the move
			if (move < 1 || move > 9 || !is_empty_cell(board[move - 1]))
			{
				std::cout << set_color(RED) << "Invalid move, try again." << reset_style() << std::endl;
				system("pause");
				continue;
			}

			// Update the game board with the player's move
			board[move - 1] = (player == GameState::X) ? 'X' : 'O';

			// Check the game state after the move
			GameState game_state = check_game_state(board, player);

			// Handle the game state
			if (game_state == GameState::DRAW)
			{
				printboard(board, player);
				std::cout << set_color(BROWN) << "Draw!" << reset_style() << std::endl;
				break;
			}
			else if (game_state == GameState::NOTHING)
			{
				// Continue the game if no winner or draw yet
			}
			else
			{
				printboard(board, player);
				std::cout << set_color(GREEN) << "Player " << (int)game_state << " wins!"
					<< reset_style() << std::endl;
				break;
			}

			// Switch to the next player
			player = (player == GameState::X) ? GameState::O : GameState::X;
		}

		// Ask if the players want to play again
		char c = play_again();
		if (c == 'n' || c == 'N')
			break;
	}

	return 0;
}

GameState check_game_state(std::vector<char> & board, GameState player)
{
	char temp;

    // Rows
    for (int i = 0; i < 3; i++)
    {
		// Check if all the cells in the row are the same
        temp = board[3 * i];
        if (temp == board[3 * i + 1] && temp == board[3 * i + 2])
            return get_player(temp);
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
		// Check if all the cells in the column are the same
        temp = board[i];
        if (temp == board[3 * 1 + i] && temp == board[3 * 2 + i])
            return get_player(temp);
    }

    // First diagonal
    temp = board[0];
    if (
		temp == board[3 * 1 + 1] // Check if the middle cell (row 1, column 1) is the same as the first cell
	 && temp == board[3 * 2 + 2] // Check if the last cell (row 2, column 2) is the same as the first cell
	)
        return get_player(temp);

    // Second diagonal
    temp = board[2];
    if(
		temp == board[3 * 1 + 1] // Check if the middle cell (row 1, column 1) is the same as the last cell
	 && temp == board[3 * 2 + 0] // Check if the first cell (row 2, column 0) is the same as the last cell
	)
        return get_player(temp);

    // Draw Check
    for (int i = 0; i < 9; i++)
        if (is_empty_cell(board[i]))
            return GameState::NOTHING;
    return GameState::DRAW;
}

GameState get_player(char c)
{
	return (c == 'X') ? GameState::X : GameState::O;
}

bool is_empty_cell(char c)
{
	return (c != 'X' && c != 'O');
}

void printboard(std::vector<char> & board, GameState curr_player)
{
	system("cls");
	std::cout << "\n\n\t\tTic Tac Toe\n";
	
	// Display the current player
	if (curr_player == GameState::X)
		std::cout << '\t' << set_color(GOLDEN) << "Player 1 (X)"
			<< reset_style() << " - Player 2 (O)\n\n";
	else
		std::cout << "\tPlayer 1 (X) - "
			<< set_color(SEAFOAM) << "Player 2 (O)\n\n" << reset_style();

	// Display the tic-tac-toe board
	std::cout << "\t          |     |\n"
		 << "\t       " << cell(board, 0) << "  |  " << cell(board, 1) << "  |  " << cell(board, 2) << std::endl
		 << "\t     _____|_____|_____\n"
		 << "\t          |     |\n"
		 << "\t       " << cell(board, 3) << "  |  " << cell(board, 4) << "  |  " << cell(board, 5) << std::endl
		 << "\t     _____|_____|_____\n"
		 << "\t          |     |\n"
		 << "\t       " << cell(board, 6) << "  |  " << cell(board, 7) << "  |  " << cell(board, 8) << std::endl
		 << "\t          |     |\n" << std::endl;
}

char play_again(void)
{
	char c;
	while (true)
	{
		std::cout << "Play again? (y/n): ";
		std::cin >> c;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore bad input
		}

		if (c == 'y' || c == 'Y' || c == 'n' || c == 'N')
			break;
	}

	return c;
}

std::string cell(std::vector<char> & board, int i)
{
	return set_color(
		board[i] == 'X' ? GOLDEN : (
			board[i] == 'O' ? SEAFOAM : WHITE
		)
	) + board[i] + reset_style();
}

std::string set_color(int color)
{
	return "\033[38;5;" + std::to_string(color) + "m";
}

std::string reset_style(void)
{
	return "\033[0m";
}
