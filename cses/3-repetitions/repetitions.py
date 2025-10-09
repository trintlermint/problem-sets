seq = list(input())
#print(seq)
max = 1
cur = 1
for i in range(len(seq)-1):
    if seq[i] == seq[i+1]:
        cur += 1
        if cur > max:
            max = cur 
    else:
        cur = 1
print(max)
