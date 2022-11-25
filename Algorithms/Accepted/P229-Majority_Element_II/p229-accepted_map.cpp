// map
#define pb push_back
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> count;
        count.insert(pair<int, int>(nums[0], 1));
        map<int, int>::iterator iter;
        for (int i=1; i<nums.size(); ++i){
            iter  = count.find(nums[i]);
            if (iter != count.end())
                ++iter->second;
            else
                count.insert(pair<int, int>(nums[i], 1));
        }
        
        // for (auto &n : count)
        //     cout << n.first << " : " << n.second << endl;
        
        vector<int> ans;
        for (iter = count.begin(); iter != count.end(); ++iter){
            if (iter->second > nums.size()/3)
                ans.pb(iter->first);
        }
        
        return ans;
    }
};
