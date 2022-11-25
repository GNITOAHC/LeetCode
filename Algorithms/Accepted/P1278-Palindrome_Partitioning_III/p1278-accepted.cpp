class Solution {
public:
    int palindromePartition(string s, int K) {
        const int lens=s.length();
        vector<vector<int> > cost(lens, vector<int>(lens));
        
        // cost[i][j] store char change cost from i to j
        for (int l=1; l<lens; ++l) {
            for (int i=0, j=l; j<lens; ++i, ++j) {
                cost[i][j] = (s[i] != s[j]) + cost[i+1][j-1]; // true == 1, false == 0
            }
        }
        
        vector<vector<int> > dp(lens, vector<int>(K+1, INT_MAX / 2));
        for (int i=0; i<lens; ++i) {
            dp[i][1] = cost[0][i];
            for (int k=2; k<=K; ++k) {
                for (int j=0; j<i; ++j) {
                    dp[i][k] = min(dp[i][k], dp[j][k-1] + cost[j+1][i]);
                }
            }
        }
        
        return dp[lens-1][K];
    }
};