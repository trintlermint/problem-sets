p=a=b=0
for x in open(0):exec("p+=x>'M'or-1;y=p%100==50;b+=y;"*int(x[1:]));a+=y
print(a,b)
