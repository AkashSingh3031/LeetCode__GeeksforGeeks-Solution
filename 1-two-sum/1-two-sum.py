class Solution
{
  public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); i++)
        {
            int n = nums[i], m = target-n;
            if(hash.find(m) != hash.end())
                return {hash[m], i};
            else
                hash[n] = i;
        }
        return {};
    }
};