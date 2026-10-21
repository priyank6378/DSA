# very slow

class Solution:
    def minOperations(self, s: str) -> int:

        if "".join(sorted(s)) == s: 
            return 0

        # max ans = 3
        n = len(s)

        ans_1 = 1
        a = s[:n-1]
        a = sorted(a)
        a.append(s[n-1])
        # print(a)
        if a != sorted(a):
            ans_1 += 1
            t = a[1:]
            t = sorted(t)
            t.insert(0, a[0])
            # print(t)
            if t != sorted(t):
                ans_1 += 1
                a = t[:n-1]
                a = sorted(a)
                a.append(t[n-1])
                # print(a)
                if a != sorted(a):
                    ans_1 += 1

        ans_2 = 1
        a = s[1:]
        a = sorted(a)
        a.insert(0, s[0])
        if a != sorted(a):
            ans_2 += 1
            t = a[:n-1]
            t = sorted(t)
            t.append(a[n-1])
            if t != sorted(t):
                ans_2 += 1
                a = t[1:n]
                a = sorted(a)
                a.insert(0, t[0])
                if a != sorted(a):
                    ans_2+=1

        # print(ans_1, ans_2)

        return min(ans_1, ans_2) if min(ans_1, ans_2) <= 3 else -1
        