class Solution:
    def minOperations(self, a: List[int]) -> int:
        n = len(a)
        ans = n+10
        if (n == 1) :
            return 0
        if (n == 2) :
            if a[0] == 0:
                return 0
            else:
                return 1
        zero_ind = a.index(0)
        search_direction = None

        if (a[(zero_ind - 1)%n] == 1) :
            search_direction = "L"
        elif a[(zero_ind + 1)%n] == 1:
            search_direction = 'R'

        if not search_direction:
            return -1

        if search_direction == 'R' : 
            i = (zero_ind + 1)%n # 1 position
            prev = 0
            possible = True
            while i!=zero_ind and possible:
                if (prev + 1 != a[i]) :
                    possible = False
                else :
                    prev += 1
                    i = (i + 1)%n

            if possible:
                ans = zero_ind
            else :
                return -1

        else:
            i = (zero_ind - 1)%n # 1 position
            prev = 0
            possible = True
            while i!=zero_ind and possible:
                if (prev + 1 != a[i]) :
                    possible = False
                else :
                    prev += 1
                    i = (i - 1)%n

            if possible:
                ans = min(zero_ind + 1 + 1, 1 + (n-1-zero_ind))
            else :
                return -1


        a.reverse()
        zero_ind = a.index(0)
        search_direction = None

        if (a[(zero_ind - 1)%n] == 1) :
            search_direction = "L"
        elif a[(zero_ind + 1)%n] == 1:
            search_direction = 'R'

        if not search_direction:
            return -1

        if search_direction == 'R' : 
            i = (zero_ind + 1)%n # 1 position
            prev = 0
            possible = True
            while i!=zero_ind and possible:
                if (prev + 1 != a[i]) :
                    possible = False
                else :
                    prev += 1
                    i = (i + 1)%n

            if possible:
                ans = min(ans, 1 + zero_ind)
            else :
                return -1

        else:
            i = (zero_ind - 1)%n # 1 position
            prev = 0
            possible = True
            while i!=zero_ind and possible:
                if (prev + 1 != a[i]) :
                    possible = False
                else :
                    prev += 1
                    i = (i - 1)%n

            if possible:
                ans = min(ans, 1+ min(zero_ind + 1 + 1, 1 + (n-1-zero_ind)))
            else :
                return -1

        return ans