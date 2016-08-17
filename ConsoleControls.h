/*
	Author: Dylan Tobia
	File: ConsoleControls.h
	Purpose: Header file for ConsoleControls.cpp, all functions have to do with the cursor position and movement
*/

#pragma once


#include <conio.h>
#include <Windows.h>
#include <string>
#include <iostream>


#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define SPACE 32




void clearConsole();
void resetCursor();
void printError();
void clearError();
void printWin();
void printLose();
void printStalemate();
void printPiece(COORD, char);
COORD moveCursor();
