#define db cout << "DEBUG" << endl;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.empty()) 
            return 0;
        int lens = nums.size();
        int left = 0, right = 0;
        int re_val = INT_MAX, sum = nums[0];
        do {
            // db;
            while (sum < target && right < lens-1)
                sum += nums[++right];
            // cout << left << ' ' << right << endl;
            while (sum >= target && left <= right) {
                re_val = re_val < (right - left + 1) ? re_val : (right - left + 1);
                sum -= nums[left++];
            }
            // cout << left << ' ' << right << endl;
        } while (left < right && right < lens-1);

        if (re_val == INT_MAX)
            return 0;
        return re_val;
    }
};