class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int total = 0;
        int res = 0;
        
        for(auto n : nums) {
            if(n) {
                total++;
                res = max(res, total);
            } else {
                total = 0;
            }
        }
        
        return res;
    }
};