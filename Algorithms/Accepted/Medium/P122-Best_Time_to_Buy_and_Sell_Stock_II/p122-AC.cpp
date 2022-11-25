class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        const int lens = prices.size();
        
        for (int i=1; i<lens; ++i) {
            const int diff = prices[i] - prices[i-1];
            if (diff > 0) {
                ans += diff;
            }
        }
        
        return ans;
    }
};