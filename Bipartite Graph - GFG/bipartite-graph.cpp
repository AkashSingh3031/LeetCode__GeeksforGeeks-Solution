// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> Col(V , -1);
	    for(int i=0; i<  V; i++){
	        if(Col[i] == -1){
	            if(!dfs(i , adj , Col , 1)) return  0;
	        }
	    }
	    return 1;
	}
	bool dfs(int node , vector<int> adj[], vector<int> &vis , int col){
	    if(vis[node] != -1 ){
	        if(vis[node] == col) return 1;
	        else return 0;
	    }
	    vis[node] = col;
	    for(int it : adj[node]){
	        if(! dfs(it , adj , vis ,  col ^ 1 )) return 0;
	    }
	    return 1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends