class Solution {
public:
    double calculateEntropy(vector<int>& X) {
        const int n = X.size();        
        double ans = 0.0;
        unordered_map<int,int> um;
        for (const int& x : X)
            ++um[x];       
        
        for (const pair<int,int>& p : um) {
            const int count = p.second;
            double logProbability = log2(static_cast<double>(count)/n);
            
            ans -= (static_cast<double>(count)/n) * log2(static_cast<double>(count)/n);
        }
        
        return ans;  
    }
};