class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], ans = 0;
        
        for (auto& price : prices) {
            min = min < price ? min : price;
            ans = (price - min > ans) ? price - min : ans;
        }
        
        return ans;
    }
};