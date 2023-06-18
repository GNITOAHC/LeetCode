use std::collections::HashSet;
use std::iter::FromIterator;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        // Generate Hashset from nums
        let mut set: HashSet<i32> = HashSet::from_iter(nums.clone());
        let mut best: i32 = 0;

        for n in &set { // Iterate through set
            if set.contains(&(n - 1)) { continue; } // Not head of sequence
            else {
                let mut inc = n + 1;
                while set.contains(&inc) {
                    inc += 1;
                }
                best = if inc - n > best { inc - n } else { best };
            }
        }

        best
    }
}