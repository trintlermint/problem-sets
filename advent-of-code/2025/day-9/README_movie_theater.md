@.1mbalance @orangeflu 

# ::SPOILERS::

so, firstly, we take each input and ||evaluate it as a tuple (x,y)|| by doing ||p=*map(eval,open(0))||
p here is the ||list of red-tile coords in the given order, forming the closed path||

next, we can ||build up a polygon||, to do this initially we setup the ||edges||, to do this i basically first called ||zip(p, p[1:] + p)|| for ||pairing each point with its next successor, and wrapping around to give the initial edges.||. Next, for any edge ||(( x_1, y_1), (x_2), y_2))|| and the || zip(*x)|| we map it to ||[(x_1, x_2), (y_1, y_2)]|| then to make a ||greedy|| construction we ||sort each pair|| so that we get ||[[xmin, xmax],[ymin, ymax]]|| by calling ||map(S:=sorted, zip(*x))|| (in my code) ||. then this makes our || list of the axis-aligned edges|| which are ||each either horizontal/vertical with the sorted coordinate ranges|| lets say this ||list is `s`.||

then i did codegolfing, to compute inclusive rectangle area one can consider || `python: ~k = -(k+1)`|| meaning that ||for a span d = R -  Q, ~d = -(d+1); multiplying two `~`values leads to the inclusive `len+1` product: `(~(R-Q))*(~(J-I)) = (R-Q+1)*(J-I+1)` when `J >= I, R >= Q` (sign flip cancel)||

but anyway, we then form an ||outer loop|| over the ||pairs of the red corners||, so lets say for my below code: 

||
```py
x = y = 0
for I, q in p:          # corner 1: (I, q)
  for J, r in p:       # corner 2: (J, r)
    Q, R = S([q, r])   # sorted y’s
    A = ~(R - Q) * ~(J - I)  # inclusive area between the two corners
    x = M(x, A)         # part 1 candidate
```
||

||`(I, q) and (J,r)` are two red tiles chosen as opposite rectangle corners||,
||A is the rectagle area with the inclusive coordinates||
|| x is keeping track of the maximum area overall all the pairs, which solves part 1 (largest rectangle using any two red tiles as opposite corners, with no restrictions in the interior)||


then with this, we can put some more code to make a ||validity check|| like the soyboys we are, inside the ||red/green region|| by doing:

||
```py
    y = M(y, all(
      ~M(~b, -J) < M(a, I+1) or ~M(~d, -R) < M(c, Q+1)
      for (a, b), (c, d) in s
    ) * A)
```
||
here we see that for each ||polygon edge|| with ||x-range [a,b] and y range [c,d]|| that:

||
- `~M(~b, -J) < M(a, I+1)` is equivalent to saying the edge’s xrange and the rectangle’s x-range are disjoint after an open/closed offset
then,
||
- after simplifying `~M(~b, -J) = min(b+1, J) - 1 and M(a, I+1) = max(a, I+1)`.
||
and
|| `~M(~d, -R) < M(c, Q+1)` analogously checks disjointness in y.||

from this we extrapolate that:

||
`(~M(~b, -J) < M(a, I+1)) or (~M(~d, -R) < M(c, Q+1))` describes the edge doesnt intresect w the open interior of the candidate rectangle (its seperated in x or in y)
||

with ||`all(...)` makes this be a requiremnt for every edge of the polygon, so the rectangle lies fully inside (or boundary) of the red/green/ region bounded by the path)
||

if the ||rectangle is valid(all(...) holds)|| then => ||it contributes A to the max, otherwise it contributes 0.|| ||y tracks the largest valid area which solves||

# Code:

```py
p=*map(eval,open(0)),
M=max
s=[[*map(S:=sorted,zip(*x))]for x in zip(p,p[1:]+p)]
x=y=0
for I,q in p:
 for J,r in p:Q,R=S([q,r]);x=M(x,A:=~(R-Q)*~(J-I));y=M(y,all(~M(~b,-J)<M(a,I+1)or~M(~d,-R)<M(c,Q+1)for(a,b),(c,d)in s)*A)
print(x,y)
``` 

