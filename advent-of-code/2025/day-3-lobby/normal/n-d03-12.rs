use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let (mut p1, mut p2) = (0i64, 0i64);
    for line in stdin.lock().lines().flatten() {
        let d: Vec<i32> = line.chars().map(|c| c.to_digit(10).unwrap() as i32).collect();
        let n = d.len();
        let mut mx = 0;
        for i in 0.. n {
            for j in i+1..n {
                mx = mx.max(d[i] * 10 + d[j]);
            }
        }
        p1 += mx as i64;
        let mut res = String::new();
        let mut start = 0;
        for rem in (1..=12).rev() {
            let mut best = start;
            for i in start..=n-rem {
                if d[i] > d[best] { best = i; }
            }
            res. push_str(&d[best]. to_string());
            start = best + 1;
        }
        p2 += res. parse: :<i64>().unwrap();
    }
    println!("{}\n{}", p1, p2);
}
