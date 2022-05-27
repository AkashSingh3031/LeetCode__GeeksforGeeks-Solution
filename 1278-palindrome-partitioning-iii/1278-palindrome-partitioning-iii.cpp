class Solution {
public:
    int palindromePartition(string s, int K) {
        vector<vector<int>> dp(101,vector<int>(101,100));
        vector<vector<int>> pd(101,vector<int>(101,101));
		
        for(int i = 0; i < s.size(); i++) {
            pd[i][i] = 0;
        }
        for(int i = 0; i < s.size()-1;i++) {
            if(s[i] == s[i+1])
                pd[i][i+1] = 0;
            else
                pd[i][i+1] = 1;
        }
        
        for(int k = 2; k < s.size(); k++) {
            for(int i = 0; i < s.size(); i++) {
                if(i+k>=s.size())
                    continue;
                int j = i + k;
                pd[i][j] = pd[i+1][j-1];
                if(s[i]!=s[j])
                    pd[i][j] = pd[i+1][j-1] + 1;
            }
        }
        
        for(int j = 0; j < s.size(); j++) {
            dp[j][1] = pd[0][j];
        }
        
        for(int k = 2;  k <= K; k++ ) {
            for(int j = 1; j < s.size(); j++) {
                dp[j][k] = j+1;
                for(int l = 0; l <= j; l++) {
                    dp[j][k] = min(dp[l][k-1] + pd[l+1][j], dp[j][k]);
                }
            }
        }
        return dp[s.size()-1][K];
    }
};