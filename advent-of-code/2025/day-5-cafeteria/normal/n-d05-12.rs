use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let parts: Vec<&str> = input.trim().split("\n\n").collect();
    let mut ranges:  Vec<(i64, i64)> = parts[0].lines().map(|l| {
        let p: Vec<i64> = l.split('-').map(|x| x.parse().unwrap()).collect();
        (p[0], p[1])
    }).collect();
    ranges.sort();
    
    let mut merged:  Vec<(i64, i64)> = vec![];
    for (lo, hi) in ranges {
        if ! merged.is_empty() && lo <= merged.last().unwrap().1 + 1 {
            let last = merged.last_mut().unwrap();
            last.1 = last.1.max(hi);
        } else {
            merged.push((lo, hi));
        }
    }
    
    let ids: Vec<i64> = parts[1].trim().lines().map(|l| l.parse().unwrap()).collect();
    let p1 = ids.iter().filter(|&&i| merged.iter().any(|&(lo, hi)| lo <= i && i <= hi)).count();
    let p2: i64 = merged.iter().map(|(lo, hi)| hi - lo + 1).sum();
    println!("{}\n{}", p1, p2);
}
