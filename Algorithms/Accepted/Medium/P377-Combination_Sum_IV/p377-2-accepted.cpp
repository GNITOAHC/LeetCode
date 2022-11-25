class Solution {    
public:
    int combinationSum4(vector<int>& nums, int target) {
        const int _target = target;
        vector<int> _nums;
        for (int i=0; i<nums.size(); ++i)
            if (nums[i] <= _target) _nums.push_back(nums[i]);
        const int numLens = _nums.size();
        if (_nums.empty()) return 0;
        
        unsigned long long dp[_target + 1];
        for (int i=0; i<_target; ++i) dp[i] = 0;
        dp[_target] = 1;
        
        for (int i=_target; i>=0; --i) {
            for (int j=0; j<numLens; ++j) {
                const unsigned long long tmpCount = dp[i];
                if (i-_nums[j] > 0) {
                    dp[i-_nums[j]] += tmpCount;
                }
            }
        }
                
        unsigned long long sum = 0;
        for (int i=0; i<numLens; ++i)
            sum += dp[_nums[i]];
        return sum;
    }
};