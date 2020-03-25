#include "OX.hpp"

void OX::initializeBoard()
{
    for (auto rows = 0; rows < 3; rows++)
    {
        for (auto lines = 0; lines < 3; lines++)
            gameBoard[rows][lines] = '*';
        cout << endl;
    }
}

void OX::showBoard()
{
    for (auto rows = 0; rows < 3; rows++)
    {
        for (auto lines = 0; lines < 3; lines++)
            cout << gameBoard[rows][lines] << " ";
        cout << endl;
    }
}

char OX::getBoardField(int row, int line)
{
    return gameBoard[row][line];
}

void OX::chooseField()
{
    int row, line;
    cout << "Choose Your field (1st - row): ";
    cin >> row;
    cout << "2nd - line: ";
    cin >> line;
    gameBoard[row][line] = player;
    OX::changePlayer();
}

void OX::chooseField(int row, int line)
{
    gameBoard[row][line] = player;
    OX::changePlayer();
}

void OX::changePlayer()
{
    if (player == 'X')
        player = 'O';
    else if (player == 'O')
        player = 'X';
}

char OX::getActuallPlayer()
{
    return player;
}