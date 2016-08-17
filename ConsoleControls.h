/*
	Author: Dylan Tobia
	File: ConsoleControls.h
	Purpose: Header file for ConsoleControls.cpp, all functions have to do with the cursor position and movement
			The only function that actually writes anything to the console is the printPiece function, which was just easier
			to have it print in this function, instead of having to move back and forth over and over again.
*/

#pragma once


#include <conio.h>
#include <Windows.h>
#include <string>
#include <iostream>

//definitions for keyboard presses
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define SPACE 32

void clearConsole();
void resetCursor();
void printPiece(COORD, char);
COORD moveCursor();
void setConsoleForStatements();
