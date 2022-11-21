#pragma once
#include <iostream>

class Board {
	char board[3][3]; //row, column
	bool gameStatus;
	int turn;
	bool tie;

public:
	Board();
	void printBoard();
	void takeTurn(int row, int col);
	bool getStatus();
	void checkWinFull();
	void checkWin();
	int getTurn();
	bool getTie();
};