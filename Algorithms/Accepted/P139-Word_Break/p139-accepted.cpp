class Solution {
private:
    int compare (string a, string b) {
        const int lena = a.length();
        const int lenb = b.length();
        
        if (lena < lenb) return -1;
        else if (lena == lenb) {
            if (a.compare(b) == 0)
                return lena;
            return -1;
        } else {
            if (a.compare(0, lenb, b) == 0)
                return lenb;
            return -1;
        }
        
        return -1;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int lens = s.length();
        const int wordNum = wordDict.size();
        
        bool dp[lens + 1];
        for (int i=0; i<lens+1; ++i)
            dp[i] = false;
        dp[lens] = true;
        
        if (s.length() == 1) {
            for (int i=0; i<wordNum; ++i)
                if (s.compare(wordDict[i]) == 0)
                    return true;
        }
        
        
        for (int i=lens-1; i>=0; --i) {
            const string cur(s, i, lens); // Nothing when (i == lens-1)
            
            for (int j=0; j<wordNum; ++j) {
                const int num = compare(cur, wordDict[j]);
                if (num != -1) {
                    if (!dp[i])
                        dp[i] = dp[i + num];
                }
            }
        }
        
        return dp[0];
    }
};