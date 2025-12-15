use std::io::{self, BufRead};

fn count_n(g: &Vec<Vec<char>>, y:  i32, x: i32, h: i32, w: i32) -> i32 {
    let mut c = 0;
    for dy in -1..=1 {
        for dx in -1..=1 {
            if dy == 0 && dx == 0 { continue; }
            let ny = y + dy;
            let nx = x + dx;
            if ny >= 0 && ny < h && nx >= 0 && nx < w && g[ny as usize][nx as usize] == '@' {
                c += 1;
            }
        }
    }
    c
}

fn main() {
    let g: Vec<Vec<char>> = io::stdin().lock().lines().flatten().map(|l| l.chars().collect()).collect();
    let (h, w) = (g.len() as i32, g[0]. len() as i32);
    
    let p1: i32 = (0..h).flat_map(|y| (0..w).map(move |x| (y, x)))
        .filter(|&(y, x)| g[y as usize][x as usize] == '@' && count_n(&g, y, x, h, w) < 4).count() as i32;
    
    let mut g2 = g.clone();
    let mut total = 0;
    loop {
        let rem:  Vec<(i32, i32)> = (0..h).flat_map(|y| (0..w).map(move |x| (y, x)))
            .filter(|&(y, x)| g2[y as usize][x as usize] == '@' && count_n(&g2, y, x, h, w) < 4).collect();
        if rem.is_empty() { break; }
        total += rem.len();
        for (y, x) in rem { g2[y as usize][x as usize] = '.'; }
    }
    println! ("{}\n{}", p1, total);
}
