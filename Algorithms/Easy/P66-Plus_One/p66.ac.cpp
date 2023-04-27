class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int counter = 0;
        std::reverse(digits.begin(), digits.end());
        digits[0] += 1;
        if (digits[0] >= 10) {
            counter = digits[0] / 10;
            digits[0] = digits[0] % 10;
        }
        for (int i = 1; i < digits.size(); ++i) {
            digits[i] += counter;
            counter = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        if (counter) {
            digits.push_back(counter);
        }
        std::reverse(digits.begin(), digits.end());
        return digits;
    }
};
