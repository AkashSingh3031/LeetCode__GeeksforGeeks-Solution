// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        if (A.length() != B.length())
       {
           return -1;
       }
       int sum = 0 , sum1 = 0;
       int i = A.length() - 1 , j = B.length() - 1;
       int ct = 0;
       while (i >= 0 && j >= 0)
       {
           sum += A[i];
           sum1 += B[j];
           i--;
           j--;
       }
       if (sum1 != sum)
       {
           return -1;
       }
       i = A.length() - 1;
       j = B.length() - 1;
       
       while (i >= 0 && j >= 0)
       {
           if (A[i] == B[j])
           {
               i--;
               j--;
           }
           else
           {
               ct++;
               i--;
           }
       }
       return ct;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends