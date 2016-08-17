#pragma once

#include "TicTacToeGame.h"
#include "ConsoleControls.h"

TTTGame::TTTGame()
{
	resetGame();
}



//resets all the variables in the game
void TTTGame::resetGame()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '\0';
		}
	}

	firstMove = 0;
	playerPiece = '\0';
	compPiece = '\0';
	numOfPlayers = 0;
	difficulty = EDiff::easy;

}

void TTTGame::resetGame(EDiff sameDiff, int players)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '\0';
		}
	}

	firstMove = 0;
	playerPiece = '\0';
	compPiece = '\0';
	numOfPlayers = players;
	difficulty = sameDiff;
}

//promps the user for how many players, and sets the numOfPlayers variable
int TTTGame::howManyPlayers()
{
	
	char answer = 0;
	bool check = false;
	while (!check)
	{
		std::cout << "How many players, 1 or 2?" << std::endl;
		std::cin >> answer;
		if (answer < 49|| answer > 50)
		{
			std::cout << "Error, you entered an invalid number. Please try again." << std::endl;
		}
		else if (answer == 49)
		{
			std::cout << "It will be you vs. the computer." << std::endl;
			check = true;
		}
		else if (answer == 50)
		{
			std::cout << "It will be you vs. your friend." << std::endl;
			check = true;
		}
	}
	
	numOfPlayers = (int)answer - 48;
	return numOfPlayers;
}

//prompts the user for which difficulty they want, and sets the difficulty variable
void TTTGame::setDifficulty()
{
	
	std::string answer = "";
	bool check = false;
	while (!check)
	{
		std::cout << "Which difficulty would you like, easy, medium, or hard?" << std::endl;
		std::cin >> answer;
		//convert answer to lowercase.
		for (int i = 0; i < answer.length(); i++)
		{
			answer[i] = tolower(answer[i]);
		}
		//check for what was input
		if (answer.compare("easy") == 0)
		{
			difficulty = EDiff::easy;
			check = true;
		}
		else if (answer.compare("medium") == 0)
		{
			difficulty = EDiff::medium;
			check = true;
		}
		else if (answer.compare("hard") == 0)
		{
			difficulty = EDiff::hard;
			check = true;
		}
		else
		{
			std::cout << "Error, you have entered an invalid answer. Please try again." << std::endl;
		}
	}
	
}

//uses a random number between 0 and 1 to "flip" a coin. User chooses heads or tails, if num is 0, heads was flipped etc. If the user guesses correctly, they go first.
void TTTGame::flipCoin()
{
	srand(time(NULL));
	std::string answer = "";
	int check = 0, coin = 0;
	std::cout << "We will flip a coin to see who goes first. Call it, heads or tails?" << std::endl;
	bool flipped = false;
	while (!flipped)
	{
		std::cin >> answer;
		//convert answer to lowercase.
		for (int i = 0; i < answer.length(); i++)
		{
			answer[i] = tolower(answer[i]);
		}

		if (answer.compare("heads") == 0)
		{
			check = 0;
			flipped = true;
		}
		else if (answer.compare("tails") == 0)
		{
			check = 1;
			flipped = true;
		}
		else
		{
			std::cout << "Error, you have entered an invalid answer. Please try again." << std::endl;
		}
	}

	coin = rand() % 2;
	if (check == coin)
	{
		std::cout << "Awesome! You called " << answer << " and the coin was " << answer << ".\nYou will go first!" << std::endl;
		firstMove = 0;
	}
	else
	{
		std::cout << "Sorry, you called " << answer << " and the coin was not " << answer << ".\nYou will go second!" << std::endl;
		firstMove = 1;
	}

	
	setPieces(firstMove);
	std::cout << "Press return to continue." << std::endl;
	std::cin.ignore();
	std::cin.get();
}

void TTTGame::setPieces(int firstMove)
{
	if (firstMove == 0)
	{
		playerPiece = 'X';
		compPiece = 'O';
	}
	else
	{
		playerPiece = 'O';
		compPiece = 'X';
	}
}
//prints out the game board.
void TTTGame::printBoard()
{
	//print out board
	std::cout	<< "   |   |   \n"
				<< "   |   |   \n"
				<< "   |   |   \n"
				<< "-----------\n"
				<< "   |   |   \n"
				<< "   |   |   \n"
				<< "   |   |   \n"
				<< "-----------\n"
				<< "   |   |   \n"
				<< "   |   |   \n"
				<< "   |   |   \n";


}

//calls all three functions to check for possible wins
bool TTTGame::checkForWin()
{
	
	if (checkForHoriz())
		return true;
	else if (checkForVerts())
		return true;
	else if (checkForDiags())
		return true;
	else
		return false;

}

//checks all horizontal lines of the board for a win
bool TTTGame::checkForHoriz()
{

	int xCount = 0, oCount = 0;
	for (int i = 0; i < 3; i++)
	{
		xCount = 0;
		oCount = 0;
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X')
			{
				xCount++;
			}
			else if (board[i][j] == 'O')
			{
				oCount++;
			}

			if (xCount == 3 || oCount == 3)
			{
				return true;
			}
		}

	}

	return false;
}

