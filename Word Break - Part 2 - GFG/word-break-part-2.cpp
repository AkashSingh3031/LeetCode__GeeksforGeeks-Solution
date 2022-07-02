// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    map<string,int>freq;
    void solve(string s,vector<string>&ans,int n,string temp){
        if(s.length()==0){
            temp.pop_back();//to remove the extra space at the end
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<s.length();j++){
            string chk=s.substr(0,j+1);
            if(freq[chk]){
                chk+=' ';
                solve(s.substr(j+1),ans,n,temp+chk);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        for(auto it:dict)
            freq[it]++;
        vector<string>ans;
        solve(s,ans,n,"");
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends