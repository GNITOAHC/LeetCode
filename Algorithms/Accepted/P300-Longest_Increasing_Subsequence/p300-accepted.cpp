class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int lens = nums.size();
        int dp[lens];
        for (int i=0; i<lens; ++i)
            dp[i] = 1;
        dp[0] = 1;
        for (int i=1; i<lens; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = dp[i] > dp[j]+1 ? dp[i] : dp[j]+1;
            }
        }
        
        // for (int i=0; i<lens; ++i)
        //     cout << dp[i] << " ";
        // cout << endl;
        
        int ans = 1;
        for (int i=0; i<lens; ++i)
            ans = dp[i] > ans ? dp[i] : ans;
        
        return ans;
    }
};