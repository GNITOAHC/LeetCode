

int removeDuplicates(int* nums, int numsSize){
    int k=1, counter=1;
    int ans[numsSize];
    ans[0] = nums[0];
    if (numsSize == 0) return 0;
    else {
        for (int i=1; i<numsSize; i++){
            if (nums[i] != nums[i-1]){
                ++k;
                ans[counter++] = nums[i];
            }
        }
    }
    
    // for (int i=0; i<counter; ++i){
    //     printf("%d ", ans[i]);
    // }
    
    for (int i=0; i<counter; ++i){
        nums[i] = ans[i];
    }
    
    return k;
}
