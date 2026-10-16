import bisect

n,m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
a.sort()
i,j=0,n-1
ans = 0
while i<j:
    x,y=a[i],a[j]
    if y-m>0:
        j-=1
    elif y-m == 0:
        j-=1
        ans +=1
    elif m-y>0 and x+y<=m:
        i+=1
        j-=1
        ans += 1
    elif x+y>m:
        j-=1
        ans += 1 if y<=m else 0
if i == j and a[i]<=m:
    ans += 1
print(ans)