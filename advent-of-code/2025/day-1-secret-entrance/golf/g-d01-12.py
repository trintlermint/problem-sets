import sys;p,a,b=50,0,0
for l in sys.stdin.read().strip().split('\n'):
 d,n=l[0],int(l[1:])
 for _ in range(n):p=(p+(-1if d=='L'else 1))%100;b+=p==0
 a+=p==0
print(a);print(b)
