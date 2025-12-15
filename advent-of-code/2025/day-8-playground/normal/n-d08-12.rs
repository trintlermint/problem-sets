use std::io::{self, BufRead};
use std::collections::HashSet;

struct UF { p: Vec<usize>, s: Vec<usize> }
impl UF {
    fn new(n: usize) -> Self { UF { p: (0..n).collect(), s: vec![1; n] } }
    fn find(&mut self, x: usize) -> usize {
        if self.p[x] != x { self.p[x] = self.find(self.p[x]); }
        self.p[x]
    }
    fn unite(&mut self, x: usize, y: usize) -> bool {
        let (mut px, mut py) = (self.find(x), self.find(y));
        if px == py { return false; }
        if self.s[px] < self.s[py] { std::mem::swap(&mut px, &mut py); }
        self.p[py] = px; self.s[px] += self.s[py]; true
    }
}

fn main() {
    let pts: Vec<Vec<i64>> = io::stdin().lock().lines().flatten()
        .map(|l| l.split(',').map(|x| x.parse().unwrap()).collect()).collect();
    let n = pts.len();
    let mut dists: Vec<(f64, usize, usize)> = vec![];
    for i in 0..n { for j in i+1..n {
        let d = ((0.. 3).map(|k| (pts[i][k] - pts[j][k]).pow(2) as f64).sum::<f64>()).sqrt();
        dists.push((d, i, j));
    }}
    dists.sort_by(|a, b| a. 0.partial_cmp(&b.0).unwrap());
    
    let mut uf1 = UF::new(n);
    for &(_, i, j) in dists.iter().take(1000) { uf1.unite(i, j); }
    let mut sizes:  Vec<usize> = (0..n).filter(|&i| uf1.find(i) == i).map(|i| uf1.s[i]).collect();
    sizes.sort_by(|a, b| b.cmp(a));
    println!("{}", sizes[0] as i64 * sizes[1] as i64 * sizes[2] as i64);
    
    let mut uf2 = UF::new(n);
    for &(_, i, j) in &dists {
        if uf2.unite(i, j) {
            let roots: HashSet<usize> = (0..n).map(|k| uf2.find(k)).collect();
            if roots.len() == 1 { println!("{}", pts[i][0] * pts[j][0]); break; }
        }
    }
}
