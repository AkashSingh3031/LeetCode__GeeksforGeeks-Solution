class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int a=0;
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[a++]);
            }
        }
        for(; a<n; a++) {
            nums[a] = 0;
        }
    }
};