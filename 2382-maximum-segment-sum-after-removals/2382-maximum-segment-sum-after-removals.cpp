class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        multiset<long long> s;
        s.insert(0);
        set<pair<int, int>> in;
        vector<long long> pre(n, nums[0]);
        for(int i = 1; i < n; i++) pre[i] = pre[i - 1] + nums[i];
        
        in.insert({0, n - 1});
        
        s.insert(pre[n - 1]);
        
        vector<long long> ans;
        for(auto p : removeQueries) {
            auto it = in.upper_bound({p, 2e9});
            if(it == in.begin()) {
                ans.push_back(0);
                continue;
            }
            it--;
            
            long long L = (p ? pre[p - 1] : 0) - (it -> first ? pre[it -> first - 1] : 0);
            long long R = pre[it -> second] - pre[p];
            long long T = pre[it -> second] - (it -> first ? pre[it -> first - 1] : 0);
            
            s.erase(s.find(T));
            if(it -> first <= p - 1) {
                in.insert({it -> first, p - 1});
                s.insert(L);
            }
            if(it -> second >= p + 1) {
                in.insert({p + 1, it -> second});
                s.insert(R);
            }
            
            in.erase(it);
            ans.push_back(*s.rbegin());
        }
        return ans;
    }
};