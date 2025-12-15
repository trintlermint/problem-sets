import sys;L=sys.stdin.read().strip().split('\n');h,w=len(L),len(L[0]);g=[list(l)for l in L]
def N(g,y,x):return sum(0<=y+dy<h and 0<=x+dx<w and g[y+dy][x+dx]=='@'for dy in[-1,0,1]for dx in[-1,0,1]if dy or dx)
print(sum(g[y][x]=='@'and N(g,y,x)<4 for y in range(h)for x in range(w)))
g2=[r[:]for r in g];t=0
while 1:
 R=[(y,x)for y in range(h)for x in range(w)if g2[y][x]=='@'and N(g2,y,x)<4]
 if not R:break
 t+=len(R)
 for y,x in R:g2[y][x]='.'
print(t)
