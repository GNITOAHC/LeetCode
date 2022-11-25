class Solution {
private:
    int helper(const int start, const int end) {
        int count = 0;
        if (start > end || start == end) return 1;
        else if (start == end-1) return 2;

        for (int cur_root = start; cur_root <= end; ++cur_root) {
            const int left = helper(start, cur_root-1);
            const int right = helper(cur_root+1, end);
            count += left * right;
        }
        
        return count;
    }
public:
    int numTrees(int n) {
        return helper(1, n);
    }
};