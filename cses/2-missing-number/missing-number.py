n = int(input())
numbers = list(map(int, input().split()))

xor_all = 0
for i in range(1, n+1):
    xor_all ^= i
for num in numbers:
    xor_all ^= num
print(xor_all)
