// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        // code here
        vector<int> adj[N  + 1];
        vector<int>dis(N  + 1,0);
        for(int i = 0 ; i < M ; i ++){
            auto it = mat[i];
            adj[it[0]].push_back(it[1]);
        }
        for(int i = 1 ; i <= N ; i ++){
            for(int j : adj[i]){
                dis[j]++;
            }
        }
        queue<int>q;
        int res = 0;
        for(int i =1 ; i<= N ; i ++)
        while(true){
                if(q.empty()){
                    int flag  = 1;
                    for(int i = 1 ; i <= N ; i ++){
                        if(dis[i] == 0){
                            flag = 0;
                            q.push(i);
                            dis[i] = -1;
                        }
                    }
                    if(flag == 1) 
                        return res;
                    res++;
                }
                int i = q.front();q.pop();
                for(int j : adj[i]){
                    dis[j]--;
                }
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends