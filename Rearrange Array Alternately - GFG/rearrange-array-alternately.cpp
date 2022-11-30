//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	long long max_index=n-1;

        long long min_index=0;
    
        long long max=arr[n-1]+1;
    
        for(long long i=0;i<n;i++){
    
            if(i%2==0){
    
                arr[i]=(arr[max_index]%max)*max+arr[i];
    
                max_index--;
    
            }
    
            else{
    
                arr[i]=(arr[min_index]%max)*max+arr[i];
    
                min_index++;
    
            }
    
        }
    
        for(long long i=0;i<n;i++ ){
    
            arr[i]/=max;
    
        }
    	 
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends