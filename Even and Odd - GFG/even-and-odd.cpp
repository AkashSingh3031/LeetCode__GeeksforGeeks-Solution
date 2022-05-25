// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void reArrange(int arr[], int N) {
        // code here
        stack<int> evenStack;
        stack<int> oddStack;
        
        for (int i = 0; i < N; i++)
        {
            if (arr[i] % 2 == 0)
            {
                evenStack.push(arr[i]);
            }
            else
            {
                oddStack.push(arr[i]);
            }
        }
        
        for (int j = 0; j < N; j++)
        {
            if (j % 2 == 0)
            {
                arr[j] = evenStack.top();
                evenStack.pop();
            }
            else
            {
                arr[j] = oddStack.top();
                oddStack.pop();
            }
        }
    }
};

// { Driver Code Starts.

int check(int arr[], int n)
{
    int flag = 1;
    int c=0, d=0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            if(arr[i]%2)
            {
                flag = 0;
                break;
            }
            else
                c++;
        }
        else
        {
            if(arr[i]%2==0)
            {
                flag = 0;
                break;
            }
            else
                d++;
        }
    }
    if(c!=d)
        flag = 0;
        
    return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        ob.reArrange(arr,N);
        
        cout<<check(arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends