class Solution {
public:
    bool isPowerOfThree(int n) {
        double a = log10(n) / log10(3);
        if (ceil(a) == floor(a) && n != 0) return true;
        return false;
    }
};