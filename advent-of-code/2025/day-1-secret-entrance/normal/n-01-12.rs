use std::io: :{self, BufRead};
use std::collections::HashMap;

fn main() {
    let stdin = io::stdin();
    let mut a:  Vec<i64> = Vec:: new();
    let mut b: Vec<i64> = Vec:: new();
    for line in stdin.lock().lines().flatten() {
        let nums: Vec<i64> = line.split_whitespace().map(|x| x.parse().unwrap()).collect();
        if nums.len() == 2 { a.push(nums[0]); b.push(nums[1]); }
    }
    a.sort(); b.sort();
    let p1: i64 = a.iter().zip(&b).map(|(x, y)| (x - y).abs()).sum();
    let mut cnt: HashMap<i64, i64> = HashMap::new();
    for &v in &b { *cnt.entry(v).or_insert(0) += 1; }
    let p2: i64 = a.iter().map(|x| x * cnt. get(x).unwrap_or(&0)).sum();
    println!("{}\n{}", p1, p2);
}
