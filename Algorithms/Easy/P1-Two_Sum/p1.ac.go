func twoSum(nums []int, target int) []int {
    sorted := make([][2]int, len(nums))

    for i, num := range nums {
		sorted[i] = [2]int{i, num}
	}

    sort.Slice(sorted, func(i, j int) bool {
        return sorted[i][1] < sorted[j][1]
    })

    left, right := 0, len(nums) - 1

    for left < right {
        sum := sorted[left][1] + sorted[right][1]

        switch {
            case sum == target:
                return []int{sorted[left][0], sorted[right][0]}
            case sum < target:
                left++
                break
            case sum > target:
                right--
                break
        }
    }

    return []int{}
}