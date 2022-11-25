class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int len1 = text1.length(), len2= text2.length();
        int dp[len1 + 1][len2 + 1];
        for (int i=0; i<len1+1; ++i) 
            for (int j=0; j<len2+1; ++j)
                dp[i][j] = 0;
        
        for (int i=len1-1; i>=0; --i) {
            for (int j=len2-1; j>=0; --j) {
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i+1][j+1] + 1;
                else
                    dp[i][j] = max (dp[i][j+1], dp[i+1][j]);
            }
        }
        
        // print test
        // for (int i=0; i<len1+1; ++i) {
        //     for (int j=0; j<len2+1; ++j)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        
        return dp[0][0];
    }
};