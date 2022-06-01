class Solution 
{
    public int[] twoSum(int[] nums, int target) 
    {
        HashMap<Integer, Integer> seen = new HashMap<>();
        for (int i = 0; i < nums.length; i++) 
        {
            int firstNumber = nums[i], secondNumber = target - firstNumber;  // firstNumber + secondNumber = target
            
            if (seen.containsKey(secondNumber)) 
                return new int[]{seen.get(secondNumber), i};
            else
                seen.put(firstNumber, i);
        }
        return new int[]{};
    }
}