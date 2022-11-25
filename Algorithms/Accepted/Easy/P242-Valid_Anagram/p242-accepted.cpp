class Solution {
public:
    bool isAnagram(string s, string t) {
        int arrayS[26] = {0};
        int arrayT[26] = {0};
        const int lens = s.length();
        if (lens != t.length())
            return false;
        for (int i=0; i<lens; ++i) {
            const char curS = toupper(s[i]);
            const char curT = toupper(t[i]);
            ++arrayS[curS - 65];
            ++arrayT[curT - 65];
        }
        
        for (int i=0; i<26; ++i) {
            if (arrayS[i] != arrayT[i])
                return false;
        }
        
        return true;
    }
};