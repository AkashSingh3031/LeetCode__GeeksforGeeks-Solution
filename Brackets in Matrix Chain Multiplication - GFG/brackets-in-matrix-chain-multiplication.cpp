// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    pair<string,int> fun(int p[], int i, int j, vector<vector<pair<string,int>>>& v)
   {
       if(i==j)
       {
           string st="";
           st+='A'+i-1;
           return {st,0};
       }
       if(v[i][j].second!=-1)
       return v[i][j];
       int m=1e9;
       string sr="";
       for(int k=i;k<=j-1;k++)
       {
           auto pr1=fun(p,i,k,v);
           auto pr2=fun(p,k+1,j,v);
           int x=pr1.second+pr2.second+p[i-1]*p[k]*p[j];
           string s="";
           s="("+pr1.first+pr2.first+")";
           if(m>x)
           {
               m=x;
               sr=s;
           }
       }
       v[i][j]={sr,m};
       return v[i][j];
   }
   string matrixChainOrder(int p[], int n){
       vector<vector<pair<string,int>>>v(n, vector<pair<string,int>>(n,{"",-1}));
       auto pr=fun(p,1,n-1,v);
       return pr.first;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends