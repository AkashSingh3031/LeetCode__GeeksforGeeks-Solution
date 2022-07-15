// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int minSwaps(int N,vector<int> A, vector<int> B){
        // code here
        int a = A[0], b = B[0], flagA = 0, flagB = 0;
       int countA, countB;
    
       int count1a = 0, count2a = 0;
    
       for(int i=0; i!=N; i++) {
           if(A[i] == a && B[i] == a)
               count1a++, count2a++;
           else if(A[i] != a && B[i] == a)
               count2a++;
           else if(A[i] == a && B[i] != a)
               count1a++;
           else {
               flagA = 1;
               break;
           }
       }
    
       int count1b = 0, count2b = 0;
    
       for(int i=0; i!=N; i++) {
           if(A[i] == b && B[i] == b)
               count1b++, count2b++;
           else if(A[i] != b && B[i] == b)
               count2b++;
           else if(A[i] == b && B[i] != b)
               count1b++;
           else {
               flagB = 1;
               break;
           }
       }
    
    //   cout << count1a  << " " << count2a << " "<< count1b <<" "<<count2b<<" "<< flagA << " " << flagB << endl;
    
       countA = (count1a > count2a) ? (N - count1a) : (N - count2a);
       countB = (count1b > count2b) ? (N - count1b) : (N - count2b);
    
    //   cout << countA << " " << countB << endl;
    
       if(flagA == 0 && flagB == 0) {
           countA = (countA < countB) ? countA : countB;
           return countA ;
       }
       else if (flagA == 1 && flagB == 0) {
           return countB;
       }
       else if(flagA == 0 && flagB == 1) {
           return countA;
       }
       else
           return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N),B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
            cin>>B[i];
        }
        Solution obj;
        cout<<obj.minSwaps(N, A, B)<<endl;
    }
}  // } Driver Code Ends