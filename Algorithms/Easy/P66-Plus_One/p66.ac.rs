impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut digits = digits;
        digits.reverse();
        let mut count: i32 = 0;
        digits[0] += 1;
        if digits[0] >= 10 {
            count = digits[0] / 10;
            digits[0] = digits[0] % 10;
        }
        for i in 1..digits.len() {
            digits[i] += count;
            count = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        if count > 0 {
            digits.push(count);
        }
        digits.reverse();
        digits
    }
}
