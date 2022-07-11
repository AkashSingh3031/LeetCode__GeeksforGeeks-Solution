// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int shortestUnSub(string S, string T) {
        // code here
        int *dp = new int[T.length() + 1];
        for(int i = 0; i <= T.length(); i++) {
            dp[i] = 1e9;
        }
        for(int i = (S.length() - 1); i >= 0; i--) {
            int *temp = new int[T.length() + 1];
            temp[T.length()] = 1;
            for(int j = (T.length() - 1); j >= 0; j--) {
                int notTake = 0 + dp[j];
                int index;
                for(index = j; index < T.length(); index++) {
                    if(T[index] == S[i]) {
                     break;
                    }
                }
                if(index == T.length()) {
                    temp[j] = 1;
                }
                else {
                    int take = 1 + dp[index + 1];
                    temp[j] = min(take, notTake);
                }
            }
            delete dp;
            dp = temp;
        }
        
        int res = dp[0];
        if(res >= 1e9) {
            return -1;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends