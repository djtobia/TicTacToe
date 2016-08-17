#pragma once

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
	void howManyPlayers();
	void setDifficulty();
	void flipCoin();
	void printBoard();
private:
	char board[3][3];
	int firstMove;
	int numOfPlayers;
	char playerPiece;
	char compPiece;
	EDiff difficulty;

};