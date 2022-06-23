// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    long long mod=1e9+7;
	    long long dp[N+4][2];
	    dp[0][0]=1;
	    dp[0][1]=1;
	    // dp[i][0] no of ways such that i'th is a free space;
	    // dp[i][1] no of ways such that i'th is a building;
	    for(int i=1;i<N;++i){
	        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
	        dp[i][1]=dp[i-1][0];
	    }
	    long long ans=(dp[N-1][0]+dp[N-1][1])%mod;
	    ans= (ans*ans)%mod;
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends