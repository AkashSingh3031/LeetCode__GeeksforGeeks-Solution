// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        int ans=0;
        vector<pair<int,int>> vp;
        
        for(int i=0; i<N; i++){
            vp.push_back({B[i] , A[i]});
        }
        
        sort(vp.begin(), vp.end());
        
        for(int i=vp.size()-1; i>=0; i--){
            
            if(T<=0)
             break;
             
            int ct=vp[i].second;
            int gold=vp[i].first;
            
            while(T>0 && ct){
                ans += gold;
                T--;
                ct--;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends