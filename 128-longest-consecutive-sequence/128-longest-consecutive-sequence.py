class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num = set(nums)
        ans = 0
        for x in num:
            if x - 1 not in num:
                curr = x + 1
                while curr in num:
                    curr += 1
                ans = max(ans, curr - x)
        return ans