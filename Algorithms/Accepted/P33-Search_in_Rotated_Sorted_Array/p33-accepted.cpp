class Solution {
public:
    int inline binarySearch (vector<int>& nums, const int L, const int R, const int t) {
        // cout << L << " " << R << " " << t <<endl;
        int left = L, right = R, middle = (L + R) / 2;
        while (left <= right) {
            // cout << left << " " << right << " " << middle << endl;
            // cout << nums[middle] << endl;
            if (nums[middle] < t)
                left = middle + 1;
            else if (nums[middle] > t)
                right = middle - 1;
            else
                return middle;
            // middle = (left + right) / 2;
            middle = (left + right) >> 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        const int length = nums.size() - 1;
        if (nums[0] < nums[length]) {
            return binarySearch(nums, 0, length, target);
        }
        int left = 0, right = length;
        int middle = (left + right) / 2;
        while (nums[left] > nums[right]) {
            if (nums[left] < nums[middle]) 
                left = middle;
            else
                right = middle;
            // middle = (left + right) / 2;
            middle = (left + right) >> 1;
        }
        if (target >= nums[0]) {
            return binarySearch (nums, 0, left, target);
        } else {
            return binarySearch (nums, left+1, length, target);
        }
    }
};