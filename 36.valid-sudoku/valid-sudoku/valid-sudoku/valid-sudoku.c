#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LeetCodeBox.h"

char sudu[9][9] = {
{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};

char sudu2[9][9] = {
    {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};

bool isValidSudoku(char board[][9], int boardSize, int* boardColSize) {
    bool rowFlag[9][10] = { 0 };
    bool collag[9][10] = { 0 };
    bool boxFlag[9][10] = { 0 };
    char cur;

    uchar rowSize = boardSize / *boardColSize;
    uchar colSize = *boardColSize;
    uchar boxSize = (rowSize / 3) * (colSize / 3);

    uchar row = 0, col = 0, box = 0;

    for (row = 0; row < rowSize; row++)
    {
        for (col = 0; col < colSize; col++)
        {
            if ('.' == board[row][col]) continue;
            cur = board[row][col] - '0';
            box = (row / 3) * 3 + (col / 3);
            if (rowFlag[row][cur]) return false;
            if (collag[col][cur]) return false;
            if (boxFlag[box][cur]) return false;

            rowFlag[row][cur] = true;
            collag[col][cur] = true;
            boxFlag[box][cur] = true;
        }
    }

    return true;
}

int main(void)
{
    bool ret = false;
    uint i = 0;
    int suduRowSize = ARRAY_SIZE(sudu);
    int suduSize = sizeof(sudu);

    printf("sudoSize = %d, suduRowSize = %d\n", suduSize, suduRowSize);

    ret = isValidSudoku(sudu2, suduSize, &suduRowSize);
    
    printf("ret = %d\n", ret);

    return true;
}