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
void playTwoPlayer();
bool playAgain();

int main(int argc, char** argv)
{
	
	printIntro();
	Game.menu();

	bool again = false;
	while (!again)
	{
		Game.flipCoin();
		if (Game.getPlayers() == 2)
		{
			playTwoPlayer();
		}
		else
			playGame();
		again = playAgain();
		if (!again)
		{
			Game.resetGame(Game.getDifficulty(), Game.getPlayers());
		}
	}

	
	return 0;
}//end main

//prints out the intro string
void printIntro()
{
	std::cout << "Welcome to Tic Tac Toe!" << std::endl;

}

//runs game against another person
void playTwoPlayer()
{
	int first = Game.getFirstMove();
	bool gameOver = false;

	clearConsole();
	Game.printBoard();
	while (!gameOver)
	{
		if (first == 0)
		{
			Game.playerMove(0);
			gameOver = Game.checkForWin();
			if (gameOver)
			{
				Game.playerOneWin();
				break;
			}
			gameOver = Game.checkForStalemate();
			if (gameOver)
			{
				Game.stalemate();
				break;
			}
			Game.playerMove(1);
			gameOver = Game.checkForWin();
			if (gameOver)
			{
				Game.playerTwoWin();
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
			Game.playerMove(1);
			gameOver = Game.checkForWin();
			if (gameOver)
			{
				Game.playerTwoWin();
				break;
			}
			gameOver = Game.checkForStalemate();
			if (gameOver)
			{
				Game.stalemate();
				break;
			}
			Game.playerMove(0);
			gameOver = Game.checkForWin();
			if (gameOver)
			{
				Game.playerOneWin();
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

//runs the game against the computer
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
			Game.playerMove(0);
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
			Game.playerMove(0);
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

//prompts the user to play again. Checks for valid input. Returns false if they do want to play again, or true if they do not.
bool playAgain()
{
	bool flag = false;
	std::string answer = "";
	std::cout << "Would you like to play again with all the same settings?" << std::endl;
	
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