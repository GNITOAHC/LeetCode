#define min(a,b) (a < b ? a : b)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        if (amount == 0) return 0;
        if (amount < coins[0]) return -1;
                
        const int lens = coins.size();
        // dp[lens+1][amount+1] 2D array
        int ** dp = new int*[lens+1];
        for (int i=0; i<=lens; ++i) 
            dp[i] = new int[amount+1];
        
        dp[0][0] = 0;
        for (int i=1; i<=amount; ++i)
            dp[0][i] = -1;
        
        for (int i=1; i<=lens; ++i) {
            dp[i][0] = 0;
            for (int j=1; j<=amount; ++j) {
                if (j < coins[i-1]) dp[i][j] = dp[i-1][j];
                else {
                    if (dp[i-1][j] == -1 && dp[i][j-coins[i-1]] == -1)
                        dp[i][j] =  -1;
                    else if (dp[i-1][j] == -1)
                        dp[i][j] = dp[i][j-coins[i-1]] + 1;
                    else if (dp[i][j-coins[i-1]] == -1)
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
                }
            }
        }
        
        return dp[lens][amount];
    }
};