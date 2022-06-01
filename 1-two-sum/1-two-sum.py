class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash = {}
        for i, n in enumerate(nums):
            m = target - n
            if m in hash:
                return [hash[m], i]
            else:
                hash[n] = i