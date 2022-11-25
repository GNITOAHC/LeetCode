class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fastptr = 0, slowptr = 0;
        do {
            fastptr = nums[nums[fastptr]];
            slowptr = nums[slowptr];
        } while (fastptr != slowptr);
        
        fastptr = 0;
        while (fastptr != slowptr) {
            fastptr = nums[fastptr];
            slowptr = nums[slowptr];
        }
        return fastptr;
    }
};