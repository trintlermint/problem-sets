import scipy
from numpy import*
l=c=0
for z in open(0,"rb"):t,*b,j=z.split();v=[1]*len(b);k=len(j:=eval(j[1:-1]));L=lambda B,*C:int(.5+scipy.optimize.milp(v+[0]*B,integrality=v+[1]*B,constraints=C).fun);c+=L(0,x:=c_[*[isin(r_[:k]+48,a)for*a,in b]],j,j);l+=L(k,c_[x,-2*eye(k)],s:=r_[[*t[1:-1]]]%2,s)
print(l,c)
