class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int i = 1, j = n; i <= j; )
            res.push_back(k > 1 ? (k-- % 2 ? i++ : j--) : i++);
        return res;
    }
};