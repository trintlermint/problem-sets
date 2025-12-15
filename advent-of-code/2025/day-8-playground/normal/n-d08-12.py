import sys
import math

def solve(data):
    lines = data.strip().split('\n')
    points = []
    for line in lines:
        x, y, z = map(int, line. split(','))
        points.append((x, y, z))
    
    n = len(points)
    dists = []
    for i in range(n):
        for j in range(i + 1, n):
            d = math.sqrt((points[i][0] - points[j][0])**2 + 
                         (points[i][1] - points[j][1])**2 + 
                         (points[i][2] - points[j][2])**2)
            dists.append((d, i, j))
    dists.sort()
    
    # Union-Find
    parent = list(range(n))
    size = [1] * n
    
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    def union(x, y):
        px, py = find(x), find(y)
        if px == py:
            return False
        if size[px] < size[py]:
            px, py = py, px
        parent[py] = px
        size[px] += size[py]
        return True
    
    # Part 1: connect 1000 closest pairs, find 3 largest circuits
    connections = 0
    for d, i, j in dists: 
        if connections >= 1000:
            break
        union(i, j)
        connections += 1
    
    # Get circuit sizes
    circuits = {}
    for i in range(n):
        root = find(i)
        circuits[root] = size[root]
    sizes = sorted(circuits.values(), reverse=True)
    p1 = sizes[0] * sizes[1] * sizes[2] if len(sizes) >= 3 else 0
    
    # Part 2: continue until all in one circuit, find last connection
    parent = list(range(n))
    size = [1] * n
    last_pair = None
    
    for d, i, j in dists: 
        if union(i, j):
            # Check if now all connected
            roots = set(find(k) for k in range(n))
            if len(roots) == 1:
                last_pair = (points[i][0], points[j][0])
                break
    
    p2 = last_pair[0] * last_pair[1] if last_pair else 0
    return p1, p2

if __name__ == "__main__": 
    p1, p2 = solve(sys.stdin.read())
    print(p1)
    print(p2)
