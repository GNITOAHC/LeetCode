class Solution {
public:
    int maxDepth(string s) {
        int test = 0, max = 0;
        for (auto s : s) {
            if (s == '(') ++test;
            else if (s == ')') --test;
            max = max > test ? max : test;
        }
        return max;
    }
};