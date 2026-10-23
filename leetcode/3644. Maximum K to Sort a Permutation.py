class Solution:
    def sortPermutation(self, a: list[int]) -> int:
        n = len(a)
        miss = set()
        ans = n
        for i in range(n):
            if a[i] != i:
                ans = min(i, ans)
                miss.add(i)
        if ans == n:
            return 0
        # miss.remove(ans)
        
        bit_position_count = {}
        for tt in miss:
            i = 0
            mm = tt
            while mm:
                x = mm & 1
                if x:
                    if i not in bit_position_count:
                        bit_position_count[i] = 0
                    bit_position_count[i] = bit_position_count[i]+1
                mm >>= 1
                i += 1

        bit_tmp = bit_position_count.copy()
        # print(miss)
        for t in range(ans, -1, -1):
            # print(t)
            possible = True
            original = []
            m = t
            i = 0
            while m:
                x = m & 1
                if x:
                    original.append(i)
                m >>= 1
                i += 1

            cmp = len(miss)
            
            for k in original:
                if k in bit_position_count:
                    if bit_position_count[k] != cmp:
                        possible = False
                        break
                    else :
                        bit_position_count[k] = 0
                else :
                    possible = False

            # for k,v in bit_position_count.items():
            #     if v > 1:
            #         possible = False
            if possible:
                return t
            bit_position_count = bit_tmp.copy()
        
        return 0