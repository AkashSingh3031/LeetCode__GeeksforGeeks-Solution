class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> dict(256, -1);
        int maxlen = 0, start = 0, n = s.size();
        
        for(int i=0; i<n; i++)
        {
            if(dict[s[i]] != -1)
                start = max(start, dict[s[i]]+1);
            dict[s[i]] = i;
            maxlen = max(maxlen, i-start+1);
        }
        return maxlen;
    }
};