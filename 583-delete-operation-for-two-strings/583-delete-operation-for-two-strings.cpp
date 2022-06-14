class Solution {
public:
    int minDistance(string a, string b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i < m || j < n)
                    dp[i][j] = i < m && j < n && a[i] == b[j] ?
                        dp[i + 1][j + 1] : 1 + min((i < m ? dp[i + 1][j] : INT_MAX), (j < n ? dp[i][j + 1] : INT_MAX));
            }
        }
        return dp[0][0];
    }
};