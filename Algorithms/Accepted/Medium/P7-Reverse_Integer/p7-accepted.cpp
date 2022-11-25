class Solution {
public:
    int reverse(int x) {
        int sign = (x > 0) ? 1 : -1;
        x = abs(x);
        int ans = x % 10;
        x /= 10;
        while (x > 0) {
            if (ans > INT_MAX/10)
                return 0;
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        
        return sign * ans;
    }
};