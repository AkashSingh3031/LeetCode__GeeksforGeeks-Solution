class Solution {
public:
    /*
        2-path matrix dp
        
		k = i1 + i2
        define f[k][i1][i2] as all possible paths from (1, 1) to (i1, k - i1), (i2, k - i2)
        property: maximum number of cherries picked up
        
        k = [2, m + n]
    */
    static const int INF = 0x3f3f3f3f;
    
    int cherryPickup(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        
        int f[m + n + 1][m + 1][n + 1];
        memset(f, -0x3f, sizeof f);
        if (grid[0][0] != -1) f[2][1][1] = 0;
        f[2][1][1] = grid[0][0] == 1;
        
        for (int k = 3; k <= m + n; k++) {
            for (int i1 = 1; i1 <= m; i1++) {
                for (int i2 = 1; i2 <= m; i2++) {
                    int j1 = k - i1, j2 = k - i2;
                    if (j1 > 0 && j1 <= n && j2 > 0 && j2 <= n) {
                        int& v = f[k][i1][i2];
                        
                        if (grid[i1 - 1][j1 - 1] == -1 || grid[i2 - 1][j2 - 1] == -1) continue;
                        
                        int earns = grid[i1 - 1][j1 - 1];
                        if (i1 != i2 && j1 != j2) {
                            earns += grid[i2 - 1][j2 - 1];
                        }
                        
                        v = max(v, f[k - 1][i1][i2]);
                        v = max(v, f[k - 1][i1 - 1][i2]);
                        v = max(v, f[k - 1][i1][i2 - 1]);
                        v = max(v, f[k - 1][i1 - 1][i2 - 1]);
                        
                        v += earns;
                    }
                }
            }
        }
        
        /*
            why not "if f[m + n][m][m] == -INF return 0"?
            
            ex>
                [[1,1,-1],
                 [1,-1,1],
                 [-1,1,1]]
            
            k = 5
            f[1][1]=-1044266559 f[1][2]=-1044266559 f[1][3]=-1044266559 
            f[2][1]=-1044266559 f[2][2]=-1044266558 f[2][3]=-1044266557 
            f[3][1]=-1044266559 f[3][2]=-1044266557 f[3][3]=-1044266558 
            
            for f[2][2], path1 to (2, 3), path2 to (2, 3), note that grid[2][3] is not -1, it will not execute continue clause on line 36
            we use -inf to update -inf, -1044266559 to -1044266558
        */
        return max(0, f[m + n][m][m]);
    }
};