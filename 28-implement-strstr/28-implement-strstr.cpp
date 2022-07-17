class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) < haystack.size())
            return haystack.find(needle);
        else
            return -1;
    }
};