

long long subArrayRanges(int* nums, int numsSize){
    long long ans = 0;
    for (int i=0; i<numsSize-1; ++i){
        int tmpmax = nums[i], tmpmin = nums[i];
        for (int j=i+1; j<numsSize; ++j){
            // tmpmax = tmpmax > nums[j] ? tmpmax : nums[j];
            // tmpmin = tmpmin < nums[j] ? tmpmin : nums[j];
            if (nums[j] > tmpmax){
                tmpmax = nums[j];
                ans += (tmpmax - tmpmin);
            }
            else if (nums[j] < tmpmin){
                tmpmin = nums[j];
                ans += (tmpmax - tmpmin);
            }
            else
                ans += (tmpmax - tmpmin);
            // printf("tmpmax = %d tmpmin = %d\n", tmpmax, tmpmin);
            // ans += (tmpmax - tmpmin);
            // printf("ans = %lld\n", ans);
        }
    }
    
    return ans;
}