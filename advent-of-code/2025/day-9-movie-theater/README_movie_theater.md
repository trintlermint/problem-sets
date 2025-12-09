Firstly, we take each input and evaluate it as a tuple (x, y) by doing `p=*map(eval,open(0))`.  
Here, `p` is the list of red-tile coordinates in the given order, forming the closed path.

To build up the polygon, initially we set up the edges by calling `zip(p, p[1:] + p)`, pairing each point with its successor and wrapping around to form the initial edges.

For any edge `((x₁, y₁), (x₂, y₂))`, `zip(*x)` maps it to `[(x₁, x₂), (y₁, y₂)]`.  
To make a greedy construction, we sort each pair so that we obtain `[[xmin, xmax], [ymin, ymax]]` by calling `map(S:=sorted, zip(*x))` in the code.  
This produces a list of axis-aligned edges, each either horizontal or vertical with sorted coordinate ranges.  
Let this list be denoted as `s`.

To compute the inclusive rectangle area, consider the operation `~k = -(k+1)`.  
For a span `d = R - Q`, `~d = -(d+1)`.  
Multiplying two such values provides the inclusive `(length + 1)` product: `(~(R-Q))*(~(J-I)) = (R-Q+1)*(J-I+1)`, assuming `J >= I, R >= Q`.  
This takes care of the closed interval requirement.

Now, we form an outer loop over pairs of the red corners, so in the code:

```py
x = y = 0
for I, q in p:          # corner 1: (I, q)
  for J, r in p:       # corner 2: (J, r)
    Q, R = S([q, r])   # sorted y’s
    A = ~(R - Q) * ~(J - I)  # inclusive area between the two corners
    x = M(x, A)         # part 1 candidate
```

Here, `(I, q)` and `(J, r)` are two red tiles chosen as opposite rectangle corners.  
`A` is the rectangle area with the inclusive coordinates.  
`x` keeps track of the maximum area over all the pairs, which solves part 1 (largest rectangle using any two red tiles as opposite corners).

For region validity checking:

```py
    y = M(y, all(
      ~M(~b, -J) < M(a, I+1) or ~M(~d, -R) < M(c, Q+1)
      for (a, b), (c, d) in s
    ) * A)
```

For each polygon edge with x-range `[a, b]` and y-range `[c, d]`:
- `~M(~b, -J) < M(a, I+1)` states that the edge's x-range and the rectangle's x-range are disjoint after an open/closed offset.
- After simplifying: `~M(~b, -J) = min(b+1, J) - 1`, and `M(a, I+1) = max(a, I+1)`.
- `~M(~d, -R) < M(c, Q+1)` checks disjointness in y.
- Therefore, `(~M(~b, -J) < M(a, I+1)) or (~M(~d, -R) < M(c, Q+1))` means the edge does not intersect the open interior of the candidate rectangle.

`all(...)` requires this condition to be true for every edge of the polygon, so the rectangle lies fully inside (or on the boundary of) the region bounded by the path.

If the rectangle is valid (i.e., `all(...)` holds for all edges), it contributes `A` to the maximum; otherwise, it contributes `0`.  
`y` tracks the largest valid area.

## Code

```py
p=*map(eval,open(0)),
M=max
s=[[*map(S:=sorted,zip(*x))]for x in zip(p,p[1:]+p)]
x=y=0
for I,q in p:
 for J,r in p:Q,R=S([q,r]);x=M(x,A:=~(R-Q)*~(J-I));y=M(y,all(~M(~b,-J)<M(a,I+1)or~M(~d,-R)<M(c,Q+1)for(a,b),(c,d)in s)*A)
print(x,y)
```
