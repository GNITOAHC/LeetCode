class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int adder = 1, idx = 0;
        long long sum = 0;
        while(true) {
            if (k == 0) break;
            if (idx >= nums.size()) break;
            if (adder < nums[idx]) {
                sum += adder;
                ++adder;
                --k;
            } else if (adder > nums[idx]) {
                ++idx;
            } else { // adder == nums[idx]
                ++adder;
                ++idx;
            }
        }
        for (int i = adder; k > 0; --k, ++i) {
            sum += i;
        }
        return sum;
    }
};
