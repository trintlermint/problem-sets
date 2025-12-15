import sys
from collections import Counter

def solve(data):
    lines = data.strip().split('\n')
    a, b = [], []
    for line in lines: 
        x, y = map(int, line.split())
        a.append(x)
        b.append(y)
    p1 = sum(abs(x - y) for x, y in zip(sorted(a), sorted(b)))
    cnt = Counter(b)
    p2 = sum(x * cnt[x] for x in a)
    return p1, p2

if __name__ == "__main__": 
    data = sys.stdin.read()
    p1, p2 = solve(data)
    print(p1)
    print(p2)
