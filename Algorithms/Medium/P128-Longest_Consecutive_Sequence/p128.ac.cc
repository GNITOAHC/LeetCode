class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (auto n : nums) set.insert(n); // Put nums into unordered_set

        int best = 0; // Initial the best solution to zero

        for (auto n : set) { // Iterate through set
            if (set.count(n - 1) > 0) {
                // If n - 1 exist: n is not the start of sequence
                continue;
            } else {
                int inc = n + 1;
                while (set.count(inc) > 0) { // inc exist in set
                    // Continue if has consecutive sequence
                    ++inc;
                }
                best = best > inc - n ? best : inc - n;
            }
        }

        return best;
    }
};