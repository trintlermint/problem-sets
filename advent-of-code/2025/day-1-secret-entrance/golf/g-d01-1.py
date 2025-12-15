p=a=0
for x in open(0):p+=sum([(x>'M')or-1]*int(x[1:]));a+=p%100==50
print(a)

"""
    p=a=b=0
for x in open(0):exec("p+=x>'M'or-1;y=p%100==50;b+=y;"*int(x[1:]));a+=y
print(a,b)
"""
