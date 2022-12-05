/*
Example 1:
    Input: s = "aa", p = "a"
    Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
    Input: s = "aa", p = "a*"
    Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
    Input: s = "ab", p = ".*"
    Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i)
            if(p[i-1] == '*') dp[0][i] = dp[0][i-2];
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] != '*')
                    dp[i][j] = dp[i-1][j-1] && p[j-1] == s[i-1];
                else if(p[j-2] != '.' && p[j-2] != s[i-1])
                    dp[i][j] = dp[i][j-2];
                else
                    dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];     
            }
        }
        
        return dp[m][n];
    }
};