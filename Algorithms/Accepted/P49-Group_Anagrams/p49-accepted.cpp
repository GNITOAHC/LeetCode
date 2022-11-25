class Solution {
private: 
    string sort (string a) {
        const int lens = a.length();
        int alph[26] = {0};
        for (int i=0; i<lens; ++i) {
            ++alph[ a[i]-97 ];
        }
        string r;
        for (int i=0; i<26; ++i) {
            for (int j=0; j<alph[i]; ++j) {
                r.push_back( i+97 );
            }
        }
        return r;
    };
    typedef struct AfterSort {
        string before;
        string after;
    }AfterSort;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int lens = strs.size();
        vector<vector<string> > ans;
        vector<string> count;
        AfterSort aftersort[lens];
        
        for (int i=0; i<lens; ++i) {
            aftersort[i].before = strs[i];
            aftersort[i].after = sort(strs[i]);
        }
        
        for (int i=0; i<lens; ++i) {
            bool in_vector_count = false;
            for (int j=0; j<count.size(); ++j) {
                if (aftersort[i].after.compare( count[j] ) == 0) {
                    ans[j].push_back(aftersort[i].before);
                    in_vector_count = true;
                }
            }
            if (!in_vector_count) {
                count.push_back(aftersort[i].after);
                ans.push_back(vector<string>());
                ans[count.size() - 1].push_back(aftersort[i].before);
            }
        }
        return ans;
    };
};
