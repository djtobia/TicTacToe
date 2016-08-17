/*
	Author: Dylan Tobia
	File: TicTacToeGame.cpp
	Purpose: "Driver" file for tic tac toe game
*/

#pragma once

#include <string>
#include <iostream>

#include "TicTacToeGame.h"

TTTGame Game; 

void printIntro();
void playGame();
bool playAgain();

int main(int argc, char** argv)
{
	
	printIntro();
	Game.howManyPlayers();
	Game.setDifficulty();

	bool again = false;
	while (!again)
	{
		Game.flipCoin();
		playGame();
		again = playAgain();
		if (!again)
		{
			Game.resetGame(Game.getDifficulty(), Game.getPlayers());
		}
	}

	
	return 0;
}//end main


void printIntro()
{
	std::cout << "Welcome to Tic Tac Toe!" << std::endl;

}

void playGame()
{
	int first = Game.getFirstMove();
	bool gameOver = false;

	clearConsole();
	Game.printBoard();
	while (!gameOver)
	{
		if (first == 0)
		{
			Game.playerMove();
			gameOver = Game.checkForWin();
			if (gameOver)
			{
				Game.win();
				break;
			}
			gameOver = Game.checkForStalemate();
			if (gameOver)
			{
				Game.stalemate();
				break;
			}
			Game.compMove();
			gameOver = Game.checkForWin();
			if (gameOver)
			{
				Game.lose();
				break;
			}
			gameOver = Game.checkForStalemate();
			if (gameOver)
			{
				Game.stalemate();
				break;
			}
		}
		else
		{
			Game.compMove();
			gameOver = Game.checkForWin();
			if (gameOver)
			{
				Game.lose();
				break;
			}
			gameOver = Game.checkForStalemate();
			if (gameOver)
			{
				Game.stalemate();
				break;
			}
			Game.playerMove();
			gameOver = Game.checkForWin();
			if (gameOver)
			{
				Game.win();
				break;
			}
			gameOver = Game.checkForStalemate();
			if (gameOver)
			{
				Game.stalemate();
				break;
			}
		}
	}
}

bool playAgain()
{
	bool flag = false;
	std::string answer = "";
	std::cout << "Would you like to play again with the exact same difficulty?" << std::endl;
	
	while (!flag)
	{
		std::cin >> answer;

		for (int i = 0; i < answer.length(); i++)
		{
			answer[i] = tolower(answer[i]);
		}

		if (answer.compare("y") == 0 || answer.compare("yes") == 0)
		{
			return false;
		}
		else if (answer.compare("n") == 0 || answer.compare("no") == 0)
		{
			return true;
		}
		else
		{
			std::cout << "Error, that is an invalid answer. Type yes, or no." << std::endl;
		}
	}
}