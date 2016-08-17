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
	playerTwoPiece = '\0';
	compPiece = '\0';
	numOfPlayers = 0;
	playerOneName = "";
	playerTwoName = "";
	difficulty = EDiff::easy;

}

//resets all variables in the game except for player names. Keeps all the same settings that pertain to playing game again.
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
	playerTwoPiece = '\0';
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
			setNames();
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
		for (size_t i = 0; i < answer.length(); i++)
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
	srand((unsigned int)time(NULL));
	std::string answer = "";
	int check = 0, coin = 0;
	std::cout << "We will flip a coin to see who goes first. Call it, heads or tails?" << std::endl;
	bool flipped = false;
	while (!flipped)
	{
		std::cin >> answer;
		//convert answer to lowercase.
		for (size_t i = 0; i < answer.length(); i++)
		{
			answer[i] = tolower(answer[i]);
		}

		if (answer.compare("heads") == 0 || answer.compare("h") == 0)
		{
			check = 0;
			flipped = true;
		}
		else if (answer.compare("tails") == 0 || answer.compare("t") == 0)
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
	if (numOfPlayers == 1)
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
	else
	{
		if (firstMove == 0)
		{
			playerPiece = 'X';
			playerTwoPiece = 'O';
		}
		else
		{
			playerPiece = 'O';
			playerTwoPiece = 'X';
		}
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
void TTTGame::playerMove(int move)
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
	if (move == 0)
	{
		printPiece(pos, playerPiece);
		board[xCord][yCord] = playerPiece;
	}
	else
	{
		board[xCord][yCord] = playerTwoPiece;
		printPiece(pos, playerTwoPiece);
	}
}

//check for valid computer move, if valid set it on the board and print it in its right coordinate.
void TTTGame::compMove()
{
	bool valid = false;
	CompCords cords;
	cords.xCord = 0;
	cords.yCord = 0;
	COORD position;

	srand((unsigned int)time(NULL));
	while (!valid)
	{
		
		if (difficulty == EDiff::medium)
		{
			cords = mediumCompMove();
		}
		else if (difficulty == EDiff::hard)
		{
			cords = hardCompMove();
		}
		else
		{
			cords = easyCompMove();
		}
		
		if (checkForValidCMove(cords.xCord, cords.yCord))
		{
			valid = true;
		}
		else if (checkForStalemateMove())
		{
			cords = moveToStalemate();
			valid = true;
		}
	}
	
	board[cords.xCord][cords.yCord] = compPiece;
	if (cords.xCord == 0)
	{
		position.Y = 1;
	}
	else if (cords.xCord == 1)
	{
		position.Y = 5;
	}
	else if (cords.xCord = 2)
	{
		position.Y = 9;
	}

	if (cords.yCord == 0)
	{
		position.X = 1;
	}
	else if (cords.yCord == 1)
	{
		position.X = 5;
	}
	else if (cords.yCord == 2)
	{
		position.X = 9;
	}
	
	printPiece(position, compPiece);
}

//checks if there is only one move left for the computer that is for the stalemate, returns true if true.
//This is because if it came down to the last move being a stalemate, the computer didn't always find it moving randomly
bool TTTGame::checkForStalemateMove()
{
	int pieceCount = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != '\0')
			{
				pieceCount++;
			}
		}
	}

	if (pieceCount == 8)
	{
		return true;
	}

	return false;

}

//finds the coordinate of the stalemate space for the computer
CompCords TTTGame::moveToStalemate()
{
	CompCords pos;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '\0')
			{
				pos.xCord = i;
				pos.yCord = j;
			}
		}
	}


	return pos;

}

//makes computer move randomly
CompCords TTTGame::easyCompMove()
{
	CompCords pos;
	srand((unsigned int)time(NULL));

	pos.xCord = rand() % 3;
	pos.yCord = rand() % 3;
	return pos;
}

//computer will try to block a win, otherwise will move randomly
CompCords TTTGame::mediumCompMove()
{
	CompCords pos;
	//check for block, if none, call easyCompMove
	pos = checkForBlock();
	if(pos.xCord == -1)
	{ 
		pos = easyCompMove();

	}

	return pos;
}

