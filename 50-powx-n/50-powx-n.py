class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if (n == 0):
            return 1
        elif (x in [0, 1]) or (n == 1):
            return x

        res = 1
        if (n < 0):
            x = 1 / x
            n = - (n + 1)
            res *= x
        while n > 0:
            if (n % 2): # n is odd
                res *= x
                n -= 1
            else: # jump 2 steps when n is even
                x *= x
                n //= 2
        return res