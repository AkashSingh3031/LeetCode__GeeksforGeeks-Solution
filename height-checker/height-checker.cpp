class Solution {
public:
    int heightChecker(vector<int>& h, int res = 0) {
        vector<int> s = h;
        sort(begin(s), end(s));
        for (auto i = 0; i < h.size(); ++i) 
            res += h[i] != s[i];
        return res;
    }
};