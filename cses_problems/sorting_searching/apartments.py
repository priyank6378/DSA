import sys
n,m,k = [int(x) for x in input().split()]
a = [(int(x)-k, int(x)+k) for x in input().split()]
b = [int(x) for x in input().split()]


a.sort(key=lambda x : x[0])
b.sort()

i,j = 0,0
ans = 0
while i<n and j<m:
    x,y = a[i]
    z = b[j]
    if z<x : 
        j+=1
    elif z>y:
        i+=1
    elif z>=x and z<=y:
        i+=1
        j+=1
        ans+=1
print(ans)