// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        int n=str.size();
        for(int i=0;i<n;i++)
        mp1[str[i]]++;
        int i=0,j=0,ans=INT_MAX;
        while(j<n)
        {
            mp2[str[j]]++;
            if(mp1.size()==mp2.size())
            {
                while(mp1.size()==mp2.size())
                {
                    mp2[str[i]]--;
                    if(mp2[str[i]]==0)
                    mp2.erase(str[i]);
                    i++;
                }
                ans=min(ans,1+j-i+1);
            }
            j++;
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends