class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count=0;
        //Create map and count all words frequency
        map<string,int> m;
        for(auto w:words) {
            m[w]++;
        }
        
        //if single word like gg once done then not consider second time
        //ex. cd*gg*dc
        bool flag=false;
        for(auto x:words) {
            string w=x;
            reverse(w.begin(),w.end());
            //Encounter bc and cb then both freq -- by 1
            if(w!=x and m[x]>0 and m[w]>0) {
                m[x]--;
                m[w]--;
                count+=4;
            } //Encounter aa and aa 2 times like bc*aa aa*cb,-- by 2 times
            else if(w==x and m[x]>1) {
                m[x]-=2;
                count+=4;
            } //Consider once like, bc*gg*cb
            else if(w==x and !flag and m[x]>0) {
                m[x]--;
                count+=2;
                flag=true;
            }
        }
        return count;
    }
};