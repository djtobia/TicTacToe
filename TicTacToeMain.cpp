/*
	Author: Dylan Tobia
	File: TicTacToeGame.cpp
	Purpose: Main file for tic tac toe game
*/

#pragma once

#include <string>
#include <iostream>

#include "TicTacToeGame.h"

TTTGame Game; 

void printIntro();

int main(int argc, char** argv)
{
	
	printIntro();
	Game.howManyPlayers();
	Game.setDifficulty();

	bool again = false;
	while (!again)
	{
		Game.flipCoin();
		again = true;
		//play game

	}

	
	return 0;
}//end main


void printIntro()
{
	std::cout << "Welcome to Tic Tac Toe!" << std::endl;
}