class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        left = 0
        right = len(s) - 1

        def recursiveReverse(l, r):

            if l == r or l > r:
                return

            s[l], s[r] = s[r], s[l]
            return recursiveReverse(l + 1, r - 1)
        recursiveReverse(left, right)
        return s