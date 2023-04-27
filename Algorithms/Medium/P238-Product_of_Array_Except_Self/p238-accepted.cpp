#define db cout << "DEBUG" << endl;
class Solution {
public:
    void test (vector<int> a){
        for (int i=0; i<a.size(); ++i)
            cout << a[i] << " ";
        cout << endl;
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> front (nums);
        vector<int> back (nums);
        // test(nums);
        for (int i=1; i<front.size(); ++i)
            front[i] *= front[i-1];
        for (int i=back.size()-2; i>=0; --i)
            back[i] *= back[i+1];
        // test(front);
        // test(back);
        nums[0] = back[1];
        nums[nums.size()-1] = front[nums.size()-2];
        
        for (int i=1; i<nums.size()-1; ++i){
            nums[i] = front[i-1] * back[i+1];
        }
        
        return nums;
    }
};