n = int(input())
a = [int(x) for x in input().split()]
b = [0 for i in range(n+1)]
for i in a:
    b[i] = 1
for i in range(1, n+1):
    if b[i] == 0:
        print(i)
        break