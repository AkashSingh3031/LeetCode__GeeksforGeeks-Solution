//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int  countPrime(int n)
    {
        int count = 0;
        
        vector<bool> isNotPrime(n,0);
        
        for(int i = 2; i*i <= n; i++)
        {
            if(isNotPrime[i]) continue;
            for(int j = i*i; j <= n; j+=i)
            {
                isNotPrime[j] = true;
            }
        }
        
        for(int i = 2; i <= n; i++)
        {
            if(!isNotPrime[i]) count++;
        }
        return count;
    }
    
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> ans;
        
            for(int i = 0; i < q; i++)
            {
                int n = query[i];
                int root = (int)sqrt(n);
                ans.push_back(countPrime(root));
            }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends