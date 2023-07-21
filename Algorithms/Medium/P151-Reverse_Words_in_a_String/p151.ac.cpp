class Solution {
public:
    stack<string> split(const string& s) {
        stack<string> stack;
        // if (s.size() == 0) return stack; // (At least one word in s)

        for (int i = 0; i < s.size(); ++i) {
            string word;
            if (s[i] == ' ') continue; // Skip spaces
            while (i < s.size() && s[i] != ' ') {
                word += s[i++];
            }
            stack.push(word);
        }

        return stack;
    }

    string reverseWords(string s) {
        string result;
        stack<string> stack = split(s);
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
            if (!stack.empty()) result += ' ';
        }
        return result;
    }
};