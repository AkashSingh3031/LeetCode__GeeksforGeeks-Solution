class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        seen = {}
        for i, firstNumber in enumerate(nums):
            secondNumber = target - firstNumber # firstNumber + secondNumber = target
            
            if secondNumber in seen:
                return [seen[secondNumber], i]
            else:
                seen[firstNumber] = i