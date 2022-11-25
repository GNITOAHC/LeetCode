// divide and conquer
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        const int lens = prices.size();
        int left[lens], right[lens];
        left[0] = 0;
        right[lens-1] = 0;
        
        // left
        int min = prices[0];
        for (int i=1; i<lens; ++i) {
            min = min < prices[i] ? min : prices[i];
            left[i] = left[i-1] > prices[i] - min ? left[i-1] : prices[i] - min;
        }
        
        // right
        int max = prices[lens-1];
        for (int i=lens-2; i>=0; --i) {
            max = max > prices[i] ? max : prices[i];
            right[i] = right[i+1] > max - prices[i] ? right[i+1] : max - prices[i];
        }
        
        // check
        // for (int i=0; i<lens; ++i) printf("%d ", left[i]);
        // cout << endl;
        // for (int i=0; i<lens; ++i) printf("%d ", right[i]);
        // cout << endl;
        
        // find ans
        int ans = left[0] + right[1];
        int buy_once = left[0];
        for (int i=1; i<lens-1; ++i) {
            ans = ans > left[i] + right[i+1] ? ans : left[i] + right[i+1];
            buy_once = buy_once > left[i] ? buy_once : left[i];
        }
        // check remain left[lens-1]
        buy_once = buy_once > left[lens-1] ? buy_once : left[lens-1];
        
        return ans > buy_once ? ans : buy_once;
    }
};