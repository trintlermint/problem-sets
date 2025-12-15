use std::io::{self, BufRead};
use std::collections: :{HashMap, HashSet, VecDeque};

fn main() {
    let grid: Vec<Vec<char>> = io::stdin().lock().lines().flatten().map(|l| l.chars().collect()).collect();
    let (h, w) = (grid.len(), grid[0].len());
    let sx = (0.. w).find(|&x| grid[0][x] == 'S').unwrap();
    let mut splits = 0;
    let mut queue = VecDeque::new();
    let mut visited = HashSet::new();
    queue.push_back((0, sx));
    while let Some((y, x)) = queue.pop_front() {
        if visited.contains(&(y, x)) { continue; }
        visited.insert((y, x));
        let ny = y + 1;
        if ny >= h { continue; }
        if grid[ny][x] == '^' {
            splits += 1;
            if x > 0 { queue.push_back((ny, x - 1)); }
            if x < w - 1 { queue.push_back((ny, x + 1)); }
        } else { queue.push_back((ny, x)); }
    }
    fn count_paths(y: usize, x: usize, h: usize, w: usize, grid: &Vec<Vec<char>>, memo: &mut HashMap<(usize, usize), i64>) -> i64 {
        if y >= h { return 1; }
        if let Some(&v) = memo.get(&(y, x)) { return v; }
        let ny = y + 1;
        if ny >= h { return 1; }
        let result = if grid[ny][x] == '^' {
            (if x > 0 { count_paths(ny, x - 1, h, w, grid, memo) } else { 0 }) +
            (if x < w - 1 { count_paths(ny, x + 1, h, w, grid, memo) } else { 0 })
        } else { count_paths(ny, x, h, w, grid, memo) };
        memo.insert((y, x), result);
        result
    }
    
    let mut memo = HashMap::new();
    println!("{}\n{}", splits, count_paths(0, sx, h, w, &grid, &mut memo));
}
