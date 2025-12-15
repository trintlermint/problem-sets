use std::io::{self, Read};

fn is_double(n: i64) -> bool {
    let s = n.to_string();
    if s.len() % 2 != 0 { return false; }
    let h = s.len() / 2;
    &s[..h] == &s[h..]
}

fn is_repeat(n: i64) -> bool {
    let s = n.to_string();
    for k in 1..s.len() {
        if s.len() % k == 0 {
            let pat = &s[..k];
            if pat.repeat(s.len() / k) == s { return true; }
        }
    }
    false
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let data: String = input.chars().filter(|&c| c != '\n').collect();
    let (mut p1, mut p2) = (0i64, 0i64);
    for r in data.split(',') {
        if r.trim().is_empty() { continue; }
        let parts: Vec<i64> = r.split('-').map(|x| x.parse().unwrap()).collect();
        for n in parts[0]..=parts[1] {
            if is_double(n) { p1 += n; }
            if is_repeat(n) { p2 += n; }
        }
    }
    println!("{}\n{}", p1, p2);
}
