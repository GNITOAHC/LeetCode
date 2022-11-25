class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int lens = nums.size();
        vector<int> ans;
        multiset<int> st;
        
        for (int i=0; i<k; ++i) st.insert(nums[i]);
        
        for (int start=0; start<=lens-k-1; ++start) {
            const int curMax = *st.rbegin();
            ans.push_back(curMax);
            st.insert(nums[start+k]);
            st.erase(st.find(nums[start]));
        }
        
        ans.push_back(*st.rbegin());
        
        return ans;
    }
};