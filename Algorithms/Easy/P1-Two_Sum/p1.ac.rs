impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut v = Vec::<i32>::new();
        for i in &nums {
            v.push(*i);
        }
        v.sort();
        let (mut front, mut end): (usize, usize) = (0, v.len() - 1);
        loop {
            if (front > end || v[front] + v[end] == target) {
                break;
            } else if v[front] + v[end] > target {
                end -= 1;
            } else if v[front] + v[end] < target {
                front += 1;
            }
        }
        let (front, end) = (v[front], v[end]);
        let mut r = Vec::<i32>::new();
        for i in 0..nums.len() {
            if &nums[i] == &front {
                r.push(i as i32);
            } else if &nums[i] == &end {
                r.push(i as i32);
            }
        }
        r
    }
}
