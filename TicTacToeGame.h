/*
	Author: Dylan Tobia
	File: TicTacToeGame.h
	Purpose: Header file for TIcTacToeGame.cpp, handles all aspects of the Game
*/

#pragma once

#include "ConsoleControls.h"
#include <iostream>
#include <string>
#include <time.h>
#include <random>

enum class EDiff {
	easy,
	medium,
	hard
};

class TTTGame {
public:
	TTTGame();
	void resetGame();
	void resetGame(EDiff, int);
	void flipCoin();
	void printBoard();
	bool checkForWin();
	bool checkForStalemate();
	void playerMove(int);
	void compMove();
	int getFirstMove();
	void playerOneWin();
	void playerTwoWin();
	void win();
	void lose();
	void stalemate();

	EDiff getDifficulty();
	int getPlayers();
	void menu();
	std::string getPlayerOne();
	std::string getPlayerTwo();
private:
	char board[3][3];
	int firstMove;
	int numOfPlayers;
	char playerPiece;
	char playerTwoPiece;
	char compPiece;
	EDiff difficulty;
	std::string playerOneName;
	std::string playerTwoName;


	bool checkForDiags();
	bool checkForHoriz();
	bool checkForVerts();
	bool checkForValidPMove(COORD);
	bool checkForValidCMove(int, int);
	void setPieces(int);
	int howManyPlayers();
	void setDifficulty();
	void setNames();
	void clearError();
	void printError();
};