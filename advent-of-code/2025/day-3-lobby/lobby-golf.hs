import Data.Char
g(k,s)c|k>0&&s/=[]&&last s<c=g(k-1,init s)c|0<1=(k,s++[c])
f z=(a,b)where t=init z;(u,m:v)=break(==maximum t)t;m2=maximum(v++[last z]);a=fromEnum m*10+fromEnum m2-528;(k,s')=foldl g(length z-12,"")z;b=read$take 12 s'
main=interact$ \x->let(a,b)=foldl(\(p,q)s->let(u,v)=f s in(p+u,q+v))(0,0)(words x)in show a++" "++show b
