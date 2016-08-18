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



//enumeration for difficulties
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
	bool checkForStalemateMove();
	void setPieces(int);
	int howManyPlayers();
	void setDifficulty();
	void setNames();
	void clearError();
	void printError();
	void printHowTo();
	COORD easyCompMove();
	COORD mediumCompMove();
	COORD hardCompMove();
	COORD checkForBlock();
	COORD checkForWinningMove();
	COORD checkForHorizMove(EDiff);
	COORD checkForVertMove(EDiff);
	COORD checkForDiagMove(EDiff);
	COORD moveToStalemate();
};