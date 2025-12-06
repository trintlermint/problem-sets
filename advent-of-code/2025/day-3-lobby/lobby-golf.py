#p1
# import sys;print(sum(int(max(w[:-1])+max(w[w.index(max(w[:-1]))+1:]))for w in sys.stdin.read().split()))
from sys import*;a=b=0
for s in stdin.read().split():
 m=max(s[:-1]);i=s.index(m);a+=int(m+max(s[i+1:]))
 k=len(s)-12;t=[]
 for c in s:
  while k and t and t[-1]<c:k-=1;t.pop()
  t+=c,
 b+=int(''.join(t[:12]))
print(a,b)
