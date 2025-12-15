import sys

def solve(data):
    lines = data.strip().split('\n')
    h, w = len(lines), len(lines[0])
    grid = [list(line) for line in lines]
    
    def count_neighbors(y, x):
        cnt = 0
        for dy in [-1, 0, 1]:
            for dx in [-1, 0, 1]: 
                if dy == 0 and dx == 0:
                    continue
                ny, nx = y + dy, x + dx
                if 0 <= ny < h and 0 <= nx < w and grid[ny][nx] == '@':
                    cnt += 1
        return cnt
    
    # art 1: count accessible rolls
    p1 = sum(1 for y in range(h) for x in range(w) if grid[y][x] == '@' and count_neighbors(y, x) < 4)
    
    # part 2: iteratively remove
    grid2 = [row[:] for row in grid]
    total = 0
    while True:
        to_remove = []
        for y in range(h):
            for x in range(w):
                if grid2[y][x] == '@':
                    cnt = 0
                    for dy in [-1, 0, 1]: 
                        for dx in [-1, 0, 1]: 
                            if dy == 0 and dx == 0:
                                continue
                            ny, nx = y + dy, x + dx
                            if 0 <= ny < h and 0 <= nx < w and grid2[ny][nx] == '@':
                                cnt += 1
                    if cnt < 4:
                        to_remove. append((y, x))
        if not to_remove:
            break
        total += len(to_remove)
        for y, x in to_remove: 
            grid2[y][x] = '.'
    return p1, total

if __name__ == "__main__":
    p1, p2 = solve(sys.stdin.read())
    print(p1)
    print(p2)
