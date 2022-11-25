class Solution {
public:
    int findMin(vector<int>& nums) {
        const int lens = nums.size();
        int front = 0, back = nums.size()-1;
        int mid = (front + back) >> 1; // \frac{front+back}{2}
        const int lmost = nums[0], rmost = nums[lens-1];
        
        if (lmost <= rmost) return nums[0];
        
        if (lens == 2) return nums[1];
        
        do {
            // printf("MID nums[%d] = %d\n", mid, nums[mid]);
            if (nums[mid] > lmost)
                front = mid + 1;
            if (nums[mid] <= rmost) {
                if (nums[mid] < nums[mid-1])
                    return nums[mid];
                back = mid-1;
            }
            if (nums[back] < nums[back-1])
                return nums[back];
            mid = (front + back) >> 1;
        } while (front <= back);
        
        return nums[0];
    }
};