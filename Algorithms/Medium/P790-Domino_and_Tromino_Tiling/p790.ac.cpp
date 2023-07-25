/*
* dp[n]     = dp[n - 1] + dp[n - 2] + 2 * (dp[n - 3] + dp[n - 4] + ... + dp[0])
* dp[n - 1] = dp[n - 2] + dp[n - 3] + 2 * (dp[n - 4] + dp[n - 5] + ... + dp[0])
* dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3] + dp[n - 3]
*           + 2 * (dp[n - 4] + dp[n - 5] + ... + dp[0])
*       = dp[n - 1] + dp[n - 3] + dp[n - 1]
*       = 2 * dp[n - 1] + dp[n - 3]
* Trimino (those 2 * dp[x] will be handle like this): 
* T t t      T x x T T     T x x z z T
* T T t  or  T T y y T  or T T y y T T (Upside down also) ...
*/
class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        else if (n == 3) return 5;
        else if (n == 4) return 11;
        
        long long dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        dp[4] = 11;
        for (int i = 5; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};