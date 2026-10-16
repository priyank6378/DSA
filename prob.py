def input_arr() -> list[int]:
    return [int(i) for i in input().split()]

for i in range(int(input())):
    n = int(input())
    a = input_arr()

    mis = []
    mis_a = []
    for i in range(1, n+1):
        if a[i-1] != i :
            mis.append(i)
            mis_a.append(a[i-1])
    mis_a.reverse()
    ind = 0
    for i in mis:
        a[i-1] = mis_a[ind]
        ind += 1
    # b = a.copy()
    if a == sorted(a):
        print("YES")
    else :
        print("NO")


