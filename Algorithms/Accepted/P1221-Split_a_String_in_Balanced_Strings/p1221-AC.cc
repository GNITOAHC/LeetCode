class Solution {
public:
    int balancedStringSplit(string s) {
        const int lens = s.length();
        int count = 0, ans = 0;
        
        for (int i=0; i<lens; ++i) {
            if (s[i] == 'R') {
                ++count;
            } else {
                --count;
            }
            if (count == 0) ++ans;
        }
        
        return ans;
    }
};