class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = INT_MIN, secondLarge = INT_MIN;
        int largestIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > largest) {
                secondLarge = largest;
                largest = nums[i];
                largestIndex = i;
            } else if (nums[i] > secondLarge){
                secondLarge = nums[i];
            }
        }

        if (largest >= 2 * secondLarge) return largestIndex;
        else return -1;
    }
};