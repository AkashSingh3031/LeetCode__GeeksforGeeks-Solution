class Solution {

public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp = 0, dp1 = 0, dp2 = 0; // corresponding to current dp, previous 1 step dp, previous 2 step dp
        for (int i = 2; i <= n; i++) {
            int jumpOneStep = dp1 + cost[i - 1];  // Minimum cost if we jump 1 step from floor (i-1)_th to i_th floor
            int jumpTwoStep = dp2 + cost[i - 2];  // Minimum cost if we jump 2 steps from floor (i-2)_th to i_th floor
            dp = min(jumpOneStep, jumpTwoStep);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};
        

