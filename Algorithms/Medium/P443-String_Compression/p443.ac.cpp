class Solution {
public:
    int compress(vector<char>& chars) {
        const int lens = chars.size();
        int modify_idx = 0; // Index to modify

        for (int i = 0; i < lens; ++i) {
            char current = chars[i];
            int count = 1;

            while (i < lens - 1 && chars[i] == chars[i + 1]) {
                ++count;
                ++i;
            }

            chars[modify_idx++] = current;
            if (count == 1) continue; // Skip if group's length is 1

            std::string num = std::to_string(count);
            for (const auto& it : num) {
                chars[modify_idx++] = it;
            }
        }
        chars.resize(modify_idx); // Drop the value after modify_idx

        return chars.size();
    }
};