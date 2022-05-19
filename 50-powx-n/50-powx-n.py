class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if (n == 0):
            return 1
        elif (x == 0):
            return 0

        else:
            if (n < 0):
                return 1 / self.myPow(x, -n)
            else:
                temp = self.myPow(x, n//2)
                if (n % 2 == 0):
                    return temp * temp
                else:
                    return temp * temp * x