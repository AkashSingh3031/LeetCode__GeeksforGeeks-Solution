class Solution {
public:
    int kConcatenationMaxSum(vector<int>& a, int k) {
        int m_sum = 0, sz = a.size();
        for (auto i = 0, sum = 0; i < min(2, k) * sz; ++i) {
            sum = max(sum + a[i % sz], a[i % sz]);
            m_sum = max(m_sum, sum);
        }
        return ((long long)m_sum + 
            max(0ll, accumulate(begin(a), end(a), 0ll) * max(0, k - 2))) % 1000000007;
    }
};