#define mod 1000000007
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        //for one character ans is 1 "a" = "a"
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        /*
        For 2 characters :
        1. if they are same : "aa" ans : "a", "aa"
        2. if they are not same : "ab" ans : "a", "b"
        */
        for(int i=0;i<n-1;i++){
            dp[i][i+1] = 2;
        }
        //Filling for 3,4,...,n characters in chunks
        for(int m=2;m<n;m++){
            for(int i=0;i<n-m;i++){
                int j = i+m;
                if(s[i] != s[j]){
                    /*
                    for query : "abc" first and last "a" and "c" are not same
                    we check for ans from "ab" and "bc"
                                         i->j-1   i+1->j
                                         "a","b"  "b","c"
                    and delete the common from both ranges ie "b" which is i+1->j-1
                    */
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }
                else{
                    /*
                    Since the edge characters are same :
                            a b a
                            i   j
                    the total number of palindromic subsequence obtained from in bwtween characters can
                    individually be bounded between characters at i and j
                    As in this case palindromic sequence by in between character : "b" is 1 ie "b"
                    which can be bounded like : "aba"
                    so in total its prev "b" : 1*2 ie 2;
                    */
                    dp[i][j] = dp[i+1][j-1] * 2;
                    /*
                    we track the characters which are similar to boundary characters i and j
                    */
                    int low = i+1, high = j-1;
                    while(low <= high && s[low]!=s[j]){
                        low++;
                    }
                    while(high >= low && s[high]!=s[i]){
                        high--;
                    }
                    if(low == high){
                        /*
                        There is one character which is similar. let query be : "abaca"
                                a  b  a  c  a
                                i    l/h    j
                        For this we add 1 for it to make a palindromic subsequence with either of
                        edge characters i.e with i or j ie "aa"
                        */
                        dp[i][j] += 1;
                    }
                    else if(low < high){
                        /*
                        There are more than one characters in bwtween;
                                a   b   a   a   a   c   a
                                i       l       h       j
                        We have to deduct the number of palindrome in between low and high
                        as its already been calculated earlier @ dp[i][j]*2;
                        */
                        dp[i][j] -= dp[low+1][high-1];
                    }
                    else{
                        /*
                        There are no characters in between which are identical
                                a   b   c   a
                                i   h   l   j
                        we need to add 2 for the edge characters they can contribute in answers like
                        "a" and "aa"
                        */
                        dp[i][j] += 2;
                    }
                }
                if(dp[i][j] < 0){
                    //Avoiding mod of negatives
                    dp[i][j] = (dp[i][j] + mod)%mod;
                }
                else{
                    dp[i][j] = dp[i][j]%mod;
                }
            }
        }
        return dp[0][n-1];
    }
};