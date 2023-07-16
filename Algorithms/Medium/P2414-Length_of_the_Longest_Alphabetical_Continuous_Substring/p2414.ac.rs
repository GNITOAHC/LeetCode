impl Solution {
    pub fn longest_continuous_substring(s: String) -> i32 {
        let mut ans: i32 = if s.len() == 0 { 0 } else { 1 };
        let mut tmp_ans: i32 = ans;
        let arr = s.chars()
                   .map(|char| char as i32 - 96)
                   .collect::<Vec<i32>>();
        for i in 1..arr.len() {
            if arr[i] == arr[i - 1] + 1 {
                tmp_ans = tmp_ans + 1;
                ans = if tmp_ans > ans { tmp_ans } else { ans };
            } else {
                tmp_ans = 1;
            }
        }
        ans
    }
}