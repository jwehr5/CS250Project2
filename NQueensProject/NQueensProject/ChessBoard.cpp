/*
	Jayden Wehr
	ChessBoard.cpp

*/


#include <iostream>
#include "ChessBoard.h"
using namespace std;

ChessBoard::ChessBoard() {

	//Create a chessboard of size 8x8
	boardPtr = new char*[8];
	for (int i = 0; i < 8; i++) {
		boardPtr[i] = new char[8];
	}

	boardSize = 8;

	//Fill the board with blanks
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			boardPtr[i][j] = '*';
		}
	}

}

ChessBoard::ChessBoard(int size) {

	//Create a chessboard of size 4x4
	if (size < 4) {

		boardPtr = new char* [4];
		for (int i = 0; i < 4; i++) {
			boardPtr[i] = new char[4];
		}

		boardSize = 4;

	}
	//Create a chessboard of size 12x12
	else if (size > 12) {

		boardPtr = new char* [12];
		for (int i = 0; i < 12; i++) {
			boardPtr[i] = new char[12];
		}

		boardSize = 12;

	}
	//Create a chessboard of the size that has been passed in
	else {

		boardPtr = new char* [size];
		for (int i = 0; i < size; i++) {
			boardPtr[i] = new char[size];
		}

		boardSize = size;

	}

	//Fill the board with blanks
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			boardPtr[i][j] = '*';
		}
	}


}

ChessBoard::~ChessBoard() {

	if (boardPtr != nullptr) {

		for (int i = 0; i < boardSize; i++) {
			delete boardPtr[i];
		}

		delete[] boardPtr;
	}
}


void ChessBoard::setSize(int newSize) {

	//Delete the exisiting board
	if (boardPtr != nullptr) {

		for (int i = 0; i < boardSize; i++) {
			delete boardPtr[i];
		}

		delete[] boardPtr;
	}

	//Create a chessboard of size 4x4
	if (newSize < 4) {

		boardPtr = new char* [4];
		for (int i = 0; i < 4; i++) {
			boardPtr[i] = new char[4];
		}

		boardSize = 4;

	}
	//Create a chessboard of size 12x12
	else if (newSize > 12) {

		boardPtr = new char* [12];
		for (int i = 0; i < 12; i++) {
			boardPtr[i] = new char[12];
		}

		boardSize = 12;

	}
	//Create a chessboard of the size that has been passed in
	else {

		boardPtr = new char* [newSize];
		for (int i = 0; i < newSize; i++) {
			boardPtr[i] = new char[newSize];
		}

		boardSize = newSize;

	}

	//Fill the board with blanks
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			boardPtr[i][j] = '*';
		}
	}


}

int ChessBoard::getSize() {

	return boardSize;
}

bool ChessBoard::placeQueens(int column) {

	int row = 0;

	if (column >= boardSize) {

		return true;
	}
	else {

		while (row < boardSize) {

			//Check spot to see if its in a path of a queen
			if (!checkLeftSpaces(row,column) && !checkUpperLeftDiagonals(row,column) && !checkLowerLeftDiagonals(row,column)) {

				//If the spot is clear, place the queen
				boardPtr[row][column] = 'Q';

				//Try to place more queens
				 bool isAbleToPlaceAnotherQueen = placeQueens(column + 1);

				if (!isAbleToPlaceAnotherQueen) {

					removeLastQueenPlaced();
					row++;
				}
				else {

					return true;

				}// End-if

			}
			else {

				//Move to the next row 
				row++;

			}// End-if

		}// End While Loop

		return false;

	}// End-if

}


bool ChessBoard::solve() {

	bool solved = false;

	solved = placeQueens(0);

	return solved;
}



bool ChessBoard::checkLeftSpaces(int row, int column) {

	bool queenInTheWay = false;

	//Looking in the left direction
	for (int i = column; i >= 0; i--) {
		if (boardPtr[row][i] == 'Q') {
			queenInTheWay = true;
		}
	}

	return queenInTheWay;

}

bool ChessBoard::checkUpperLeftDiagonals(int row, int column) {

	bool queenInTheWay = false;

	//Checking the upper left diagonals
	int i = row;
	int j = column;
	while (i >= 0 && j >= 0) {
		if (boardPtr[i][j] == 'Q') {
			queenInTheWay = true;
		}

		//To traverse the spaces in the upper left corner, subtract our row and column position by 1
		i--;
		j--;
	}

	return queenInTheWay;
}

bool ChessBoard::checkLowerLeftDiagonals(int row, int column) {

	bool queenInTheWay = false;

	//Checking the lower left diagonals
	int i = row;
	int j = column;
	while (i < boardSize && j >= 0) {
		if (boardPtr[i][j] == 'Q') {
			queenInTheWay = true;
		}

		/*
		* To traverse the spaces in the lower left corner, add our row postion by 1
		  and subtract our column position by 1
		*/
		i++;
		j--;
	}

	return queenInTheWay;
}

void ChessBoard::removeLastQueenPlaced() {

	int row = -1;
	int column = -1;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			
			//We will traverse down the board vertically instead of horizontally
			if (boardPtr[j][i] == 'Q') {
				row = j;
				column = i;
			}
		}
	}

	if (row > -1 && column > -1) {
		boardPtr[row][column] = '*';
	}
}

void ChessBoard::displayBoard() {

	if (boardPtr != nullptr) {

		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				cout << boardPtr[i][j] << " ";
			}
			cout << endl;
		}
	}

	

}