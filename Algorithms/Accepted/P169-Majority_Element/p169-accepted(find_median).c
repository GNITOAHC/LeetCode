

// find median
int cmp(const void * a, const void * b){
    if (*(int *)a > *(int *)b) return 1;
    return -1;
}

int majorityElement(int* nums, int numsSize){
    if (numsSize == 1 || numsSize == 2) return nums[0];
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[(numsSize/2)];
}