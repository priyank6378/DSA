class Solution:
    def days_count(self, d, days_sum):
        a = d[0]
        b = d[1]
        a -= 1
        if a == 0:
            return b
        return days_sum[a-1]+b

    def countDaysTogether(self, aa: str, al: str, ba: str, bl: str) -> int:
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        days_sum = []
        x = 0
        for i in days:
            x += i
            days_sum.append(x)
        d1 = self.days_count([int(x) for x in aa.split("-")], days_sum)
        d2 = self.days_count([int(x) for x in al.split("-")], days_sum)
        d3 = self.days_count([int(x) for x in ba.split("-")], days_sum)
        d4 = self.days_count([int(x) for x in bl.split("-")], days_sum)

        if d2<d3 or d1>d4:
            return 0
        if d1<=d3:
            return min(d2,d4) - d3 + 1
        if d3<=d1:
            return min(d2,d4) - d1 + 1