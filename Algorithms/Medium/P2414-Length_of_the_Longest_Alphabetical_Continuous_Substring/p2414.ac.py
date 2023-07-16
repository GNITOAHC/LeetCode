class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        ans: int = 0 if len(s) == 0 else 1;
        tmp_ans: int = ans;
        for i in range(1, len(s)):
            if ord(s[i]) == ord(s[i - 1]) + 1:
                tmp_ans += 1;
                ans = tmp_ans if tmp_ans > ans else ans;
            else:
                tmp_ans = 1;
        return ans;