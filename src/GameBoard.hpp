#pragma once

#include <vector>
#include <iostream>
#include <GameField.hpp>

using namespace std;

class GameBoard
{
public:
    GameBoard();
    GameBoard(int numberOfFields);
    GameBoard(int numberOfFields, char boardDefaultField);
    char getBoardField(int row,int line);
    void setBoardField(int row,int line, char field);
    void setBoardField(pair<unsigned, unsigned> position, char field);
    void showBoard();
    void fillGameBoardLine(int numberOfChars, char value);
    //~GameBoard();
protected:
    vector<vector<char>> gameBoard;
};
