class Solution {
public:
    string longestPalindrome(string s) {
        const int lens = s.length();
        auto get_lens = [&](int l, int r) -> int {
            while (l >= 0 && r < lens && s[l] == s[r]) {
                ++r;
                --l;
            }
            return (r - l -1);
        };
        
        int start = 0, ansLens = 0;
        for (int i=0; i<lens; ++i) {
            const int tmp = max(get_lens(i, i), get_lens(i, i+1));
            if (tmp > ansLens) {
                ansLens = tmp;
                start = i - ((ansLens-1) / 2);
            }
        }
        
        return s.substr(start, ansLens);
    }
};