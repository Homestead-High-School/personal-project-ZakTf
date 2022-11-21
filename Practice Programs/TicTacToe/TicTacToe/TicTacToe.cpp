#include <iostream>
#include "Board.h"
#include <windows.h>
#include <cwchar>

inline
void turn(Board b) {
	std::cout << "\n";
	if (b.getTurn() % 2 == 0) {
		std::cout << "   It is player one's turn: " << "\n";
	}
	else {
		std::cout << "   It is player two's turn: " << "\n";
	}
	b.printBoard();
}

int main()
{
	//change size and font
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0; //width
	cfi.dwFontSize.Y = 25; //height
	
	cfi.FontFamily = FF_SCRIPT;
	cfi.FontWeight = 700;
	std::wcscpy(cfi.FaceName, L"Script"); //font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
	//change color
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13); //color attribute
	

	Board b;
	std::cout << "\n\n" << "   Welcome to the tic-tac-toe game!" << "\n\n";
	std::cout << "\n";
	std::cout << "   It is player one's turn: " << "\n";
	b.printBoard();
	while (b.getStatus() == false && b.getTie() == false) {
		if (b.getStatus() == true) {
			break;
		}
		int row;
		int col;
		std::cout << "\n";
		std::cout << "   Enter a row: ";
		std::cin >> row;
		std::cout << "   Enter a column: ";
		std::cin >> col;
		std::cout << "\n";
		b.takeTurn(row, col);
		turn(b);
	}
	int x = 0;
	if (b.getTurn() % 2 == 0) {
		x = 1;
	}
	else {
		x = 2;
	}
	if (b.getStatus() == true) {
		std::cout << "\n" << "   Player " << x << " wins!";
	}
	else if (b.getTie() == true) {
		std::cout << "\n" << "   It's a tie!";
	}
}