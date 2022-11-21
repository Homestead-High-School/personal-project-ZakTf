#include "Board.h"
#include <iostream>

Board::Board() {
	for (int i = 0; i < sizeof(board)/sizeof(board[0]); i++) {
		for (int j = 0; j < sizeof(board[i]); j++) {
			board[i][j] = '-';
		}
	}
	gameStatus = false;
	turn = 0;
	tie = false;
}
void Board::printBoard() {
	int count = 1;
	int count2 = 1;
	for (int i = 0; i < sizeof(board)/sizeof(board[0]); i++) {
		std::cout << "   " << count << " ";
		for (int j = 0; j < sizeof(board[i]); j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
		count++;
	}
	std::cout << "    1 2 3" << "\n";
}
void Board::takeTurn(int row, int col) {
	row -= 1;
	col -= 1;
	if (board[row][col] != '-') {
		std::cout << "   You can't go there!" << "\n";
		return;
	}
	if (turn % 2 == 0) {
		board[row][col] = 'X';
	}
	else {
		board[row][col] = 'O';
	}
	checkWinFull();
	if (gameStatus == true) {
		return;
	}
	turn++;
}
bool Board::getStatus() {
	return gameStatus;
}
int Board::getTurn() {
	return turn;
}
void Board::checkWinFull() {
	for (int i = 0; i < sizeof(board) / sizeof(board[0]); i++) {
		for (int j = 0; j < sizeof(board[i]); j++) {
			if (board[i][j] == '-') {
				checkWin();
				return;
			}
		}
	}
	checkWin();
	if (gameStatus == true) {
		return;
	}
	tie = true;
}
void Board::checkWin() {
	int count = 0;
	int count2 = 0;
	for (int i = 0; i < sizeof(board) / sizeof(board[0]); i++) {
		for (int j = 0; j < sizeof(board[i]); j++) {
			if (board[i][j] == 'X') {
				count++;
			}
			else if (board[i][j] == 'O') {
				count2++;
			}
		}
		if (count == 3 || count2 == 3) {
			gameStatus = true;
			return;
		}
		else {
			count = 0;
			count2 = 0;
		}
	}
	for (int i = 0; i < sizeof(board) / sizeof(board[0]); i++) {
		for (int j = 0; j < sizeof(board[i]); j++) {
			if (board[j][i] == 'X') {
				count++;
			}
			else if (board[j][i] == 'O') {
				count2++;
			}
		}
		if (count == 3 || count2 == 3) {
			gameStatus = true;
			return;
		}
		else {
			count = 0;
			count2 = 0;
		}
	}
	int column = 0;
	for (int i = 0; i < sizeof(board) / sizeof(board[0]); i++) {
		if (board[i][column] == 'X') {
			count++;
		}
		else if (board[i][column] == 'O') {
			count2++;
		}
		column++;
	}
	if (count == 3 || count2 == 3) {
		gameStatus = true;
		return;
	}
	else {
		count = 0;
		count2 = 0;
	}
	column = 2;
	for (int i = 0; i < sizeof(board) / sizeof(board[0]); i++) {
		if (board[i][column] == 'X') {
			count++;
		}
		else if (board[i][column] == 'O') {
			count2++;
		}
		column--;
	}
	if (count == 3 || count2 == 3) {
		gameStatus = true;
		return;
	}
	else {
		count = 0;
		count2 = 0;
	}
}
bool Board::getTie() {
	return tie;
}