// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(long H[], long A[], long N, long L, long M, long mid){
        long long totalSpeed=0;
        for(long i=0;i<N;i++){
            if(H[i]+A[i]*mid>=L)
                totalSpeed+=H[i]+A[i]*mid;
        }
        return totalSpeed>=M;
    }
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        // code here
        long start=1,end=M,ans=-1;
        while(start<=end){
            long mid=start+(end-start)/2;
            
            if(check(H,A,N,L,M,mid)){
                ans=mid;
                end=mid-1;
            }
            else 
                start=mid+1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends