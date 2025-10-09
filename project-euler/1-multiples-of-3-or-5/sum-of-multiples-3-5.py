n = 1000
sum = 0
for i in range(n):
    if i%3 == 0 or i%5 == 0:
        sum += i
    else:
        continue 
print(sum)
