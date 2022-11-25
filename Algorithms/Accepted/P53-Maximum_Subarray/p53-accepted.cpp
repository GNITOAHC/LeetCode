class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp = INT_MIN, ans = INT_MIN;
        for (int i=0; i<nums.size(); ++i){
            if (tmp >= 0) tmp += nums[i];
            else
                tmp = nums[i];
            if (tmp > ans)
                ans = tmp;
        }
        
        return ans;
    }
};