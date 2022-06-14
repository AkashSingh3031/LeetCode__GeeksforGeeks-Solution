// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
            //complete the function here
            int low = 0;
            int high = n * 5;
            int ans = high;
            while(low <= high){
                int mid = low + (high - low)/2;
                int x = 5;
                int total = 0;
                while(x <= mid){
                    total += mid/x;
                    x *= 5;
                }

                if(total < n){
                    low = mid + 1;
                }
                else if(total > n){
                    high = mid - 1;
                    ans = min(ans, mid);
                }
                else{
                    ans = mid;
                    break;
                }
            }
            ans -= ans % 5;
            return ans;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends