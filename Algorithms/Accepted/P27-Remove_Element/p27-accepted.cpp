class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lens = nums.size(), l = 0;
        for (int i=0; i<lens; ++i) 
            if (nums[i] != val) {
                nums[l] = nums[i];
                ++l;
            }
        
        return l;
    }
};