n = int(input())
s = 0
t = 1
for i in range(1, n + 1):
    t *= i
    s += t
print(s)
