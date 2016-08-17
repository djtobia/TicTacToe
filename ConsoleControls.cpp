#include "ConsoleControls.h"
#include "TicTacToeGame.h"
void resetCursor()
{
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 1;
	pos.Y = 1;
	SetConsoleCursorPosition(stdH, pos);
}

void printError()
{
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 13;

	SetConsoleCursorPosition(stdH, pos);
	std::cout << "Error, Piece already placed there." << std::endl;
	resetCursor();
}

void clearError()
{
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 13;

	SetConsoleCursorPosition(stdH, pos);
	std::cout << "                                  " << std::endl;
	resetCursor();
}

void printPiece(COORD Position, char piece)
{
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X -= 1;
	Position.Y -= 1;
	SetConsoleCursorPosition(stdH, Position);
	if (piece == 'X')
	{
		std::cout << "X X";
		Position.Y += 1;
		SetConsoleCursorPosition(stdH, Position);
		std::cout << " X ";
		Position.Y += 1;
		SetConsoleCursorPosition(stdH, Position);
		std::cout << "X X";

	}
	else if (piece == 'O')
	{
		std::cout << "OOO";
		Position.Y += 1;
		SetConsoleCursorPosition(stdH, Position);
		std::cout << "O O";
		Position.Y += 1;
		SetConsoleCursorPosition(stdH, Position);
		std::cout << "OOO";
	}

	resetCursor();
}

COORD moveCursor()
{
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 1;
	pos.Y = 1;
	int key = 0;
	bool moved = false;
	while (!moved)
	{
		key = _getch();
		switch (key)
		{
		case LEFT_ARROW:
			pos.X -= 4;
			if (pos.X < 1)
			{
				pos.X = 9;
			}
			SetConsoleCursorPosition(stdH, pos);
			break;
		case RIGHT_ARROW:
			pos.X += 4;
			if (pos.X > 9)
			{
				pos.X = 1;
			}
			SetConsoleCursorPosition(stdH, pos);
			break;
		case UP_ARROW:
			pos.Y -= 4;
			if (pos.Y < 1)
			{
				pos.Y = 9;
			}
			SetConsoleCursorPosition(stdH, pos);
			break;
		case DOWN_ARROW:
			pos.Y += 4;
			if (pos.Y > 9)
			{
				pos.Y = 1;
			}
			SetConsoleCursorPosition(stdH, pos);
			break;
		case SPACE:
			moved = true;
			break;
		}

	}
	return pos;
}

void clearConsole()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void printWin()
{
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	clearError();
	pos.X = 0;
	pos.Y = 13;
	SetConsoleCursorPosition(stdH, pos);
	std::cout << "Congratulations, you won!" << std::endl;
}

void printLose()
{
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	clearError();
	pos.X = 0;
	pos.Y = 13;
	SetConsoleCursorPosition(stdH, pos);
	std::cout << "I'm sorry, you lost!" << std::endl;
}

void printStalemate()
{
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	clearError();
	pos.X = 0;
	pos.Y = 13;
	SetConsoleCursorPosition(stdH, pos);
	std::cout << "This game was a stalemate!" << std::endl;
}