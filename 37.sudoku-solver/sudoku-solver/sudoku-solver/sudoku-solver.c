#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LeetCodeBox.h"

bool rowMask[9][9] = { false };
bool colMask[9][9] = { false };
bool boxMask[9][9] = { false };
int indexMask[9 * 9] = { 0 };
int indexSize = 0;
bool valid = false;

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

void dfs(char board[][9], int pos)
{
    if (indexSize == pos)
    {
        valid = true;
        return;
    }

    uchar row = indexMask[pos] / 9;
    uchar col = indexMask[pos] % 9;
    uchar box = (row / 3) * 3 + (col / 3);
    uchar num;
    char cur;
    for (num = 0; num < 9; num++)
    {
        if (rowMask[row][num] || colMask[col][num] || boxMask[box][num])
        {
            continue;
        }

        rowMask[row][num] = colMask[col][num] = boxMask[box][num] = true;

        board[row][col] = num + '0' + 1;
        dfs(board, pos + 1);
        if (valid) return;
        rowMask[row][num] = colMask[col][num] = boxMask[box][num] = false;

    }
}

bool solveSudoku(char board[][9], int boardSize, int* boardColSize) {
    uchar row = 0, col = 0, box = 0;
    uchar rowSize = boardSize / *boardColSize;
    uchar colSize = *boardColSize;
    uchar boxSize = (rowSize / 3) * (colSize / 3);
    char cur;

    for (row = 0; row < rowSize; row++)
    {
        for (col = 0; col < colSize; col++)
        {
            if ('.' == board[row][col])
            {
                indexMask[indexSize++] = row * rowSize + col;
                continue;
            }
            else
            {
                cur = board[row][col] - '0' - 1;
                box = (row / 3) * 3 + col / 3;
                if (rowMask[row][cur]) 
                    return false;
                if (colMask[col][cur]) 
                    return false;
                if (boxMask[box][cur]) 
                    return false;
                rowMask[row][cur] = true;
                colMask[col][cur] = true;
                boxMask[box][cur] = true;
            }
        }
    }

    dfs(board, 0);

    return true;
}

int main(void)
{
    uint suduRowSize = ARRAY_SIZE(sudu);
    uint suduColSize = ARRAY_SIZE(sudu[0]);
    uint i = 0;
    bool ret = false;
    int suduSize = sizeof(sudu);

    printf("sudoRowSize = %d, suduColSize = %d\n", suduRowSize, suduColSize);

    for (i = 0; i < suduRowSize; i++)
    {
        dumpCharArray(sudu[i], suduColSize);
    }

    ret = solveSudoku(sudu, suduSize, &suduColSize);
    printf("\nret = %d\n\n", ret);
    for (i = 0; i < suduRowSize; i++)
    {
        dumpCharArray(sudu[i], suduColSize);
    }

    return true;
}