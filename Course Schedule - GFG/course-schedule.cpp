// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        //creating indeg,ans,g(adjacency list for n numbers)
       vector<int>ans;
       vector<int>indeg(n,0);
       vector<int>g[n];
       queue<int>q;
       for(int i=0;i<prerequisites.size();i++){
           int u=prerequisites[i][0];
           int v=prerequisites[i][1];
           g[v].push_back(u);
           indeg[u]++;
       }
       //calculating indeg and then pushing it into q whose indeg is 0
       for(int i=0;i<n;i++){
           if(indeg[i]==0){
               //indeg[i]==0 then push that into queue
               q.push(i);
           }
       }
       //start wrking on queue
       while(!q.empty()){
           //popping the front element
           int f=q.front();
           q.pop();
           //pushing the front element into ans array
           ans.push_back(f);
           //traversing the adjancency list of front node f
           
           for(auto nbr:g[f]){
               //if any of neighbour have indeg ==0 then push that into queue
               indeg[nbr]--;
               if(indeg[nbr]==0){
                   q.push(nbr);
               }
           }
       }
       //after coming out from the loop check the size of ans size
       //if it is equal to n then it means graph has no cycle
       //simply return that ans arr
       //but if size is not equal to n then it means cycle is present
       //then simply return empty arr( {} )
       if(ans.size()==n){
           return ans;
       }else{
           return {};
       }
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends