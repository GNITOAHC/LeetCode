class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        const int lens = changed.size();
        if (lens % 2 == 1) return {};
        
        map<int, int> mp;
        vector<int> ans;
        
        for (auto c : changed) {
            ++mp[c];
        }
        
        for (auto m : mp) {
            int key = m.first;
            if (m.second == 0) continue;
            while (mp[key] > 0) {
                ans.push_back(key);
                --mp[key];
                --mp[key*2];
            }
            if (mp[key*2] < 0) return {};
        }
        
        return ans;
    }
};