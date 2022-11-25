

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// boyer-moore voting
int* majorityElement(int* nums, int numsSize, int* returnSize){
    if (numsSize == 1){
        * returnSize = 1;
        return nums;
    }
    
    int ans1 = nums[0], count1 = 1;
    int ans2, count2;
    int i = 1;
    for ( ; i<numsSize; ++i){
        if (nums[i] != ans1){
            ans2 = nums[i];
            count2 = 1;
            printf("break at %d\n", i);
            break;
        }
        else
            ++count1;
    }
    if (i == numsSize){
        if (count1 == numsSize){
            int * re = (int *) malloc (sizeof(int) * 1);
            * returnSize = 1;
            re[0] = nums[0];
            return re;
        }
        int * re = (int *) malloc (sizeof(int) * 2);
        * returnSize = 2;
        re[0] = ans1;
        re[1] = ans2;
        return re;
    }
    ++i;
    for ( ; i<numsSize; ++i){
        printf("%d ", i);
        if (nums[i] == ans1)
            ++count1;
        else if (nums[i] == ans2)
            ++count2;
        else{
            if (count1 == 1)
                ans1 = nums[i];
            else if (count2 == 1)
                ans2 = nums[i];
            else{
                --count1;
                --count2;
            }
        }
    }
    
    if (count1 > numsSize/3){
        if (count2 > numsSize/3){
            int * re = (int *) malloc (sizeof(int) * 2);
            re[0] = ans1;
            re[1] = ans2;
            * returnSize = 2;
            return re;
        }
        int * re = (int *) malloc (sizeof(int) * 1);
        re[0] = ans1;
        * returnSize = 1;
        return re;
    }
    if (count2 > numsSize/3){
        int * re = (int *) malloc (sizeof(int) * 1);
        re[0] = ans2;
        * returnSize = 1;
        return re;
    }
    printf("\nnothing\n");
    int * re = (int *) malloc (sizeof(int) * 1);
    *returnSize = 0;
    return re;
}
