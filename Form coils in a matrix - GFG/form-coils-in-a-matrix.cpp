// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        
        // code here
        vector<vector<int>> temp;
       vector<vector<int>> v;
       int k=1;
       for(int i=0;i<4*n;++i)
       {
           vector<int> v1;
           for(int j=0;j<4*n;++j)
           {
              v1.push_back(k++);
           }
           v.push_back(v1);
       }
       int top=0,left=0;
       n=4*n;
       int bottom=n-1,right=n-1;
       vector<int> t1;
       vector<int> t2;
       k=0;
       while(left<=right)
       {
           for(int i=top;i<=bottom;++i)
           {
               if(k%2==0)
               t1.push_back(v[i][left]);
               else
               t2.push_back(v[i][left]);
           }
           left++;
           for(int i=bottom;i>=top;--i)
           {
               if(k%2==0)
               t2.push_back(v[i][right]);
               else
               t1.push_back(v[i][right]);
           }
           right--;
           for(int i=left;i<=right;++i)
           {
               if(k%2==0)
               t1.push_back(v[bottom][i]);
               else
               t2.push_back(v[bottom][i]);
           }
           bottom--;
           for(int i=right;i>=left;--i)
           {
               if(k%2==0)
               t2.push_back(v[top][i]);
               else
               t1.push_back(v[top][i]);
           }
           top++;
           k++;
       }
       reverse(t1.begin(),t1.end());
       reverse(t2.begin(),t2.end());
       temp.push_back(t2);
       temp.push_back(t1);
       return temp;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends