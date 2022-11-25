// 186 / 188 test cases passed.
#define max(a,b) a > b ? a : b
#define db cout << "DEBUG" << endl;

class Solution {
private:
    void test (int * nums, const int lens) {
        for (int i=0; i<lens; ++i)
            cout << nums[i] << " ";
        cout << endl;
        return;
    }
    
    int findMax(vector<int>& nums, const int start, const int end) {
        // printf("Start: %d, End: %d\n", start, end);
        if (start == end) {
            // cout << "ANS = " << nums[start] << endl;
            return nums[start];
        }
        
        int ans = nums[start];
        const int count = end - start; // start from 0 to count
        // cout << "Count: " << count << endl;
        int dp[count+1];
        dp[0] = nums[start];
        for (int i=1; i<=count; ++i){
            dp[i] = dp[i-1] * nums[i+start];
            ans = max(ans, dp[i]);
        }
        // test(dp, count+1);
        for (int i=0; i<=count; ++i) {
            for (int j=i; j<=count; ++j) {
                dp[j] /= nums[i+start];
                ans = max(ans, dp[j]);
            }
            // test(dp, count+1);
        }
        
        // cout << "ANS = " << ans << endl;
        return ans;
    }
    
public:
    int maxProduct(vector<int>& nums) {
        const int lens = nums.size();
        int ans = INT_MIN, start = 0;
        while (start < lens && nums[start] == 0) ++start;
        if (start == lens) return 0;
        // cout << "NOT_END" << endl;
        for (int i=start; i<lens; ++i) {
            ans = max(ans, nums[i]);
            if (nums[i] == 0) {
                ans = max (ans, findMax(nums, start, i-1));
            }
            while (i < lens && nums[i] == 0){
                ++i;
                start = i;
            }
            if (start >= lens-1) break;
        }
        
        int last = lens-1;
        while (nums[last] == 0) --last;
        if (start <= last) {
            // printf("Start: %d, End: %d\n", start, lens-1);
            ans = max(ans, findMax(nums, start, last));
        }
        // cout << "debug" << endl;
        
        return ans;
    }
};
