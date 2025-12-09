p=*map(eval,open(0)),
M=max
s=[[*map(S:=sorted,zip(*x))]for x in zip(p,p[1:]+p)]
x=y=0
for I,q in p:
 for J,r in p:Q,R=S([q,r]);x=M(x,A:=~(R-Q)*~(J-I));y=M(y,all(~M(~b,-J)<M(a,I+1)or~M(~d,-R)<M(c,Q+1)for(a,b),(c,d)in s)*A)
print(x,y)
