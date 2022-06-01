class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i], m = target - n;
            if (hash.containsKey(m)) 
                return new int[]{hash.get(m), i};
            else
                hash.put(n, i);
        }
        return new int[]{};
    }
}