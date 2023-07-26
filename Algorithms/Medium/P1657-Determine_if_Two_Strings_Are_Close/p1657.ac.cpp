/*
* 1. Length of two words should be the same.
* 2. Same characters should present in both words.
* 3. Occurences should be the same. 
* (i.e. If 'a' occur 3 times in word1, word2 should have a character occur 3 times)
*/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        
        int arr1[26] = {0}, arr2[26] = {0};
        for (auto it : word1) ++arr1[it - 'a'];
        for (auto it : word2) ++arr2[it - 'a'];

        for (int i = 0; i < 26; ++i) {
            if ((arr1[i] == 0 && arr2[i] == 0) || (arr1[i] != 0 && arr2[i] != 0))
                continue;
            return false;
        }
        
        std::sort(arr1, arr1 + 26);
        std::sort(arr2, arr2 + 26);

        for (int i = 0; i < 26; ++i) if (arr1[i] != arr2[i]) return false;

        return true;
    }
};