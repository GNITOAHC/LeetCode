class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag_count[26] = {0};
        for (int i=0; i<magazine.length(); ++i) {
            ++mag_count[magazine[i]-'a'];
        }

        for (int i=0; i<ransomNote.length(); ++i) {
            --mag_count[ransomNote[i]-'a'];
            if (mag_count[ransomNote[i]-'a'] < 0) return false;
        }
        return true;
    }
};