//checks all verticle lines of the board for a win
bool TTTGame::checkForVerts()
{

	int xCount = 0, oCount = 0;
	for (int i = 0; i < 3; i++)
	{
		xCount = 0;
		oCount = 0;
		for (int j = 0; j < 3; j++)
		{
			if (board[j][i] == 'X')
			{
				xCount++;
			}
			else if (board[j][i] == 'O')
			{
				oCount++;
			}

			if (xCount == 3 || oCount == 3)
			{
				return true;
			}
		}

	}

	return false;
}

//checks for a valid player move
bool TTTGame::checkForValidPMove(COORD pos)
{
	if (board[pos.Y / 4][pos.X / 4] == '\0')
	{
		clearError();
		return true;
	}
	else
	{
		printError();
		return false;
	}
}

//checks for a valid computer move
bool TTTGame::checkForValidCMove(int xCord, int yCord)
{
	if (board[xCord][yCord] == '\0')
	{
		return true;
	}
	else
		return false;
}

//checks both diagonals of the board for a win
bool TTTGame::checkForDiags()
{
	int xCount = 0, oCount = 0;

	for (int i = 0, j = 0; i < 3, j < 3; i++, j++)
	{
		
		if (board[i][j] == 'X')
		{
			xCount++;
		}
		else if (board[i][j] == 'O')
		{
			oCount++;
		}

		if (xCount == 3 || oCount == 3)
		{
			return true;
		}
	}

	xCount = 0;
	oCount = 0;
	for (int i = 0, j = 2; i < 3, j >= 0; i++, j--)
	{
		
		if (board[i][j] == 'X')
		{
			xCount++;
		}
		else if (board[i][j] == 'O')
		{
			oCount++;
		}

		if (xCount == 3 || oCount == 3)
		{
			return true;
		}
	}
	return false;
}

//checks if all squares of the board are taken, but there are no wins.
bool TTTGame::checkForStalemate()
{

	int xCount = 0, oCount = 0;
	for (int i = 0; i < 3; i++)
	{
		
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X')
			{
				xCount++;
			}
			else if (board[i][j] == 'O')
			{
				oCount++;
			}

			if (xCount + oCount == 9)
			{
				return true;
			}
		}

	}

	return false;
}

//handles all aspects of player movement and placement
void TTTGame::playerMove()
{
	COORD pos;
	resetCursor();
	bool valid = false;;
	while (!valid)
	{
		pos = moveCursor();
		valid = checkForValidPMove(pos);
	}

	int xCord = pos.Y / 4, yCord = pos.X / 4;
	board[xCord][yCord] = playerPiece;
	printPiece(pos, playerPiece);
}

//check for valid computer move, if valid set it on the board and print it in its right coordinate.
void TTTGame::compMove()
{
	bool valid = false;
	int xCord = 0, yCord = 0;
	COORD position;
	srand(time(NULL));
	while (!valid)
	{
		xCord = rand() % 3;
		yCord = rand() % 3;
		if (checkForValidCMove(xCord, yCord))
		{
			valid = true;
		}
	}
	
	board[xCord][yCord] = compPiece;
	if (xCord == 0)
	{
		position.Y = 1;
	}
	else if (xCord == 1)
	{
		position.Y = 5;
	}
	else if (xCord = 2)
	{
		position.Y = 9;
	}

	if (yCord == 0)
	{
		position.X = 1;
	}
	else if (yCord == 1)
	{
		position.X = 5;
	}
	else if (yCord == 2)
	{
		position.X = 9;
	}
	
	printPiece(position, compPiece);
}

//returns firstMove variable
int TTTGame::getFirstMove()
{
	return firstMove;
}

//returns numOfPlayers variable
int TTTGame::getPlayers()
{
	return numOfPlayers;
}

//prints and handles menu for game
void TTTGame::menu()
{
	int players = 0, option = 0;
	bool diffFlag = false, menuFlag = false;
	std::string input = "";
	while (!menuFlag)
	{
		std::cout << "\n1. Number of Players.\n\n"
			<< "2. Set difficulty.\n\n"
			<< "3. Play game. (Only available if both 1 and 2 are complete, or if there is 2 players)" << std::endl;
		
		std::cin >> input;
		if (input.compare("1") == 0)
		{
			option = 1;
		}
		else if (input.compare("2") == 0)
		{
			option = 2;
		}
		else if (input.compare("3") == 0)
		{
			option = 3;
		}
		else
		{
			std::cout << "Error, invalid input. Enter 1, 2, or 3." << std::endl;
		}
		switch (option)
		{
		case 1:
			players = howManyPlayers();
			break;
		case 2:
			setDifficulty();
			diffFlag = true;
			break;
		case 3:
			if (players == 2)
			{
				return;
			}
			else if (players == 1 && diffFlag == true)
			{
				return;
			}
			else
			{
				std::cout << "Error, you must set the amount of players and the difficulty for 1 player mode first." << std::endl;
			}
			break;
		}
	}
}

//returns diffculty variable
EDiff TTTGame::getDifficulty()
{
	return difficulty;
}

//prints the win prompt
void TTTGame::win()
{
	printWin();
}

//prints the lose prompt
void TTTGame::lose()
{
	printLose();
}

//prints the stalemate prompt
void TTTGame::stalemate()
{
	printStalemate();
}
