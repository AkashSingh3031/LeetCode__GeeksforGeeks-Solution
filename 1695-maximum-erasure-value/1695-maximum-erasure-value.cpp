class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int result = 0;
        unordered_set<int> hset;
        for (int i = 0, j = 0, win = 0; j < nums.size(); j++) {
            while (hset.find(nums[j]) != hset.end()) {
                hset.erase(nums[i]);
                win -= nums[i];
                i++;
            }
            hset.insert(nums[j]);
            win += nums[j];
            result = max(result, win);
        }
        return result;
    }
};