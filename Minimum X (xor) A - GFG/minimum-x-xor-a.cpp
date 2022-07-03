// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int bits=0;
        while(b>0){
            bits++;
            int l=__lg(b);
            b-=(1<<l);
        }
        int temp=a,abits=0;
        while(temp>0){
            abits++;
            int l=__lg(temp);
            temp-=(1<<l);
        }
        int ans=0;
        vector<int> took;
        while(a>0 && bits--){
            int l=__lg(a);
            ans+=(1<<l);
            a-=(1<<l);
            took.push_back(l);
        }
        if (bits<=0) return ans;
        sort(took.begin(),took.end());
        int dzire=0,i=0;
        while(bits--){
            while(i<took.size() && took[i]==dzire){
                i++;
                dzire++;
            }
            ans+=(1<<dzire);
            dzire++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends