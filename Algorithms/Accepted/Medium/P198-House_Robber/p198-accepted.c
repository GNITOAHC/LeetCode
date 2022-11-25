

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int rob(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    else if (numsSize == 1) return nums[0];
    else if (numsSize == 2) return max(nums[0], nums[1]);
    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[0] + nums[2];
    for (int i=3; i<numsSize; ++i){
        dp[i] = max(nums[i] + dp[i-2], nums[i] + dp[i-3]);
    }
    
    return max(dp[numsSize-1], dp[numsSize-2]);
}