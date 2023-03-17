impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut previous = None;
        let mut count = 0;

        for i in 0..nums.len() {
            if Some(nums[i]) != previous {
                previous = Some(nums[i]);
                nums.swap(i, count);
                count += 1;
            }
        }

        count as i32
    }
}
