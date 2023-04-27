

int max (const int a, const int b){
    if (a > b)
        return a;
    return b;
}

int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int a = nums1Size, b = nums2Size;
    int dp[a+1][b+1];

    int ans = 0;
    dp[0][0] = 0;
    for (int i=1; i<a+1; ++i){
        dp[i][0] = 0;
        for (int j=1; j<b+1; ++j){
            dp[0][j] = 0;
            if (nums1[i-1] == nums2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
                dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}
