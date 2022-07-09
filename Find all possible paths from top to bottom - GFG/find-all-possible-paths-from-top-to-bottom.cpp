// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> answer;
    void helper(int i,int j, vector<vector<int>> grid, vector<int> v,int n, int m){
    
    //we've reached the final element
        if(i==n-1 && j==m-1){         
            v.push_back(grid[i][j]);
            answer.push_back(v);
            return;
        }
    //Backtracking
        if(i>n-1||j>m-1) return; 
        
    // Normal recursive function 
        v.push_back(grid[i][j]);   // Appending the elements
        helper(i+1,j,grid,v,n,m);  //Moving right
        helper(i,j+1,grid,v,n,m);  // Moving Down
        return;
    }
    
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        if(grid.size()==0) return{{}};
        vector<int> v;
        helper(0,0,grid,v,n,m);
        return answer;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends