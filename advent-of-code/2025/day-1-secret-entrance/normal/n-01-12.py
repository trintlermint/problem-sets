import sys

def solve(data):
    lines = data.strip().split('\n')
    pos = 50
    p1 = p2 = 0
    for line in lines:
        d = line[0]
        n = int(line[1:])
        for _ in range(n):
            if d == 'L':
                pos = (pos - 1) % 100
            else:
                pos = (pos + 1) % 100
            if pos == 0:
                p2 += 1
        if pos == 0:
            p1 += 1
    return p1, p2

if __name__ == "__main__": 
    p1, p2 = solve(sys.stdin. read())
    print(p1)
    print(p2)