//computer will try to WIN, if it cant win it will try to block, if it cant block, will move randomly
CompCords TTTGame::hardCompMove()
{
	CompCords pos;
	//checkForWin, if none, checkForBlock, if none, call easyCompMove
	pos = checkForWinningMove();
		if(pos.xCord == -1)
		{
			pos = checkForBlock();
			if(pos.xCord == -1)
			{
				pos = easyCompMove();
			}
		}
	
	return pos;
}

//checks for horizontal, then verticle, then diagonal blocks. If there isnt one, returns (-1,-1)
CompCords TTTGame::checkForBlock()
{
	CompCords pos;
	EDiff specialCase = EDiff::medium;
	pos = checkForHorizMove(specialCase);
	if (pos.xCord == -1)
	{
		pos = checkForVertMove(specialCase);
		if (pos.xCord == -1)
		{
			pos = checkForDiagMove(specialCase);
		}
	}
	
	return pos;
}

//steps through all of the different move functions, if there is no win, returns (-1,-1)
CompCords TTTGame::checkForWinningMove()
{
	EDiff specialCase = EDiff::hard;
	CompCords pos;
	
	pos = checkForHorizMove(specialCase);
	if (pos.xCord == -1)
	{			
		pos = checkForVertMove(specialCase);
		if (pos.xCord == -1)
		{
			pos = checkForDiagMove(specialCase);
		}
	}
	

	return pos;
}

//steps through the board horizontally, if the playerpiece count ever equals 2, checks if it can block or win (depeniding on specialCase). If it cannot, returns (-1,-1)
CompCords TTTGame::checkForHorizMove(EDiff specialCase)
{
	CompCords pos;
	int playerCount = 0, compCount = 0;
	//steps through rows
	for (int i = 0; i < 3; i++)
	{
		playerCount = 0;
		compCount = 0;
		//steps through columns
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == playerPiece)
			{
				playerCount++;
			}
			else if (board[i][j] == compPiece)
			{
				compCount++;
			}

			//specialCase changes depending on if checkForWinningMove has already been checked or not
			if (specialCase == EDiff::medium)
			{
				if (playerCount == 2 && compCount == 0)
				{
					//checks if there is an empty spot to move to, if there is sets the cords for that move and returns
					for (int k = 0; k < 3; k++)
					{
						if (board[i][k] == '\0')
						{
							pos.xCord = i;
							pos.yCord = k;
							return pos;
						}
					}
				}
			}
			else if (specialCase == EDiff::hard)
			{
				if (compCount == 2 && playerCount == 0)
				{
					for (int k = 0; k < 3; k++)
					{
						if (board[i][k] == '\0')
						{
							pos.xCord = i;
							pos.yCord = k;
							return pos;
						}
					}
				}
			}

		}
	}
	//if there is no block or winning move to make, sets the cords to (-1,-1), and returns them
	pos.xCord = -1;
	pos.yCord = -1;
	return pos;
}

//checks for verticle blocks/wins (depending on specialCase). if there is one, returns that coordinate, if not returns (-1,-1)
CompCords TTTGame::checkForVertMove(EDiff specialCase)
{
	CompCords pos;
	int playerCount = 0, compCount = 0;
	//steps through rows
	for (int i = 0; i < 3; i++)
	{
		playerCount = 0;
		compCount = 0;
		//steps through columns
		for (int j = 0; j < 3; j++)
		{
			if (board[j][i] == playerPiece)
			{
				playerCount++;
			}
			else if (board[j][i] == compPiece)
			{
				compCount++;
			}

			//specialCase changes depending on if checkForWinningMove has already been checked or not
			if (specialCase == EDiff::medium)
			{
				if (playerCount == 2 && compCount == 0)
				{
					//checks if there is an empty spot to move to, if there is sets the cords for that move and returns
					for (int k = 0; k < 3; k++)
					{
						if (board[k][i] == '\0')
						{
							pos.xCord = k;
							pos.yCord = i;
							return pos;
						}
					}
				}
			}
			else if (specialCase == EDiff::hard)
			{
				if (compCount == 2 && playerCount == 0)
				{
					for (int k = 0; k < 3; k++)
					{
						if (board[k][i] == '\0')
						{
							pos.xCord = k;
							pos.yCord = i;
							return pos;
						}
					}
				}
			}

		}
	}
	//if there is no block or winning move to make, sets the cords to (-1,-1), and returns them
	pos.xCord = -1;
	pos.yCord = -1;
	return pos;
}

