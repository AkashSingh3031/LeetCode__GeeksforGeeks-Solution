// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int>um;
        unordered_set<int>us;
        for(int i=0;i<n;i++)
            us.insert(arr[i]);
        int k=us.size();
        for(int i=0;i<n;i++){
            um[arr[i]]++;
            while(um.size()>=k&&j<=i){
                ans+=(n-i);
                 um[arr[j]]--;
                if(um[arr[j]]==0)
                  um.erase(arr[j]);
                j++;}
             }
        return ans;
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends