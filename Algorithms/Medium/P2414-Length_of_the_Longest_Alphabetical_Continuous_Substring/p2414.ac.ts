function longestContinuousSubstring(s: string): number {
    let ans: number = s.length == 0 ? 0 : 1;
    let tmpAns: number = ans;
    const charCode = (s: string) => s.charCodeAt(0) - 97;
    for (let i = 1; i < s.length; ++i) {
        if (charCode(s[i]) == charCode(s[i - 1]) + 1) {
            ++tmpAns;
            ans = tmpAns > ans ? tmpAns : ans;
        } else {
            tmpAns = 1;
        }
    }
    return ans;
};
