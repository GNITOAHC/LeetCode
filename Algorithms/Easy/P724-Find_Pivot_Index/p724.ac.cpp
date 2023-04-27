class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0, rightSum = 0;
        for (auto n : nums) {
            rightSum += n;
        }

        rightSum -= nums[0];
        if (rightSum == leftSum) return 0;
        const int size = nums.size();

        for (int i = 1; i < size; ++i) {
            leftSum += nums[i - 1];
            rightSum -= nums[i];
            if (leftSum == rightSum) return i;
        }
        return -1;
    }
};