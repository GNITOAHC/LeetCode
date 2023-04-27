class Solution {
public:
    int newStart(string s, int start, int newend){
        for (int i=start; i<newend; ++i){
            if (s[i] == s[newend]){
                return i+1;
            }
        }
        return false;
    }
    
    bool haveBefore(string s, int start, int newend){
        for (int i=start; i<newend; ++i){
            if (s[i] == s[newend]){
                return true;
            }
        }
        return false;
    }
    
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return NULL;
        if (s.length() == 1)
            return 1;
        int length = 0, start = 0, end = 0;
        while (end < s.length()-1){
            if (haveBefore(s, start, end+1) == false){
                ++end;
                length = length > (end-start)+1 ? length : (end-start)+1;
                
                // cout << "haveBefore == false, length = " << length << endl;
                // for (int i=start; i<end+1; ++i) cout << s[i] << " ";
                // cout << endl;
            }
            else {
                start = newStart(s, start, end+1);
                ++end;
                length = length > (end-start)+1 ? length : (end-start)+1;
                
                // cout << "haveBefore == true, length = " << length << endl;
                // for (int i=start; i<end+1; ++i) cout << s[i] << " ";
                // cout << endl;
            }
        }
        // cout << "Ans = " << length << endl;
        return length;
    }
};