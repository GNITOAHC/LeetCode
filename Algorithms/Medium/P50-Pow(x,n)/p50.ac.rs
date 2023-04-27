impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        fn pow(x: f64, res: f64, n: i64) -> f64 {
            // x: buffer, res: response, n: power time
            match n {
                0 => res, // is n equals to 0, return res
                // If n is odd, pow the res
                n if n & 1 == 1 => pow(x * x, res * x, n >> 1),
                // Else x * x
                _ => pow(x * x, res, n >> 1)
            }
        }
        match n {
            0 => 1.0, // If equals 0, return 1
            // If n < 0, return pow but of 1/x
            n if n < 0 => pow(1.0 / x, 1.0, (n as i64).abs()),
            _ => pow(x, 1.0, n as i64)
        }
    }
}
