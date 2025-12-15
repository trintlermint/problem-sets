a=b=0
l=eval(input().replace(*'-,'))
while l:
 x,y,*l=l
 while~y+x:A=len(s:=str(x))//(s*2).find(s,1);a+=~A%2*x;b+=1%A*x;x+=1
print(a,b)
