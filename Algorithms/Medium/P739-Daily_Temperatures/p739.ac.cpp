class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s; // index, value
        vector<int> ans(temperatures.size(), 0);

        for (int idx = 0; const auto& it : temperatures) {
            while (!s.empty()) {
                if (s.top().second < it) {
                    const int value_index = s.top().first;
                    s.pop();
                    ans[value_index] = idx - value_index;
                } else {
                    break;
                }
            }
            s.push({idx++, it});
        }

        return ans;
    }
};