// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:

    void dfs(vector <string> &v, string &S, int i, int n, string &s){
        if(i+1>= n){
            s += S[i];
            v.push_back(s);
            s.pop_back();
            return;
        }
        s += S[i];
        s += " ";
        dfs(v, S, i+1, n, s);
        s.pop_back();
        dfs(v, S, i+1, n, s);
        s.pop_back();
    }
    
    vector<string> permutation(string S){
        string s = "";
        int n = S.size();
        vector <string> v;
        dfs(v, S, 0, n, s);
        return v;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends