use std::io::{self, BufRead};

fn main() {
    let lines:  Vec<String> = io::stdin().lock().lines().flatten().collect();
    let maxlen = lines.iter().map(|l| l.len()).max().unwrap_or(0);
    let padded: Vec<String> = lines.iter().map(|l| format!("{:width$}", l, width = maxlen)).collect();
    
    let cols: Vec<String> = (0..maxlen).map(|c| {
        padded.iter().map(|l| l. chars().nth(c).unwrap_or(' ')).collect()
    }).collect();
    
    fn solve(cs: &[String]) -> i64 {
        let mut total = 0i64;
        let mut i = 0;
        while i < cs.len() {
            while i < cs.len() && cs[i].trim().is_empty() { i += 1; }
            if i >= cs.len() { break; }
            let mut j = i;
            while j < cs.len() && !cs[j].trim().is_empty() { j += 1; }
            let op = cs[i].chars().last().unwrap();
            let nums: Vec<i64> = (i..j).filter_map(|k| {
                let s:  String = cs[k].chars().take(cs[k].len() - 1).filter(|&c| c != ' ').collect();
                if s.is_empty() { None } else { s.parse().ok() }
            }).collect();
            total += if op == '+' { nums.iter().sum() } else { nums.iter().product() };
            i = j;
        }
        total
    }
    
    println!("{}", solve(&cols));
    let rev:  Vec<String> = cols.into_iter().rev().collect();
    println!("{}", solve(&rev));
}
