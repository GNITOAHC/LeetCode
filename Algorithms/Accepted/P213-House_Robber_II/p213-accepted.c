

int max(int a, int b){
    if (a > b) return a;
    return b;
}
int rob(int* nums, int numsSize){
    // if only 4 or less house
    int tmpans = 0;
    if (numsSize <= 3){
        for (int i=0; i<numsSize; ++i){
            tmpans = tmpans > nums[i] ? tmpans : nums[i];
        }
        return tmpans;
    }
    else if (numsSize == 4){
        tmpans = nums[0]+nums[2] > nums[1]+nums[3] ? nums[0]+nums[2] : nums[1]+nums[3];
        return tmpans;
    }
    // rob first house
    int dp[numsSize];
    dp[2] = nums[2];
    dp[3] = nums[3];
    dp[4] = nums[4] + nums[2];
    for (int i=5; i<numsSize; ++i){
        dp[i] = max(nums[i] + dp[i-2], nums[i] + dp[i-3]);
    }
    tmpans = max(dp[numsSize-2], dp[numsSize-3]) + nums[0];
    // init array dp
    for (int i=0; i<numsSize; ++i)
        dp[i] = 0;
    // dont rob first
    dp[1] = nums[1];
    dp[2] = nums[2];
    dp[3] = nums[3] + nums[1];
    for (int i=4; i<numsSize; ++i){
        dp[i] = max(nums[i] + dp[i-2], nums[i] + dp[i-3]);
    }
    return max(tmpans, max(dp[numsSize-1], dp[numsSize-2]));
}