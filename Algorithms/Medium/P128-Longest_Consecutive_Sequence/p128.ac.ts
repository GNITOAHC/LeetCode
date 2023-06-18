function longestConsecutive(nums: number[]): number {
    const set = new Set(nums) // Generate set from nums
    let best: number = 0

    set.forEach((value) => {
        if (!set.has(value - 1)) { // If value is head of sequence
            let inc: number = value + 1
            while (set.has(inc)) inc += 1
            best = best > inc - value ? best : inc - value
        }
    })

    return best
};