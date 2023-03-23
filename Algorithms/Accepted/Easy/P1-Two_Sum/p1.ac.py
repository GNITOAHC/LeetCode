class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        newlist = nums.copy()
        newlist.sort()
        front = 0
        end = len(newlist) - 1
        while True:
            if newlist[front] + newlist[end] < target:
                front += 1
            if newlist[front] + newlist[end] > target:
                end -= 1
            if newlist[front] + newlist[end] == target:
                break
        ans = []
        for i in range(0, len(nums)):
            if nums[i] == newlist[front]:
                ans.append(i)
            elif nums[i] == newlist[end]:
                ans.append(i)
        return ans