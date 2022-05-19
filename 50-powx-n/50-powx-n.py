class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0: 
            return 1
        if n < 0: 
            n, x = -n, 1 / x
        lower = self.myPow(x, n//2)
        return lower * lower * x if n % 2 else lower * lower