int longestContinuousSubstring(char * s){
    const int lens = strlen(s);
    int ans = lens == 0 ? 0 : 1;
    int tmp_ans = ans;
    for (int i = 1; i < lens + 1; ++i) {
        if (s[i] == s[i - 1] + 1) {
            ++tmp_ans;
            ans = tmp_ans > ans ? tmp_ans : ans;
        } else {
            tmp_ans = 1;
        }
    }
    return ans;
}