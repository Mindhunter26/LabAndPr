#include <iostream>
#include "TicTacToe.h"

Game initGame(char userChar) 
{
	Game game;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) 
		{
			game.board[i][j] = ' ';
		}

	game.isUserTurn = true;
	game.userChar = userChar;
	game.botChar = (userChar == 'x' ? 'o' : 'x');
	game.status = PLAY;

	updateDisplay(game);
	return game;
}

void updateDisplay(const Game game) 
{
	system("CLS");

	std::cout << "    1   2   3\n  -------------\n";

	for (int i = 0; i < 3; i++) 
	{
		std::cout << i + 1 << " | ";

		for (int j = 0; j < 3; j++)
			std::cout << game.board[i][j] << " | ";

		std::cout << "\n  -------------\n";
	}
}

void botTurn(Game* game) 
{
	int filledCount = 0;

	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) 
			if (game->board[i][j] != ' ') 
				filledCount++;
	
	if (filledCount == 0) // First botChar goes to center
	{
		game->board[1][1] = game->botChar; 
		return;
	}

	filledCount = 0;

	for (int i = 0; i < 3; i++) //Checking diag1
	{
		if (game->board[i][i] == game->userChar) 
			filledCount++;
		else if (game->board[i][i] == game->botChar) 
			filledCount--;
	} 

	if (filledCount == 2) //Saves diag
	{
		for (int i = 0; i < 3; i++) 
		{
			if (game->board[i][i] == ' ') 
			{
				game->board[i][i] = game->botChar;
				return;
			}
		}
	} 

	filledCount = 0;

	for (int i = 0; i < 3; i++)  //Checking second diag
	{
		if (game->board[i][2 - i] == game->userChar) 
			filledCount++;
		else if (game->board[i][2 - i] == game->botChar) 
			filledCount--;
	}

	if (filledCount == 2) //Saves second diag
	{
		for (int i = 0; i < 3; i++) 
		{
			if (game->board[i][2 - i] == ' ') 
			{
				game->board[i][2 - i] = game->botChar;
				return;
			}
		}
	}

	for (int i = 0; i < 3; i++) //Check rows
	{
		filledCount = 0;

		for (int j = 0; j < 3; j++) 
		{
			if (game->board[i][j] == game->userChar) 
				filledCount++;
			else if (game->board[i][j] == game->botChar) 
				filledCount--;
		}

		if (filledCount == 2)
		{
			for (int j = 0; j < 3; j++) 
			{
				if (game->board[i][j] == ' ') 
				{
					game->board[i][j] = game->botChar;
					return;
				}
			}
		} 
		else if (filledCount == 1)
		{
			for (int j = 0; j < 3; j++)
			{
				if (game->board[i][j] == ' ')
				{
					game->board[i][j] = game->botChar;
					return;
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) //Check cols
	{
		filledCount = 0;

		for (int j = 0; j < 3; j++) 
		{
			if (game->board[j][i] == game->userChar) 
				filledCount++;
			else if (game->board[j][i] == game->botChar) 
				filledCount--;
		}
		if (filledCount == 2)
		{
			for (int j = 0; j < 3; j++) 
			{
				if (game->board[j][i] == ' ') 
				{
					game->board[j][i] = game->botChar;
					return;
				}
			}
		} 
		else if (filledCount == 1)
		{
			for (int j = 0; j < 3; j++)
			{
				if (game->board[j][i] == ' ')
				{
					game->board[j][i] = game->botChar;
					return;
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) //Mark first empty cell
		for (int j = 0; j < 3; j++)
			if (game->board[i][j] == ' ') 
			{
				game->board[i][j] = game->botChar;
				return;
			}
}

void userTurn(Game* game) 
{
	int a, b;
	std::cout << "Введите ячейку: ";
	std::cin >> a >> b;

	while (a < 1 || a > 3 || b < 1 || b > 3 || game->board[a - 1][b - 1] != ' ') 
	{
		std::cout << "Неверная ячейка\nВыберите ячейку: ";
		std::cin >> a >> b;
	}

	game->board[a - 1][b - 1] = game->userChar;
}

void whoWon(Game* game, int counter) 
{
	if (counter == 3)
		game->status = USER_WIN;
	else if (counter == -3)
		game->status = BOT_WIN;
}

bool updateGame(Game* game) 
{
	int counter;

	for (int i = 0; i < 3; i++) //Check rows
	{
		counter = 0;

		for (int j = 0; j < 3; j++) 
		{
			if (game->board[i][j] == game->userChar) 
				counter++;
			else if (game->board[i][j] == game->botChar) 
				counter--;
		}
		whoWon(game, counter);
	}

	for (int i = 0; i < 3; i++) //Check cols
	{
		counter = 0;

		for (int j = 0; j < 3; j++) 
		{
			if (game->board[j][i] == game->userChar) 
				counter++;
			else if (game->board[j][i] == game->botChar) 
				counter--;
		}
		whoWon(game, counter);
	}

	counter = 0;

	for (int i = 0; i < 3; i++) //Check diag
	{
		if (game->board[i][i] == game->userChar) 
			counter++;
		else if (game->board[i][i] == game->botChar) 
			counter--;
	}

	whoWon(game, counter);

	counter = 0;

	for (int i = 0; i < 3; i++) //Check second diag
	{
		if (game->board[i][2 - i] == game->userChar) 
			counter++;
		else if (game->board[i][2 - i] == game->botChar) 
			counter--;
	}

	whoWon(game, counter);

	if (game->status == PLAY) 
	{
		counter = 0;

		for (int i = 0; i < 3; i++) 
		{
			for (int j = 0; j < 3; j++) 
			{
				if (game->board[i][j] == ' ')
					counter++;
			}
		}

		if (counter == 0) 
		{
			game->status = NOT_WIN;
			return true;
		}

		game->isUserTurn = !game->isUserTurn;
		return false;
	}
	return true;
}