//checks for diagonal blocks/wins (depending on specialCase). if there is one, returns that coordinate, if not returns (-1,-1)
CompCords TTTGame::checkForDiagMove(EDiff specialCase)
{
	CompCords pos;
	int playerCount = 0, compCount = 0;
	for (int i = 0, j = 0; i < 3; i++, j++)
	{
		if (board[i][j] == playerPiece)
		{
			playerCount++;
		}
		else if (board[i][j] == compPiece)
		{
			compCount++;
		}

		if (specialCase == EDiff::medium)
		{
			if (playerCount == 2 && compCount == 0)
			{
				for (int k = 0, l = 0; k < 3; k++, l++)
				{
					if (board[k][l] == '\0')
					{
						pos.xCord = k;
						pos.yCord = l;
						return pos;
					}
				}
			}
		}
		else if (specialCase == EDiff::hard)
		{
			if (compCount == 2 && playerCount == 0)
			{
				for (int k = 0, l = 0; k < 3; k++, l++)
				{
					if (board[k][l] == '\0')
					{
						pos.xCord = k;
						pos.yCord = l;
						return pos;
					}
				}
			}
		}
	}

	playerCount = 0;
	compCount = 0;

	for (int i = 0, j = 2; i < 3; i++, j--)
	{
		if (board[i][j] == playerPiece)
		{
			playerCount++;
		}
		else if (board[i][j] == compPiece)
		{
			compCount++;
		}

		if (specialCase == EDiff::medium)
		{
			if (playerCount == 2 && compCount == 0)
			{
				for (int k = 0, l = 2; k < 3; k++, l--)
				{
					if (board[k][l] == '\0')
					{
						pos.xCord = k;
						pos.yCord = l;
						return pos;
					}
				}
			}
		}
		else if (specialCase == EDiff::hard)
		{
			if (compCount == 2 && playerCount == 0)
			{
				for (int k = 0, l = 2; k < 3; k++, l--)
				{
					if (board[k][l] == '\0')
					{
						pos.xCord = k;
						pos.yCord = l;
						return pos;
					}
				}
			}
		}
	}
	pos.xCord = -1;
	pos.yCord = -1;
	return pos;
}
//returns firstMove variable
int TTTGame::getFirstMove()
{
	return firstMove;
}

//prints out the win statement for player one in two player game
void TTTGame::playerOneWin()
{
	setConsoleForStatements();
	std::cout << playerOneName << " wins!" << std::endl;
}

//prints out win statement for player two in two player game
void TTTGame::playerTwoWin()
{
	setConsoleForStatements();
	std::cout << playerTwoName << " wins!" << std::endl;
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
	setConsoleForStatements();
	std::cout << "Congratulations, you won!" << std::endl;
}

//prints the lose prompt
void TTTGame::lose()
{
	setConsoleForStatements();
	std::cout << "I'm sorry, you lost!" << std::endl;
}

//prints the stalemate prompt
void TTTGame::stalemate()
{
	setConsoleForStatements();
	std::cout << "This game was a stalemate!" << std::endl;
}

//sets the names of player one and player two for two player game
void TTTGame::setNames()
{
	std::cout << "Enter player number one's name." << std::endl;
	std::cin >> playerOneName;
	std::cout << "Enter player number two's name." << std::endl;
	std::cin >> playerTwoName;
}

//returns playerOneName variable
std::string TTTGame::getPlayerOne()
{
	return playerOneName;
}

//returns playerTwoName variable
std::string TTTGame::getPlayerTwo()
{
	return playerTwoName;
}

//clears any error messages
void TTTGame::clearError()
{
	setConsoleForStatements();
	std::cout << "                                  " << std::endl;
	resetCursor();
}

//prints out an error message when a piece is already in that coordinate
void TTTGame::printError()
{
	setConsoleForStatements();
	std::cout << "Error, piece already placed there." << std::endl;
	resetCursor();
}