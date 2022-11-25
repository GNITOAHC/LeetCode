#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

class Solution {
private:
    void swap (int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
        return;
    }
        
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int tmpMax = nums[0], tmpMin = nums[0];
        const int lens = nums.size();
        
        for (int i=1; i<lens; ++i) {
            if (nums[i] < 0)
                swap (tmpMax, tmpMin);
            tmpMax = max(nums[i], tmpMax * nums[i]);
            tmpMin = min(nums[i], tmpMin * nums[i]);
            
            ans = max(ans, tmpMax);
        }
        
        return ans;
    }
};