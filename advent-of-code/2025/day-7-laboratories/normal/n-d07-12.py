import sys

def solve(data):
    lines = data.strip().split('\n')
    grid = [list(line) for line in lines]
    h, w = len(grid), len(grid[0])
    
    # Find S
    start_x = None
    for x in range(w):
        if grid[0][x] == 'S':
            start_x = x
            break
    from collections import deque
    splits = 0
    beams = deque()
    beams.append((0, start_x))  # (y, x)
    visited = set()
    
    while beams:
        y, x = beams.popleft()
        if (y, x) in visited:
            continue
        visited.add((y, x))
        
        # Move down
        ny = y + 1
        if ny >= h:
            continue
        if grid[ny][x] == '^':
            splits += 1
            # Emit left and right
            if x - 1 >= 0:
                beams.append((ny, x - 1))
            if x + 1 < w:
                beams.append((ny, x + 1))
        else:
            beams.append((ny, x))
    
    # Part 2: count all paths (timelines)
    sys.setrecursionlimit(100000)
    memo = {}
    
    def count_paths(y, x):
        if y >= h: 
            return 1
        if (y, x) in memo:
            return memo[(y, x)]
        
        ny = y + 1
        if ny >= h:
            return 1
        
        if grid[ny][x] == '^':
            result = 0
            if x - 1 >= 0:
                result += count_paths(ny, x - 1)
            if x + 1 < w:
                result += count_paths(ny, x + 1)
        else:
            result = count_paths(ny, x)
        
        memo[(y, x)] = result
        return result
    
    p2 = count_paths(0, start_x)
    
    return splits, p2

if __name__ == "__main__":
    p1, p2 = solve(sys.stdin.read())
    print(p1)
    print(p2)
