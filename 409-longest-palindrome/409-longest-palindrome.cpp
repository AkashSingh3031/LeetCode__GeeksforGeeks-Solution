class Solution {
public:
    int longestPalindrome(string s) {
        int odds = 0;
        for (char c='A'; c<='z'; c++)
            odds += count(s.begin(), s.end(), c) & 1;
        return s.size() - odds + (odds > 0);
    }
};