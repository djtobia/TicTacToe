#pragma once
#include "ConsoleControls.h"
#include "TicTacToeGame.h"

//resets the cursor to position (1,1)
void resetCursor()
{
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 1;
	pos.Y = 1;
	SetConsoleCursorPosition(stdH, pos);
}

//the only function that prints for this header. Sets the cursor and prints the piece for the current move
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

//allows for user to move cursor around the console using the arrow keys
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

//clears the console, taken directly from microsoft bsdn
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

//sets the cursor at position (0,13) where statements and errors are printed.
void setConsoleForStatements()
{
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 13;
	SetConsoleCursorPosition(stdH, pos);
	
}
