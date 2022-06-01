class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num;
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++) {
            num.insert(nums[i]);
        }
        
        for(int i=0; i<nums.size(); i++) {
            int x = nums[i];
            if(num.find(x-1) == num.end()) {
                int curr = 1;
                while(num.find(x+curr) != num.end()) {
                    curr++;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};