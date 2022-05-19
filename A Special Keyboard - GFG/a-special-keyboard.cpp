// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        // code here
        unordered_map <int,int> u;
        for(int i=0; i<26; i++)
            u[S1[i]] = i;
        int s = u[S2[0]];
        for(int i=1; S2[i]!='\0'; i++)
            s += abs(u[S2[i]]-u[S2[i-1]]);
        return s;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends