function twoSum(nums: number[], target: number): number[] {
    let original: number[] = [...nums] // Clone nums
    nums.sort( (a, b) => a - b ) // Sort nums for searching
    let idx_down: number = 0, idx_up: number = nums.length - 1

    while(idx_down < idx_up) { // Assume exactly one solution
        let sum = nums[idx_down] + nums[idx_up]
        if (sum < target) ++idx_down
        else if (sum > target) --idx_up
        else break
    }

    let ans: number[] = []
    original.map( (value, index) => {
        if (value == nums[idx_down]) ans.push(index)
        else if (value == nums[idx_up]) ans.push(index)
    })

    return ans
};