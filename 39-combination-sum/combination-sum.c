/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrack(int* candidates, int candidatesSize, int target, int start, int* temp, int tempSize, int*** res, int* returnSize, int** returnColSizes) {
    if (target == 0) {
        (*res)[*returnSize] = (int*)malloc(sizeof(int) * tempSize);
        for (int i = 0; i < tempSize; i++) {
            (*res)[*returnSize][i] = temp[i];
        }
        (*returnColSizes)[*returnSize] = tempSize;
        (*returnSize)++;
        return;
    }
    if (target < 0) return;

    for (int i = start; i < candidatesSize; i++) {
        temp[tempSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i, temp, tempSize + 1,
                  res, returnSize, returnColSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColSizes) {
    int capacity = 200; 
    int** res = (int**)malloc(sizeof(int*) * capacity);
    *returnColSizes = (int*)malloc(sizeof(int) * capacity);
    int* temp = (int*)malloc(sizeof(int) * 200);
    *returnSize = 0;

    backtrack(candidates, candidatesSize, target, 0, temp, 0, &res, returnSize, returnColSizes);

    free(temp);
    return res;
}
