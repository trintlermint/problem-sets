a,b = 2,3
sum = 0

while a <= 4000000:
    if a%2 == 0:
        sum += a
    if b%2 == 0:
        sum += b
    a,b = a+b, a+b+b
print(sum)
