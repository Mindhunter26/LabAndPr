#include <iostream>
#include <time.h>
#include "TicTacToe.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	char ch;

	do {
		std::cout << "Выберите x или o: ";
		std::cin >> ch;
	} while (ch != 'x' && ch != 'o');

	Game game = initGame(ch);

	while (!updateGame(&game))
	{
		if (game.isUserTurn)
			userTurn(&game);
		else 
			botTurn(&game);
		updateDisplay(game);
	}

	if (game.status == USER_WIN)
		std::cout << "Вы победили!\n";
	else if (game.status == BOT_WIN)
		std::cout << "Вы проиграли!\n";
	else 
		std::cout << "Ничья!\n";

	system("pause");
}
