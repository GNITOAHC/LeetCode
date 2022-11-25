class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int lens = nums.size();
        // vector<int> dp_inc (lens, 1), dp_dec (lens, 1);
        int dp_inc[lens], dp_dec[lens];
        for (int i=0; i<lens; ++i) {
            dp_inc[i] = 1;
            for (int j=0; j<i; ++j) {
                if (nums[i] > nums[j])
                    dp_inc[i] = max (dp_inc[i], dp_inc[j] + 1);
            }
        }
        
        for (int i=lens-1; i>=0; --i) {
            dp_dec[i] = 1;
            for (int j=lens-1; j>i; --j) {
                if (nums[i] > nums[j])
                    dp_dec[i] = max (dp_dec[i], dp_dec[j] + 1);
            }
        }
        
        // for (int i=0; i<lens; ++i)
        //     cout << dp_dec[i] << " ";
        // cout << endl;
        
        int val = INT_MIN, index = -1;
        for (int i=0; i<lens; ++i) {
            if (val < dp_inc[i] + dp_dec[i] - 1 && dp_inc[i] > 1 && dp_dec[i] > 1) {
                val = dp_inc[i] + dp_dec[i] - 1;
                index = i;
            }
        }
        
        return lens - val;
    }
};