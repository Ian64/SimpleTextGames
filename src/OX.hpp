#pragma once

#include <iostream>
#include <GameField.hpp>

using namespace std;

class OX
{
public:
    void initializeBoard();
    void showBoard();
    void chooseField();
    void chooseField(int row, int line);
    char getBoardField(int row, int line);
    void changePlayer();
    char getActuallPlayer();
private:
    BoardField boardField;
    char gameBoard[3][3];/* =
    {'1', '2', '3', '4', '5', '6', '7', '8', '9'};*/
    char player = 'X';
};