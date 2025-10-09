
n = 218000
sum = 0
for i in range(n):
    square = i**2
    if square % 2 == 1:
        sum = sum + square
    else:
        continue
print(sum)
