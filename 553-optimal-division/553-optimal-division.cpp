class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string s;
        s += to_string(nums[0]);
        if (nums.size() == 1) {
            return s;
        }
        
        s += "/";
        if (nums.size() == 2) {
            s += to_string(nums[1]);
            return s;
        }
        
        s += "(";
        for (size_t ii = 1; ii < nums.size(); ii++) {
            s += to_string(nums[ii]) + "/";
        }

        s.pop_back();
        s += ")";
        
        return s;
    }
};