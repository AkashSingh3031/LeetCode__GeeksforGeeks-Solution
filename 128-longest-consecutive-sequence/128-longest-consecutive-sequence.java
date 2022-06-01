class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> num = new HashSet<Integer>();
        int ans = 0;
        
        for(int i : nums) {
            num.add(i);
        }
        
        for(int i : nums){
            if(!num.contains(i-1)){
                int count = 1;
                while(num.contains(i+count)){
                    count++;
                }
                ans = Math.max(ans, count);
            }
        }
        return ans;
    }
}