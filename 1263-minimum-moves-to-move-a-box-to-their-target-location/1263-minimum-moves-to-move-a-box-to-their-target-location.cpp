class Solution {
public:
    int n , m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
	
    bool inside(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    bool canWalk(int srcX, int srcY, int destX, int destY, vector<vector<char>>&grid, vector<vector<int>>&visited)
    {
        if(srcX == destX && srcY == destY) return true;
        visited[srcX][srcY] = 1;
        for(int i = 0; i < 4; i++)
        {
            int x = srcX + dx[i];
            int y = srcY + dy[i];
            if(inside(x, y) && grid[x][y] != '#' && !visited[x][y])
            {
                if(canWalk(x, y, destX, destY, grid, visited))
                    return true;
            }
        }
        return false;
    }
    int minPushBox(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();
         int boxX, boxY, targetX, targetY, personX, personY; 
         for(int i = 0; i < n; i++)
         {
             for(int j = 0; j < m; j++)
             {
                 if(grid[i][j] == 'S')
                 {
                     personX = i;
                     personY = j;
                 }
                 else if(grid[i][j] == 'T')
                 {
                     targetX = i;
                     targetY = j;
                 }
                 else if(grid[i][j] == 'B')
                 {
                     boxX = i;
                     boxY = j;
                 }
             }
         }
		 
         queue<vector<int>>q;
         set<vector<int>> seen;
         q.push({boxX, boxY,personX, personY});
         int ans = 0;
		 
         while(!q.empty())
         {
             int sz = q.size();
             while(sz--)
             {
                auto p = q.front();
                q.pop();
                boxX = p[0]; boxY = p[1];
                personX = p[2]; personY = p[3];
				
                if(boxX == targetX && boxY == targetY)
                    return ans;
					
                grid[boxX][boxY] = '#';
				
                for(int i = 0; i < 4; i++)
                {
                    int new_boxX = boxX + dx[i];
                    int new_boxY = boxY + dy[i];
                    int new_personX = boxX - dx[i];
                    int new_personY = boxY - dy[i];
                    vector<int>curPos({new_boxX,new_boxY,new_personX,new_personY});
                    vector<vector<int>> visited(n, vector<int>(m, 0));
                    if(inside(new_boxX, new_boxY) && grid[new_boxX][new_boxY]!='#'  && !seen.count(curPos) && canWalk(personX, personY, new_personX, new_personY, grid, visited))
                    {
                        seen.insert(curPos);
                        q.push(curPos);
                    }
                }
                grid[boxX][boxY] = '.';
              }
             ans++;
          }
        return -1;
    }
};