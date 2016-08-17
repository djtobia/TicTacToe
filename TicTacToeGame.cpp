#pragma once

#include "TicTacToeGame.h"

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

//promps the user for how many players, and sets the numOfPlayers variable
void TTTGame::howManyPlayers()
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
	}
	else
	{
		std::cout << "Sorry, you called " << answer << " and the coin was not " << answer << ".\nYou will go second!" << std::endl;
	}

	firstMove = coin;
	std::cout << "Press return to continue." << std::endl;
	std::cin.ignore();
	std::cin.get();
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
