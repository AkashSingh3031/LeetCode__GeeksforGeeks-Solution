class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num = set(nums)
        ans = 0
        for i in num:
            if i - 1 not in num:
                count = 1
                while (i+count) in num:
                    count += 1
                ans = max(ans, count)
        return ans