/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int * arr = (int*)calloc(2,sizeof(int));
    int t;
    for(int i=0;i<numsSize;i++){
        int t = target-nums[i];
        for(int j=i+1;j<numsSize;j++){
            if(nums[j]==t){
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
        }
         if(arr[1]!=0) break;
    }
    *returnSize = 0;
    return NULL;
}