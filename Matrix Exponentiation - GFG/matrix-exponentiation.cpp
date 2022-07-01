// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;
    ll mul(ll a, ll b){
        return ((a % MOD) * (b % MOD)) % MOD;
    }
    ll add(ll a, ll b){
        return ((a % MOD) + (b % MOD)) % MOD;
    }
    pair<ll, ll> fib(ll n){
        if(n == 0){
            return {0, 1};
        }
        const pair<ll, ll> p = fib(n >> 1);
        ll c = mul(p.first, ((mul(2, p.second) - p.first) + MOD) % MOD);
        ll d = add(mul(p.first, p.first), mul(p.second, p.second));
        if(n & 1){
            return {d, add(c, d)};
        }
        return {c, d};
    }
public:
    int FindNthTerm(long long int n) {
        return fib(n).second;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends