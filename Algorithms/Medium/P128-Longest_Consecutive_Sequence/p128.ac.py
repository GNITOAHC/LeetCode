class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums) # Generate set from nums
        best = 0

        for n in nums:
            if n - 1 not in nums: # If n is not the start of sequence
                inc = n + 1 # Count from n + 1
                while inc in nums: inc += 1
                best = max(best, inc - n)
        
        return best