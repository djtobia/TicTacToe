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
	void howManyPlayers();
	void setDifficulty();
	void flipCoin();
	void printBoard();
	bool checkForWin();
	bool checkForStalemate();
	void playerMove();
	void compMove();
	int getFirstMove();
	void win();
	void lose();
	void stalemate();

	EDiff getDifficulty();
	int getPlayers();
private:
	char board[3][3];
	int firstMove;
	int numOfPlayers;
	char playerPiece;
	char compPiece;
	EDiff difficulty;

	bool checkForDiags();
	bool checkForHoriz();
	bool checkForVerts();
	bool checkForValidPMove(COORD);
	bool checkForValidCMove(int, int);
	void setPieces(int);

};