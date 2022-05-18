class Solution
{
  public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> vec;
        unordered_map<int,int> mp;
        int len=nums.size();
        for(int i=0;i<len;i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                vec.push_back(mp[target-nums[i]]);
                vec.push_back(i);
                return vec;
            }
            mp[nums[i]]=i;
        }
        return vec;
    }
};