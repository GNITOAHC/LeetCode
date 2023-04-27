#define pb push_back
#define debug cout << "DEBUG" << endl;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> reans;
        for (int i=0; i<2; ++i) reans.pb(-1);
                
        int l = 0, r = nums.size()-1, m = (nums.size()-1)/2;
        while (l < r) {
            if (nums[m] == target) {
                break;
            }
            if (nums[m] < target) {
                l = m+1;
            }
            else if (nums[m] > target) {
                r = m-1;
            }
            m = (l + r) / 2;
        }
                
        if (l > r || nums[m] != target)
            return reans;
        else {
            l = r = m;
            while (l > 0 && nums[l-1] == target)
                --l;
            while (r < nums.size()-1 && nums[r+1] == target)
                ++r;
        }
        reans[0] = l;
        reans[1] = r;
        return reans;
    }
};