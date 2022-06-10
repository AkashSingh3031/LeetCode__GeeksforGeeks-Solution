// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    double bs(double low, double high, double m[],int n)
    {
        double dif =1/(1e12);
        double mid = (low + high)/2;
        double net = 0;
        for(int i=0;i<n;i++)
            net+=1/(mid-m[i]);
        if((-dif) < net && net < dif)
            return mid;
        else if (net > 0)
            return bs(mid, high, m,n);
        else 
            return bs(low, mid, m,n);
    }
    void nullPoints(int n, double m[], double getAnswer[])
    {
        // Your code goes here   
        for(int i=0; i<n-1; i++)
            getAnswer[i] = bs(m[i], m[i+1], m,n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends