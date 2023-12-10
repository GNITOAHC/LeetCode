class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [&](const char c) -> bool {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                return true;
            return false;
        };

        int front = 0, end = k, vowel_counter = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) ++vowel_counter;
        }

        int max = vowel_counter;

        for (int i = 0; i < s.length(); ++i) {
            if (end >= s.length()) break;
            if (isVowel(s[front++])) --vowel_counter;
            if (isVowel(s[end++])) ++vowel_counter;
            max = vowel_counter > max ? vowel_counter : max;
        }

        return max;
    }
};