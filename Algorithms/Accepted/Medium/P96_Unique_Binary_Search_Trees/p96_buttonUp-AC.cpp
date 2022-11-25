class Solution {
public:
    int numTrees(int n) {
        int dp[20];
        for (int i=0; i<20; ++i) dp[i] = 0;
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        
        for (int count=3; count < n+1; ++ count) {
            for (int root=1; root<=count; ++root) {
                int left = root - 1, right = count - root;
                if (left >= 0 && right >= 0)
                    dp[count] += dp[left] * dp[right];
            }
        }
        
        return dp[n];
    }
};