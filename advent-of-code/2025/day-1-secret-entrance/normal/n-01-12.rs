use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut pos:  i32 = 50;
    let (mut p1, mut p2) = (0, 0);
    for line in stdin.lock().lines().flatten() {
        let d = line.chars().next().unwrap();
        let n:  i32 = line[1..].parse().unwrap();
        for _ in 0.. n {
            pos = (pos + if d == 'L' { -1 } else { 1 }).rem_euclid(100);
            if pos == 0 { p2 += 1; }
        }
        if pos == 0 { p1 += 1; }
    }
    println!("{}\n{}", p1, p2);
}
