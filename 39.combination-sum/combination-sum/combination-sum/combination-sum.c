#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LeetCodeBox.h"

int combineSize;
int ansSize;
int* ansColumnSize;

// 1. 判断 index 是否最大，如果最大，则直接返回；
// 2. 判断 target 是否为0， 如果为0则代表找到了一组目标数组；
//  2.1 拷贝目标数组到自己申请的内存中，并把该内存的指针保存到ans中；
//  2.2 把该目标数组的大小保存到ansColumnSize中；
//  2.3 ans 和 ansColumSize 的下标ansSize++;
//  2.4 return;
// 3. dfs(index+1)
// 4. 判断target - candidates[index] 是否大于0，如果大于0则说明还可以继续递归，执行下一步4.1；
//  4.1 copy candidates[index] 到 combine[combineSize++]中
//  4.2 dfs(target - candidates[index])
//  4.3 combineSize--

void dfs(int* candidates, int candidatesSize, int target, int **ans, int* ansColumnSize, int* combine, int idx)
{
    
    if (candidatesSize == idx)   return;
    if (0 == target)
    {
        int* temp = malloc(sizeof(int) * combineSize);
        int i = 0;
        for (; i < combineSize; i++)
        {
            temp[i] = combine[i];
        }
        ans[ansSize] = temp;
        ansColumnSize[ansSize++] = combineSize;
        return;
    }

    dfs(candidates, candidatesSize, target, ans, ansColumnSize, combine, idx + 1);

    if ((target - candidates[idx]) >= 0)
    {
        combine[combineSize++] = candidates[idx];
        dfs(candidates, candidatesSize, target - candidates[idx], ans, ansColumnSize, combine, idx);
        combineSize--;
    }

}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** ans = malloc(sizeof(int*) * 1001);
    ansColumnSize = malloc(sizeof(int) * 1001);
    int combine[2001] = { 0 };
    ansSize = combineSize = 0;

    dfs(candidates, candidatesSize, target, ans, ansColumnSize, combine, 0);

    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSize;
    return ans;
}


int main(void)
{
    int** ret;
    int* returnColumnSizes;
    int candidates[] = { 2, 3, 5 };
    int target = 8, returnSize;
    int candidatesSize = ARRAY_SIZE(candidates);
    int i = 0;
    
    dumpIntArray(candidates, candidatesSize);
    ret = combinationSum(candidates, candidatesSize, target, &returnSize, &returnColumnSizes);
    
    for (i = 0; i < returnSize; i++)
    {
        dumpIntArray(ret[i], returnColumnSizes[i]);
    }

    return true;
}