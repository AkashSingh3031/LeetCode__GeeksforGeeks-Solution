// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    // Your code goes here
	    int lps[s.length()] = {0};
	    int i = 1;
	    int len = 0;
	    int n = s.length();
	    int res  = 0;
	    while(i < s.length() ){
	        int k = i;
            while(s[i] == s[len]){
                lps[i] = len + 1;
                res = max(res,lps[i]);
                len++;i++;
                }
	         if(s[i] != s[len]){
	            if(len == 0){
	                lps[i] = 0;i++;
	            }else{
	                len = lps[len - 1];
	            }
	        }
	        
	    }
	    if(res == 0) return 0;
	    string t = s.substr(0,n - res);
	    string ans = "";
	    int k = n/t.length();
	    while(k--){
	       ans += t;
	    }
	    if(ans == s) return 1;
	    return 0;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends