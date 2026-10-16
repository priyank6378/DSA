n = input()
ans = 0
cur = 0
p = 0
for i in n:
    # print(i, p, cur)
    if i == p:
        cur+=1
    else:
        ans = max(cur, ans)
        cur = 1
        p = i

ans = max(ans, cur)
print(ans)
