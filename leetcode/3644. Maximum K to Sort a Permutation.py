class Solution:
    def sortPermutation(self, a: list[int]) -> int:
        n = len(a)
        t = 2**32 - 1
        ans = t
        for i in range(n):
            if a[i] != i:
                ans &= i
        if ans != t:
            return ans
        return 0
        