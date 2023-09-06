/*
	Jayden Wehr
	ChessBoard.h

*/

#pragma once

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard {

private:
	char** boardPtr;
	int boardSize;

	/**
	* placeQueens places the queens on the chessboard so that no queen can attack 
	  each other based on the pseudocode provided.
	* 
	* @param column Queens will be placed at this column and all the columns to 
	*        the right of this column.
	* @return true if all the queens were able to be sucessfully placed on the board
	*         or if we were able to place queens in the designated column and all 
	*		  proceeding columns.
	* @return false if we run into a dead end by not being able to place a queen
	* @pre The board must initially be blank
	* 
	**/
	bool placeQueens(int column);

	/**
	* checkLeftSpaces checks all spaces left of our current position for any queens.  
	* 
	* @param row This is the current row index.
	* @param column This is the current column index.
	* @return true if there is a queen in the way
	* @return false if there is no queen in the way
	* @pre There must not be any queens in the spaces we are checking
	**/
	bool checkLeftSpaces(int row, int column);

	/**
	* checkUpperLeftDiagonals checks all spaces for queens that are in the upper left corner 
	  of our current position on the board
	* 
	*
	* @param row This is the current row index.
	* @param column This is the current column index.
	* @return true if there is a queen in the way
	* @return false if there is no queen in the way
	* @pre There must not be any queens in the spaces we are checking
	**/
	bool checkUpperLeftDiagonals(int row, int column);

	/**
	* checkLowerLeftDiagonals checks all spaces for queens that are in the lower left corner 
	  of our current position in the board.
	* 
	*
	* @param row This is the current row index.
	* @param column This is the current column index.
	* @return true if there is a queen in the way
	* @return false if there is no queen in the way
	* @pre There must not be any queens in the spaces we are checking
	**/
	bool checkLowerLeftDiagonals(int row, int column);

	/**
	* removeLastQueenPlaced removes the last queen placed by traversing through the board
	  column by column.
	*
	* @pre there must be at least one queen on the board
	**/
	void removeLastQueenPlaced();

public:
	ChessBoard();
	ChessBoard(int size);
	~ChessBoard();
	void setSize(int newSize);
	int getSize();

	/**
	* solve solves the N Queens problem via the placeQueens function
	*
	* @return true if the N Queens problem was solved sucessfully
	* @return false if the N Queens problem was unable to be solved
	* @pre The placeQueens funciton must return true
	**/
	bool solve();

	/**
	* displayBoard displays the chess board, showing where the queens are placed
	*
	* @pre boardPtr must not be nullptr
	**/
	void displayBoard();


};

#endif 